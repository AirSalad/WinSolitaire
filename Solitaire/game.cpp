// Library Includes
// Local Includes
#include "Clock.h"
#include "Level.h"
#include "BackBuffer.h"
#include "utils.h"
#include "cards.h"
// This Include
#include "Game.h"
// Static Variables
CGame* CGame::s_pGame = 0;
// Static Function Prototypes
// Implementation
CGame::CGame(): m_pLevel(0), m_pClock(0), m_hApplicationInstance(0), m_hMainWindow(0), m_pBackBuffer(0)
{

}

CGame::~CGame()
{
	delete m_pLevel;
	m_pLevel = 0;
	delete m_pBackBuffer;
	m_pBackBuffer = 0;
	delete m_pClock;
	m_pClock = 0;
}

bool CGame::Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight)
{
	m_hApplicationInstance = _hInstance;
	m_hMainWindow = _hWnd;
	m_pClock = new CClock();
	VALIDATE(m_pClock ->Initialise());
	m_pClock->Process();
	m_pBackBuffer = new CBackBuffer();
	VALIDATE(m_pBackBuffer->Initialise(_hWnd, _iWidth, _iHeight));
	//m_pLevel = new CLevel();
	//VALIDATE(m_pLevel->Initialise(_iWidth, _iHeight));
	m_pCard = new CCards();
	//VALIDATE(m_pLevel->Initialise(_iWidth, _iHeight));
	//ShowCursor(false);
	//m_pCard->SetSuit(clubs);
	//m_pCard->GetSuit();
	//m_pCard->SetValue(5);
	/*testCard.FlipCard();
	testCard.FlipCard();
	testCard.setCardPos();*/

	//Do the shufflign and dealing for the cards

	

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			
			CCards* tempCard = new CCards;
			tempCard->SetSuit((m_eCardSuits)i);
			tempCard->SetValue(j);
			deck.push_back(*tempCard);
		}
	}

	//SHUFFLE
	random_shuffle(deck.begin(),deck.end());

	for (int i = 0; i< 7; i++)
	{
		vector<CCards> temp;
		//playingspace;
		for (int j = 0; j<1+i;j++)
		{
			temp.push_back(deck.back());
			deck.pop_back();
		}
		playingspace.push_back(temp);
		playingspace.back().back().FlipCard();
	}
	//return (true);
}

void CGame::Draw()
{
	//m_pBackBuffer->Clear();
	//m_pLevel->Draw();
	//m_pBackBuffer->Present();
	

	//Draw cards
	//Draw deck pile
	if(deck.size()>0)
	{
		m_pCard->drawCard(m_hMainWindow, false, 0,0,10,10);
		//m_pCard->drawCard(m_hMainWindow, false, 2,4,10,10);
	}
	else
	{
		//if(!vegasdrawsremaining)
		//m_pCard->drawCard(m_hMainWindow, false, 1,4,10,10);
		m_pCard->drawCard(m_hMainWindow, true, 2,4,10,10);
	}
	
	if(!heartpile.empty())
	{
		//m_pCard->drawCard(m_hMainWindow, false, 0,0,10,10);
	}
	else
	{
		m_pCard->drawCard(m_hMainWindow, true, 9,4, 256, 10);
	}

	if(!diamondpile.empty())
	{
		//m_pCard->drawCard(m_hMainWindow, false, 0,0,10,10);
	}
	else
	{
		m_pCard->drawCard(m_hMainWindow, true, 10,4, 338, 10);
	}

	if(!clubpile.empty())
	{
		//m_pCard->drawCard(m_hMainWindow, false, 0,0,10,10);
	}
	else
	{
		m_pCard->drawCard(m_hMainWindow, true, 11,4, 420, 10);
	}

	if(!spadepile.empty())
	{
		//m_pCard->drawCard(m_hMainWindow, false, 0,0,10,10);
	}
	else
	{
		m_pCard->drawCard(m_hMainWindow, true, 12,4, 502, 10);
	}

	//ITERATORS FOR THE PILES
	
	for (vector<vector<CCards>>::iterator iterVect = playingspace.begin(); iterVect !=playingspace.end(); iterVect++)
	{

		for (vector<CCards>::iterator iterCards = iterVect->begin(); iterCards !=iterVect->end(); iterCards++)
		{

			m_pCard->drawCard(m_hMainWindow, iterCards->IsFaceUp(), iterCards->GetValue()-1,iterCards->GetSuit(), 10+(82*distance(playingspace.begin(),iterVect)), 120+((distance(iterVect->begin(),iterCards))*20));
		}

	}

}

void
CGame::Process(float _fDeltaTick)
{
	m_pLevel->Process(_fDeltaTick);
}

void
CGame::ExecuteOneFrame()
{
	float fDT = m_pClock->GetDeltaTick();
	Process(fDT);
	Draw();
	m_pClock->Process();
	Sleep(1);
}

CGame&
CGame::GetInstance()
{
	if (s_pGame == 0)
	{
		s_pGame = new CGame();
	}
	return (*s_pGame);
}

void
CGame::GameOverWon()
{
	MessageBox(m_hMainWindow, L"Winner!", L"Game Over", MB_OK);
	PostQuitMessage(0);
}

void
CGame::GameOverLost()
{
	MessageBox(m_hMainWindow, L"Loser!", L"Game Over", MB_OK);
	PostQuitMessage(0);
}

void
CGame::DestroyInstance()
{
	delete s_pGame;
	s_pGame = 0;
}

CBackBuffer* CGame::GetBackBuffer()
{
	return (m_pBackBuffer);
}

CLevel* CGame::GetLevel()
{
	return (m_pLevel);
}

HINSTANCE CGame::GetAppInstance()
{
	return (m_hApplicationInstance);
}

HWND CGame::GetWindow()
{
	return (m_hMainWindow);
}