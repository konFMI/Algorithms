// SmartSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

const int length = 7;
void read( std::array<int, length> &numbers)
{
	for (size_t i = 0; i < length; i++)
	{
		int digit = 0;
		std::cin >> digit;
		numbers[i] = digit;
	}
}
void write(std::array<int, length>& numbers)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << numbers[i] << std::endl;
	}
}
int main()
{
	std::array<int,length> numbers;
	
	read(numbers);
	write(numbers);
	
}

