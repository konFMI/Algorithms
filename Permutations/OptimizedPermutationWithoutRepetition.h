#include<iostream>
void Permute(int index, int* set, const     int size)
{
    if (index == size)
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout<<set[i]<<" ";
        }
        std::cout<<std::endl;
        return;
    }

    Permute(index + 1,set,size);
    
    for (size_t i = index+1; i < size; i++)
    {
        std::swap(set[index],set[i]);
        Permute(index+1,set,size);
        std::swap(set[index],set[i]);
    }
    
}
