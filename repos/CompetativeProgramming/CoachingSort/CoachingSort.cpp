// CoachingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
int getValue(char a)
{
	if (a >= '0' && a <= '9')
	{
		return a;
	}
	else if (a >= 'a' && a <= 'z')
		{
			return (a - 'a') + 'A';
		}
	else  if (a >= 'A' && a <= 'Z')
	{
		return (a - 'A') + 'a';
	}

	return 0;
}
void Merge(std::string &array, int left, int middle, int right)
{
    int i, j, k;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    char* leftSubarray = new char[leftSize+1];
    char* rightSubarray = new char[rightSize+1];

    for (i = 0; i < leftSize; i++)
    {
        leftSubarray[i] = array[left + i];
    }
    for (j = 0; j < rightSize; j++)
    {
        rightSubarray[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    //The merge
    while (i < leftSize && j < rightSize)
    {
        if (getValue(leftSubarray[i]) <= getValue(rightSubarray[j]))
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

void MergeSort(std::string &arr, int left, int right)
{
    if (left < right)
    {
        int middle = (right + left) / 2;

        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);

        Merge(arr, left, middle, right);
    }
    return;
}
int main()
{
	//int size = 0;
	//std::cin >> size;

	std::string array;
	//std::cin >> array;
	//for (size_t i = 0; i < array.length()-1; i++)
	//{
	//	int min = i;
    //
	//	for (size_t j = i + 1; j < array.length(); j++)
	//	{
	//		if (getValue(array[min]) > getValue(array[j]))
	//		{
	//			min = j;
	//		}
	//	}
	//	char temp = array[i];
	//	array[i] = array[min];
	//	array[min] = temp;
	//}
    //
    //std::cout << array << std::endl;
    std::cin >> array;
    MergeSort(array, 1, array.length());
    std::cout << array;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
