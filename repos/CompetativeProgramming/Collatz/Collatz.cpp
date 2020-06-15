// Collatz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct compare
{
	long key;
	compare(long const& k) : key(k)
	{}

	bool operator()(long const& k)
	{
		return (k == key);
	}
};

long collatz(long seed)
{
	std::vector<long> sequence;
	sequence.push_back(seed);

	while (true)
	{
		if (seed % 2 == 0)
		{
			seed /= 2;
		}
		else
		{
			seed *= 3;
			seed++;
		}

		if (std::any_of(sequence.begin(), sequence.end(), compare(seed)))
		{
			return seed;
		}

		sequence.push_back(seed);
	}

	return seed;
}

int main()
{
	long seed = 0;
	std::cin >> seed;
	std::cout << collatz(seed);

	return 0;
}