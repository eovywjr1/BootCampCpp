#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>

using namespace std;

const int DeckCount = 52;
int Deck[DeckCount];

void Initialize()
{
	const int MaxCardNumber = 13;

	for (int Index = 0; Index < DeckCount; ++Index)
	{
		Deck[Index] = Index % MaxCardNumber + 1;
	}
}

void Shuffle()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int Count = 0; Count < DeckCount; ++Count)
	{
		const int RandomIndex1 = rand() % DeckCount;
		const int RandomIndex2 = rand() % DeckCount;

		swap(Deck[RandomIndex1], Deck[RandomIndex2]);
	}
}

int DeckIndex = 0;
const int MaxScore = 21;

int Play()
{
	int Score = 0;
	int CurrentCard = 0;
	const int MaxCardNumber = 11;

	CurrentCard = Deck[DeckIndex] > MaxCardNumber ? MaxCardNumber : Deck[DeckIndex];
	++DeckIndex;

	Score += CurrentCard;
	cout << CurrentCard << ", ";

	CurrentCard = Deck[DeckIndex];
	++DeckIndex;

	Score += CurrentCard;
	cout << CurrentCard;

	return Score;
}

void Print()
{
	cout << "컴퓨터 : ";
	const int ComputerScore = Play();

	cout << '\n';
	cout << "===============";
	cout << '\n';

	cout << "플레이어 : ";
	const int PlayerScore = Play();

	cout << '\n';
	cout << "===============";
	cout << '\n';

	if (ComputerScore > MaxScore || ComputerScore < PlayerScore)
	{
		cout << "Win";
	}
	else if (ComputerScore == PlayerScore)
	{
		cout << "Draw";
	}
	else
	{
		cout << "Lose";
	}
}

int main()
{
	Initialize();
	Shuffle();
	Print();

	return 0;
}