// MultiplesOf3And5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int sumOfMultiples = 0;

	for (size_t number = 3; number < 1000; number++)
	{
		if (number % 3 == 0 || number % 5 == 0)
		{
			sumOfMultiples += number;
		}
	}

	std::cout << sumOfMultiples;
}