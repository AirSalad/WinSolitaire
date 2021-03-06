#pragma once
#if !defined(__GAME_H__)
#define __GAME_H__
// Library Includes
#include <windows.h>
#include <algorithm>
#include <vector>
// Local Includes
#include "clock.h"

using namespace std;

// Types
// Constants
// Prototypes
class CLevel;
class CBackBuffer;
class CCards;

class CGame
{
// Member Functions
public:
	virtual ~CGame();
	virtual bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);
	virtual void Draw();
	virtual void Process(float _fDeltaTick);
	void ExecuteOneFrame();
	CBackBuffer* GetBackBuffer();
	CLevel* GetLevel();
	HINSTANCE GetAppInstance();
	HWND GetWindow();
	void GameOverWon();
	void GameOverLost();
	// Singleton Methods
	static CGame& GetInstance();
	static void DestroyInstance();
protected:
private:
	CGame();
	CGame(const CGame& _kr);
	CGame& operator= (const CGame& _kr);
	// Member Variables
public:
protected:
	CClock* m_pClock;
	CLevel* m_pLevel;
	CBackBuffer* m_pBackBuffer;
	CCards* m_pCard;
	//Application data
	HINSTANCE m_hApplicationInstance;
	HWND m_hMainWindow;
	// Singleton Instance
	static CGame* s_pGame;
private:
	vector<CCards> deck;
	vector<CCards> revealpile;
	vector<CCards> heartpile;
	vector<CCards> diamondpile;
	vector<CCards> spadepile;
	vector<CCards> clubpile;
	vector<vector<CCards>> playingspace;
	int cardDraw;
};
#endif // __GAME_H__