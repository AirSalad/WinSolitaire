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

void CCards::drawCard(HDC hdcDest)
{
	HDC	hdcSrc = CreateCompatibleDC(NULL);

	HBITMAP hbmOld, hbmNew;
	BITMAP bm;

	//HBITMAP m_hSprite;
	//HBITMAP m_hMask;
	//BITMAP m_bitmapSprite;
	//BITMAP m_bitmapMask;

	//HINSTANCE hInstance = CGame::GetInstance().GetAppInstance();

	//hbmOld = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	hbmNew = CreateBitmap( bm.bmWidth, bm.bmHeight, bm.bmPlanes, bm.bmBitsPixel,
            NULL);

	//SelectObject(hdcSrc, hbmOld);

	//m_hMask = LoadBitmap(hInstance, MAKEINTRESOURCE(_iMaskResourceID));

	//BitBlt(hdcDest, m_x, m_y, m_width, m_height, hMemDC, 0, 0, SRCCOPY);

	BLENDFUNCTION BlendFunction = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

	AlphaBlend(
		//Destination
		hdcSrc,
		0,
		0,
		936,
		500,
		//Source
		hdcDest,
		m_x,
		m_y,
		m_width,
		m_height,
		BlendFunction
	);
		//HDC hdcDest,
		//int xoriginDest,
		//int yoriginDest,
		//int wDest,
		//int hDest,
		//HDC hdcSrc,
		//int xoriginSrc,
		//int yoriginSrc,
		//int wSrc,
		//int hSrc,
		//BLENDFUNCTION ftn
}