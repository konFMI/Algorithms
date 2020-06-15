// DigitHoles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
long digitHoles(long long number)
{
	if (number == 0)
	{
		return 1;
	}

	int digit = 0,
		countHoles = 0;

	auto hasHole = [](int d) {
		bool has = (d == 4 || d == 6 || d == 9 || d == 0);
		return has;
	};
	
	while (number > 0)
	{
		digit = number % 10;
		number /= 10;
		if (hasHole(digit))
		{
			countHoles++;
		}
		else if (digit == 8)
		{
			countHoles += 2;
		}
	}

	return countHoles;
}
int main()
{
	long long number = 0;
	std::cin >> number;
	std::cout << digitHoles(number);
	return 0;
}
