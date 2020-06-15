// SudoKu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>

const int size = 9;
const int sizeBig = 26;
void printWall(int num, int size)
{
	const WORD colors[] =
	{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = num%12;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, colors[index]);

	
	FlushConsoleInputBuffer(hstdin);

	// Keep users happy
	std::cout<<'\n' << std::setfill('*') << std::setw(size)<<'\n';
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	
}
void prinSideWall(int num)
{
	const WORD colors[] =
	{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = num % 12;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, colors[index]);


	FlushConsoleInputBuffer(hstdin);

	// Keep users happy
	std::cout << "*";
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);

}
void sudoKu(std::vector<std::vector<int>> &sudoku)
{
	
	



	for (size_t p = 0; p <= 6; p+=3)
	{
		for (size_t k = 0; k <= 6; k += 3)
		{
		printWall(k+1,size);
			for (size_t i = 0+p; i < 3+p; i++)
			{
				prinSideWall(k + 1);
				for (size_t j = 0 + k; j < 3 + k; j++)
				{
					std::cout << sudoku[i][j] << " ";
				}
				prinSideWall(k + 1);
				std::cout << std::endl;
			}
			printWall(k+1,size);
		}
	}
}
void read(std::vector<std::vector<int>> &sudoku)
{
	int digit = 0;

	for (size_t i = 0; i < 9; i++)
	{
		std::vector<int> row;
		for (size_t j = 0; j < 9; j++)
		{
			std::cin >> digit;
			row.push_back(digit);
		}
		sudoku.push_back(row);
	}
}
void print(std::vector<std::vector<int>> &sudoku)
{
	printWall(1, sizeBig);

	for (size_t i = 0; i < sudoku.size(); i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (j% 3 == 0)
			{
				prinSideWall(1);
				std::cout << " ";
			}
			std::cout << sudoku[i][j] << " ";
		}
		if ((i+1)%3 == 0)
		{
			prinSideWall(1);
			printWall(1, sizeBig);

		}
		else {
			prinSideWall(1);
			std::cout << "\n";
		}
	}
}
int main()
{
    std::vector<std::vector<int>> sudoku;

	read(sudoku);
	std::cout << std::endl;
	//sudoKu(sudoku);
	print(sudoku);
}

