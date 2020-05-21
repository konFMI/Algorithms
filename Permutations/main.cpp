#include<iostream>
#include"../Sorting/MergeSort.h"
#include"PermutationsWithRepetition.h"

int main()
{
    int array[] = {1,2,2};
    int count = sizeof(array) / sizeof(array[0]);
    MergeSort(array,0,count-1);
    Permute(array,0,count-1,count);
    
    return 0;
}