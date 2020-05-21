

void Merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int* leftSubarray = new int[leftSize];
    int* rightSubarray = new int[rightSize];

    for( i = 0; i < leftSize; i++)
    {
        leftSubarray[i] = array[left+i];
    }
    for ( j = 0; j < rightSize; j++)
    {
        rightSubarray[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    //The merge
    while(i < leftSize && j < rightSize)
    {
        if(leftSubarray[i] <= rightSubarray[j])
        {
            array[k] = leftSubarray[i];
            i++;
        }
        else
        {
            array[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftSubarray[i];
        i++;
        k++;
    }
    
    while (j < rightSize)
    {
        array[k] = rightSubarray[j];
        j++;
        k++;
    }

    delete[] leftSubarray;
    delete[] rightSubarray;
    
    return;
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = (right+left)/2;

        MergeSort(arr, left, middle);
        MergeSort(arr,middle+1,right);

        Merge(arr,left,middle,right);
    }
    return;
}