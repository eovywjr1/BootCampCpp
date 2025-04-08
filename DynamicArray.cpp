#include <iostream>

using namespace std;

void Resize(int** pArray, int CurrentSize, int NewSize)
{
	int* TempArray = *pArray;
	*pArray = new int[NewSize];

	for (int Index = 0; Index < CurrentSize; ++Index)
	{
		(*pArray)[Index] = TempArray[Index];
	}

	delete[] TempArray;
	TempArray = nullptr;
}

int main()
{
	int* DynamicArray = new int[10];

	for (int Index = 0; Index < 10; ++Index)
	{
		DynamicArray[Index] = (Index + 1) * 3;
	}

	Resize(&DynamicArray, 10, 20);

	for (int Index = 10; Index < 20; ++Index)
	{
		DynamicArray[Index] = (Index + 1) * 4;
	}

	for (int Index = 0; Index < 20; ++Index)
	{
		cout << DynamicArray[Index] << ' ';
	}

	delete[] DynamicArray;
	DynamicArray = nullptr;

	return 0;
}