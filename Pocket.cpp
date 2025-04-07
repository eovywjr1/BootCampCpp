#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
	const int PocketSize = 52;
	int Pocket[PocketSize] = { 0, };

	for (int Index = 0; Index < PocketSize; ++Index)
	{
		Pocket[Index] = Index + 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int Index = 0; Index < PocketSize; ++Index)
	{
		const int RandomIndex1 = static_cast<int>(rand() % PocketSize);
		const int RandomIndex2 = static_cast<int>(rand() % PocketSize);

		swap(Pocket[RandomIndex1], Pocket[RandomIndex2]);
	}

	for (int Index = 0; Index < PocketSize; ++Index)
	{
		cout << Pocket[Index] << ' ';
	}

	return 0;
}
