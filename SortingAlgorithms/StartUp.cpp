// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sorting.h"

using namespace Algorithms::Sorting;
void print(std::vector<int> collection)
{
    for(auto element : collection)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return;
}

int main()
{
    std::cout << "Hello World!\n";

    Sort sort;
    const size_t size = 10;
    std::vector<int> collection;
    for (size_t i = size; i > 0; i--)
    {
        collection.push_back(i);
    }
    int a = 2, b = 3;
    std::cout << a << std::endl << b << std::endl;

    sort.Swap(a, b);
    std::cout << a << std::endl << b << std::endl;

    collection[collection.size() - 1] = 0;
    print(collection);

    sort.Bubble(collection);

    print(collection);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
