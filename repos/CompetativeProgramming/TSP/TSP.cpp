// TSP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include <string>
int tsp(std::string places)
{
	int cities = 0,
		villages = 0,
		visited = 1;
	for (auto place : places)
	{
		if (place == 'V')
		{
			villages++;
		}
		else if (place == 'C')
		{
			cities++;
		}
	}
	auto abs = [](int a) {
		return a > 0 ? a : -a;
	};
	if (cities == 0 && villages == 0)
	{
		visited = 0;
	}
	else if (cities == villages)
	{
		visited += cities;
	}
	else if (cities != 0 && villages != 0)
	{
		visited += ((cities > villages)? villages : cities)*2;
	}

	return visited;
}
int main()
{
	std::string places = " ";

	std::getline(std::cin, places);

	std::cout <<tsp(places);

	return 0;
}


