#include "Cards.h"
#include<string>

CCards::CCards(void)
{
	m_bFaceUp = 0;
	m_eChosenSuit = hearts;
}

CCards::~CCards(void)
{
}

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