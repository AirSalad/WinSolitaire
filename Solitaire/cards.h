#pragma once

#if !defined(__CARD_H__)
#define __CARD_H__
// Library Includes
// Local Includes
#include "entity.h"
#include "resource.h"
#include "utils.h"
#include "BackBuffer.h"
#include "Sprite.h"
#include "cards.h"
#include "Game.h"

using namespace std;
//#include "resource.h"

//#include "BackBuffer.h"
//#include "utils.h"
//// This include
//#include "Sprite.h"
//#include "entity.h"

enum m_eCardSuits
{
	hearts,
	diamonds,
	clubs,
	spades
};

//class CSprite;
class CCards// : public CEntity
{
public:
	//
	CCards();
	~CCards();
	//virtual ~CCards();
	//virtual bool Initialise();
	//virtual void Draw();
	//virtual void Process(float _fDeltaTick);
	//
	void SetValue(int);
	int GetValue();
	void SetSuit(m_eCardSuits);
	int GetSuit();
	void FlipCard();
	bool IsFaceUp();
	void setCardPos();
	void drawCard(HWND _hWND, bool bCardFaceUp, int iCardValue, int iCardType,  int x, int y);

private:
	//CCards(const CCards& _kr);
	//CCards& operator= (const CCards& _kr);

	//void setCardPos();
	//int m_x;
	//int m_y;
	//int m_height;//100
	//int m_width;//72
	int m_iCardValue;
	m_eCardSuits m_eChosenSuit;
	bool m_bFaceUp;
};

#endif // __CARD_H__