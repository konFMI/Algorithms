#include<iostream>

void Permute(int set[],int start, int end,int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout<<set[i]<<" ";
    }
    std::cout<<std::endl;

    for (int left = end - 1; left >= start; left--)
    {
        for(int right = left + 1; right <= end; right++)
        {
            if (set[left] != set[right])
            {
                std::swap(set[left],set[right]);
                Permute(set,left+1,end,size);
            }
        }
        int firstElement = set[left];
        for(int i = left; i <= end - 1; i++)
        {
            set[i] = set[i+1];
        }
        set[end] = firstElement;
    }
    
}