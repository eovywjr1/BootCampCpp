#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	int PocketSize = 0;
	cin >> PocketSize;

	vector<int> Pocket(PocketSize, 0);

	for (int i = 0; i < PocketSize; i++)
	{
		Pocket[i] = i;
	}

	vector<bool> SelectedIndexes(PocketSize, false);

	srand(time(nullptr));

	int SelectCount = 0;
	while (SelectCount < PocketSize)
	{
		const int RandomIndex = static_cast<int>(rand() % PocketSize);
		
		if (SelectedIndexes[RandomIndex])
		{
			continue;
		}
		
		cout << Pocket[RandomIndex] << ' ';

		++SelectCount;
		SelectedIndexes[RandomIndex] = true;
	}

	return 0;
}
