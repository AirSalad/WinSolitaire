#pragma once

enum m_eCardSuits
{
	hearts,
	diamonds,
	clubs,
	spades
};

class CCards
{
public:
	CCards(void);
	~CCards(void);
	void SetValue(int);
	int GetValue();
	void SetSuit(m_eCardSuits);
	int GetSuit();
	void FlipCard();

private:
	int m_iCardValue;
	m_eCardSuits m_eChosenSuit;
	bool m_bFaceUp;
};