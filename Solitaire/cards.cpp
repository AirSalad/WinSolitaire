// Library Includes
// Local Includes
#include "resource.h"
#include "utils.h"
#include "BackBuffer.h"
#include "Sprite.h"
#include "cards.h"
//#include "Game.h"
#include "game.h"

using namespace std;

CCards::CCards()
{
	//m_bFaceUp = 0;
	//m_eChosenSuit = hearts;
}

CCards::~CCards()
{

}

//bool CCards::Initialise()
//{
//	VALIDATE(CEntity::Initialise(IDB_BITMAP1, IDB_BRICKMASK));
//	return (true);
//}
//
//void CCards::Draw()
//{
//	CEntity::Draw();
//}
//
//void CCards::Process(float _fDeltaTick)
//{
//	CEntity::Process(_fDeltaTick);
//}

void CCards::SetValue(int pValue)
{
	m_iCardValue = pValue;
}

int CCards::GetValue()
{
	return m_iCardValue;
}

void CCards::SetSuit(m_eCardSuits pSuit)
{
	m_eChosenSuit = pSuit;
}

int CCards::GetSuit()
{
	return m_eChosenSuit;
}

void CCards::FlipCard()
{
	m_bFaceUp = !m_bFaceUp;
}

void CCards::setCardPos()
{
	m_x = (m_iCardValue-1)*72;
	m_y = m_eChosenSuit*100;
	m_width = 72;
	m_height = 100;
}

void CCards::drawCard(HWND _hWND, bool bCardFaceUp,  int iCardValue, int iCardType,  int xCard, int yCard)
{
	/////////////////
	/////////////
	HINSTANCE hInstance = CGame::GetInstance().GetAppInstance();
	HDC _hdc = GetDC(_hWND);
	
	HDC	hdcSrc = CreateCompatibleDC(NULL);

	HBITMAP hbmNew;
	//BITMAP bm;

	hbmNew = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP2));

	//hbmOld = CreateCompatibleBitmap(_hdc, 936, 500);

	

	//HBITMAP m_hOldObject = static_cast<HBITMAP>(SelectObject(hbmOld, hdcNew));

	HGDIOBJ holdObj = SelectObject(hdcSrc, hbmNew);

	/////////////////////
	//DRAW//
	if(!bCardFaceUp)
	{
		BitBlt(_hdc, xCard, yCard, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	}
	else
	{
		BitBlt(_hdc, xCard, yCard, 72, 100, hdcSrc, iCardValue*72, iCardType*100, SRCCOPY);
	}
	/////////////////////

	//HINSTANCE hInstance = CGame::GetInstance().Get.AppInstance();

	//hbmNew = CreateBitmap( bm.bmWidth, bm.bmHeight, bm.bmPlanes, bm.bmBitsPixel, NULL);

	//SelectObject(hdcSrc, hbmOld);

	//m_hMask = LoadBitmap(hInstance, MAKEINTRESOURCE(_iMaskResourceID));

	//Deck
	//BitBlt(_hdc, 10, 10, 72, 100, hdcSrc, 0, 0, SRCCOPY);

	//Reveal Pile
	//BitBlt(_hdc, 92, 10, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 107, 10, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 122, 10, 72, 100, hdcSrc, 0, 0, SRCCOPY);

	//7 Piles
	//BitBlt(_hdc, 10, 120, 72, 100, hdcSrc, 504, 200, SRCCOPY);
	//BitBlt(_hdc, 92, 120, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 174, 120, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 256, 120, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 338, 120, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 420, 120, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 502, 120, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	/*for (int i = 0; i< 7; i++)
	{
		//vector<CCards> temp;
		//playingspace[i];
		for (int j = 0; j<1+i;j++)
		{
			//BitBlt(_hdc, (i*72)+10, 120, 72, 100, hdcSrc, 576, 400, SRCCOPY);
			BitBlt(_hdc, 10+(i*72)+(i*10), 120, 72, 100, hdcSrc, 576, 400, SRCCOPY);
			//temp.push_back(deck.back());
			//deck.pop_back();
		}
		//playingspace[i].push_back(temp);
		//playingspace[i].back().back().FlipCard();
	}*/

	//Pile 7
	//BitBlt(_hdc, 502, 140, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	//BitBlt(_hdc, 502, 160, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	//BitBlt(_hdc, 502, 180, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	//BitBlt(_hdc, 502, 200, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	//BitBlt(_hdc, 502, 220, 72, 100, hdcSrc, 576, 400, SRCCOPY);
	//BitBlt(_hdc, 502, 240, 72, 100, hdcSrc, 0, 0, SRCCOPY);

	//Suits
	//BitBlt(_hdc, 256, 10, 72, 100, hdcSrc, 0, 0, SRCCOPY);
	//BitBlt(_hdc, 338, 10, 72, 100, hdcSrc, 0, 100, SRCCOPY);
	//BitBlt(_hdc, 420, 10, 72, 100, hdcSrc, 0, 200, SRCCOPY);
	//BitBlt(_hdc, 502, 10, 72, 100, hdcSrc, 0, 300, SRCCOPY);
	

	SelectObject(hdcSrc, holdObj);

	SelectObject(_hdc, GetStockObject(LTGRAY_BRUSH));

	//BLENDFUNCTION BlendFunction = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

	//AlphaBlend(
		//Destination
	//	hdcDest,
	//	0,
	//	0,
	//	72,
	//	100,
	//	//Source
	//	hdcSrc,
	//	m_x,
	//	m_y,
	//	m_width,
	//	m_height,
	//	BlendFunction
	//);

	ReleaseDC(_hWND, _hdc);

}