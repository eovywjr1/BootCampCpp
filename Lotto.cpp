#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

constexpr int LottoMaxNumber = 45;
int LottoArray[LottoMaxNumber] = { 0, };

void Initialize()
{
	for (int Index = 0; Index < LottoMaxNumber; ++Index)
	{
		LottoArray[Index] = Index + 1;
	}
}

void Shuffle()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int ShuffleCount = 0; ShuffleCount < LottoMaxNumber; ++ShuffleCount)
	{
		const int RandomIndex1 = rand() % LottoMaxNumber;
		const int RandomIndex2 = rand() % LottoMaxNumber;

		swap(LottoArray[RandomIndex1], LottoArray[RandomIndex2]);
	}
}

constexpr int LotteryCount = 6;
int PredictNumbers[LotteryCount] = { 0, };

void Predict()
{
	cout << "로또 예측 : ";
	
	for (int Count = 0; Count < LotteryCount; ++Count)
	{
		cin >> PredictNumbers[Count];
	}
}

int LotteriedNumbers[LotteryCount] = { 0, };

void Lottery()
{
	cout << "추첨 결과 : ";

	for (int Count = 0; Count < LotteryCount; ++Count)
	{
		LotteriedNumbers[Count] = LottoArray[Count];
		cout << LotteriedNumbers[Count] << ' ';
	}
}

void Result()
{
	sort(&PredictNumbers[0], &PredictNumbers[LotteryCount - 1]);
	sort(&LotteriedNumbers[0], &LotteriedNumbers[LotteryCount - 1]);

	bool bIsFirstAward = true;

	for (int Index = 0; Index < LotteryCount; ++Index)
	{
		if (PredictNumbers[Index] != LotteriedNumbers[Index])
		{
			bIsFirstAward = false;
			break;
		}
	}

	cout << '\n';
	if (bIsFirstAward)
	{
		cout << "1등";
	}
	else 
	{
		cout << "실패";
	}
}

int main()
{
	Initialize();
	Shuffle();
	Predict();
	Lottery();
	Result();
}