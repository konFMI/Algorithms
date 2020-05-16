namespace MaximumSubarray
{
    #include<iostream>
    #include<tuple>
    #include<limits>
    
    using std::tuple;
    using std::make_tuple;
    using std::get;
    using std::numeric_limits;

    tuple<int,int,int> FindMaxCrossingSubarray(int* array, int low, int mid, int high)
    {
        tuple<int,int,int> data;
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

        data = make_tuple(maxLeftIndex,maxRightIndex,leftSum+rightSum);
        return data;
    }

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
}