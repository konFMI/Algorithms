// ArraysSpiral.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100

int matrix[MAX_HEIGHT][MAX_WIDTH];

void FillMatrix(int size)
{
	int topValue = size * size,
		value = 1;
	int i = 0,
		j = 0,
		left = 0,
		right = size - 1,
		up = 0,
		down = size - 1,
		incrementI = 0,
		incrementJ = 1;
	while (true)
	{
		while (j <= right)
		{
			matrix[i][j] = value;
			value++;
			j++;
		}
		right--;
		j--;
		i++;
		while (i <= down)
		{
			matrix[i][j] = value;
			value++;
			i++;
		}
		down--;
		i--;
		j--;
		while (j >= left)
		{
			matrix[i][j] = value;
			value++;
			j--;
		}
		left++;
		j++;
		i--;
		while (i > up)
		{
			matrix[i][j] = value;
			value++;
			i--;
		}
		up++;
		i++;
		j++;
		if (value > topValue)
		{
			break;
		}
	}
}
int CountDigits(int n)
{
	int count = 0;
	n = n > 0 ? n : -n;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return count;
}
void PrintMatrix(int size)
{
	int width = CountDigits(size * size) + 1;
	if (size > 33)
	{
		std::cout << "The output won't be pretty. Just a warning.\n";
	}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				std::cout << std::setw(width) << matrix[i][j];
			}
			std::cout << std::endl << std::endl;
		}
	
}

int main()
{
	int size = 0, numberOfTest = 0;

	std::cin >> numberOfTest;

	while (numberOfTest > 0)
	{
		std::cin >> size;
		FillMatrix(size);
		PrintMatrix(size);
		numberOfTest--;
	}
}

