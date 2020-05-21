#include<iostream>
#include<vector>

using std::vector;

struct Solution
{
    void WithoutRepetition(int index)
    {
        if(index >= elements.size())
        {
            Print();
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
    void Print()
    {
        for (size_t i = 0; i < permutation.size(); i++)
    {
        std::cout<<permutation[i]<<" ";
    }
        std::cout<<std::endl;

        return;
    }

    void AddElement(char element)
    {
        elements.push_back(element);
        permutation.push_back(' ');
        usedIndex.push_back(false);
    }

    private: vector<char> elements;
    private: vector<char> permutation;
    private: vector<bool> usedIndex;

}permute;




int main()
{
    permute.AddElement('A');
    permute.AddElement('B');
    permute.AddElement('C');
    permute.AddElement('D');
    permute.AddElement('E');
    permute.AddElement('F');
    
    permute.WithoutRepetition(0);

    return 0;
}
