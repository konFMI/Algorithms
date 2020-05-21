#include<iostream>
#include<vector>

using std::vector;

struct Solution
{
    void WithoutRepetition(int index)
    {
        if(index >= elements.size())
        {
            vectors.push_back(permutation);
        }

        for (size_t i = 0; i < elements.size(); i++)
        {
            if (!usedIndex[i])
            {
                usedIndex[i] = true;
                permutation[index] = elements[i];
                WithoutRepetition(index + 1);
                usedIndex[i] = false;
            }

        }
    
    }
    void WithRepetition(int index)
    {
        if(index >= elements.size())
        {
            vectors.push_back(permutation);
        }

        for (size_t i = 0; i < elements.size(); i++)
        {
            
            permutation[index] = elements[i];
            WithRepetition(index + 1);
            
            
        }
    
    }
    
    void AddElement(char element)
    {
        elements.push_back(element);
        permutation.push_back(' ');
        usedIndex.push_back(false);
    }
    void Print()
    {
        for (size_t j = 0; j < vectors.size(); j++)
        {
            permutation = vectors[j];
            RemoveDuplicate(permutation,j+1);
            for (size_t i = 0; i < permutation.size(); i++)
            {
                std::cout<<permutation[i]<<" ";
            }
            std::cout<<std::endl;
        }
        return;
    }
    private:
     void RemoveDuplicate(vector<char> vec, int startIndex)
     {
         for (int i = startIndex; i < vectors.size(); i++)
         {
             if (vectors[i] == vec)
             {
                 vectors.erase(vectors.begin() + i);
             }
             
         }
         
     }
    
     vector<char> elements;
     vector<char> permutation;
     vector<bool> usedIndex;
     vector<vector<char>> vectors;

}permute;




int main()
{
    permute.AddElement('A');
    permute.AddElement('B');
    permute.AddElement('B');
    permute.AddElement('D');
    permute.AddElement('F');
    permute.AddElement('F');
    
    permute.WithoutRepetition(0);
    permute.Print();
    return 0;
}
