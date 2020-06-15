// Grading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int left = 0, right = 0;
    std::cin >> left >> right;
    
    int intervalValue = 0;

    for (size_t number = left; number <= right; number++)
    {
        if (number % 2 == 0)
        {
            intervalValue -= number;
        }
        else
        {
            intervalValue += number;
        }
    }

    intervalValue = (intervalValue > 0) ? intervalValue : -intervalValue;
    
    int grade = intervalValue % 5 + 2;

    std::cout << grade;

    return 0;
}

// Вход
// На единствен ред на стандартния вход ще бъдат зададени две цели числа L и R, задаващи, съответно, началото и края на интервала за даден студент.
// Изход
// На единствен ред на стандартния изход извадете едно цяло число – оценката, която се очаква да получи съответният студент.
