// SumEvenFibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define UpperLimit 4000000

long SumEvenFibonacci(int upperLimit)
{
    long fib1 = 1,
        fib2 = 1,
        fib3 = 2,
        sum = 0;

    while (fib3 <= UpperLimit)
    {
        if (fib3 % 2 == 0)
        {
            sum += fib3;
        }

        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib2 + fib1;
    }

    return sum;
}

int main()
{
    long sum = SumEvenFibonacci(UpperLimit);

    std::cout << sum;
}

