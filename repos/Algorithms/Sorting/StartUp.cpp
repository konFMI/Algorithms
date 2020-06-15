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
void printElements(std::vector<Element<int,int>> collection)
{
    for (auto element : collection)
    {
        std::cout << element.value << " ";
    }
    std::cout << std::endl;

    return;
}
void init(std::vector<int>& collection,const size_t size)
{
    for (size_t i = size; i > 0; i--)
    {
        collection.push_back(i);
    }
}

void initWithElements(std::vector<Element<int,int>>& collection, const size_t size)
{
    for (int i = size; i > 0; i--)
    {
        collection.push_back(Element<int, int>{i, i});
    }
}

int main()
{
    Sort<int,int> sort;
    const size_t size = 10;
    std::vector<int> collection;
    std::vector<Element<int, int>> elements;

    //init(collection, size);
    initWithElements(elements,size);

    //print(collection);
    printElements(elements);

    sort.Shake(elements);
    
    //print(collection);
    printElements(elements);

}

