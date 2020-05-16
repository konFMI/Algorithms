//We assume all matrices are square

#include<vector>
#include<iostream>
using std::vector;

// O(n^3)
void MultiplyMatrix(vector<vector<int>>& leftMatrix,vector<vector<int>>& rightMatrix, vector<vector<int>>& resultMatrix)
{

    for (size_t i = 0; i < leftMatrix.size(); i++)
    {

        for (size_t j = 0; j < rightMatrix.size(); j++)
        {

            for (size_t k = 0; k < rightMatrix.size(); k++)
            {
                resultMatrix[i][j] += leftMatrix[i][k]*rightMatrix[k][j];
            }
            
        }
        
    }
    
}