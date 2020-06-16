// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "Sorting.h"

using namespace Algorithms::Sorting;
using TypeKey = long;
using TypeValue = long;
void print(std::vector<int> collection)
{
    for(auto element : collection)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return;
}
void printElements(std::vector<Element<TypeKey,TypeValue>> collection)
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

void initWithElements(std::vector<Element<TypeKey, TypeValue>>& collection, const size_t size)
{
    for (TypeKey i = size; i > 0; i--)
    {
        collection.push_back(Element<TypeKey, TypeValue>{i, i});
    }
}

int main()
{
    Sort<TypeKey, TypeValue> sort;
    const size_t size = 10000000;
    std::vector<int> collection;
    std::vector<Element<TypeKey, TypeValue>> elements;

    //init(collection, size);
    initWithElements(elements, size);

    //print(collection);
    //printElements(elements);

    sort.QuickSort(elements);
   
    //print(collection);
    printElements(elements);

}

