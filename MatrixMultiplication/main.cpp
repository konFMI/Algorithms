#include<iostream>
#include<vector>
#include"MatrixMultiplication.cpp"

using std::vector;

void PrintSquareMatrix(vector<vector<int>>& matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
        
    }
    
}
int main()
{
    std::cout<<"Hello Vecher\n";
    
    vector<vector<int>> leftMatrix = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> rightMatrix = 
    {
        {1,0,0},
        {0,-1,0},
        {0,0,1}
    };
    vector<vector<int>> resultMatrix = 
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    
    MultiplyMatrix(leftMatrix,rightMatrix,resultMatrix);
    PrintSquareMatrix(leftMatrix);
    PrintSquareMatrix(rightMatrix);
    PrintSquareMatrix(resultMatrix);
   
    return 0;
}