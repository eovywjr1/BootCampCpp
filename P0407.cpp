#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	int PocketSize = 0;
	cin >> PocketSize;

	vector<int> Pocket;
	Pocket.resize(PocketSize);

	for (int i = 0; i < PocketSize; i++)
	{
		Pocket[i] = i;
	}

	vector<int> SelectedIndexes;

	srand(time(nullptr));

	while (SelectedIndexes.size() < PocketSize)
	{
		const int RandomIndex = rand() % PocketSize;
		bool bIsEqualIndex = false;

		for (int SelectedIndex : SelectedIndexes)
		{
			if (SelectedIndex == RandomIndex)
			{
				bIsEqualIndex = true;
				break;
			}
		}

		if (bIsEqualIndex)
		{
			continue;
		}

		cout << Pocket[RandomIndex] << ' ';
		SelectedIndexes.push_back(RandomIndex);
	}

	return 0;
}
