//We assume all values are valid.

#include<tuple>
#include<limits>
#include<iostream>
#include<algorithm>

using std::tuple;
using std::make_tuple;
using std::get;
using std::numeric_limits;
using std::max;

//Complexity O(n)
tuple<int,int,int> FindMaxCrossingSubarray(int* array, int low, int mid, int high)
{
    int leftSum = numeric_limits<int>::min();
    int maxLeftIndex = mid;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += array[i];
        if ( sum > leftSum)
        {
            leftSum = sum;
            maxLeftIndex = i;
        }
    }
    int rightSum = numeric_limits<int>::min();
    int maxRightIndex = mid;
    sum = 0;
    for (size_t i = mid + 1; i <= high; i++)
    {
        sum += array[i];
        if(sum > rightSum)
        {
            rightSum = sum;
            maxRightIndex = i;
        }
    }
    return make_tuple(maxLeftIndex,maxRightIndex,leftSum+rightSum);
    
}

//Complexity O(n*logn)
tuple<int,int,int> FindMaxSubarray(int* array, int low, int high)
{
    if (low == high)
    {
        return make_tuple(low,high,array[low]); // There is one element;
    }
    int mid = (low+high) / 2;
    tuple<int,int,int> leftSubarray = FindMaxSubarray(array,low,mid);
    tuple<int,int,int> righSubarray = FindMaxSubarray(array, mid + 1, high);
    tuple<int,int,int> crossingSubarray = FindMaxCrossingSubarray(array,low,mid,high);
    int leftSum = get<2>(leftSubarray);
    int rightSum = get<2>(righSubarray);
    int crossSum = get<2>(crossingSubarray);
    
    if (leftSum >= rightSum && leftSum >= crossSum)
    {
        return leftSubarray;
    }
    else if (rightSum >= leftSum && rightSum >= crossSum)
    {
        return righSubarray;
    }
    else
    {
        return crossingSubarray;
    }
}

//Complexity O(n)
tuple<int,int,int> MaxSubarrayKadane(int* array, int size)
{
    int localMaxSum = 0;
    int globalMaxSum = 0;
    int leftIndex = 0, rightIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        localMaxSum += array[i];
        if (localMaxSum < 0)
        {
            leftIndex = i+1;
            localMaxSum = 0;
        }
        
        if (localMaxSum > globalMaxSum)
        {
            rightIndex = i;
            globalMaxSum = localMaxSum;
        }
    }
    
    return make_tuple(leftIndex,rightIndex,globalMaxSum);
}