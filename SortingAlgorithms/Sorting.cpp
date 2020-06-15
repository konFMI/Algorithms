#include "Sorting.h"
#include <vector>

namespace Algorithms
{
	namespace Sorting
	{
		Sort::Sort()
		{
		}

		void Sort::Inserion(std::vector<int> &collection)
		{
			size_t lenght = collection.size();
			for (size_t index = 1; index < lenght; index++)
			{
				int j = index - 1;
				int key = collection[index];
				while (j >= 0 && collection[j] > key)
				{
					collection[j+1] = collection[j];
					j--;
				}
				collection[j + 1] = key;

			}
		}

		void Sort::Selection(std::vector<int>& collection)
		{
			size_t length = collection.size();
			for (size_t i = 0; i < length - 1; i++)
			{
				size_t swapIndex = i;

				for (size_t j = i + 1; j < length; j++)
				{
					if (collection[swapIndex] > collection[j])
					{
						swapIndex = j;
					}
				}
						Swap(collection[i], collection[swapIndex]);
			}
		}

		void Sort::Bubble(std::vector<int>& collection)
		{
			size_t length = collection.size();
			bool notSorted = true;
			while (notSorted)
			{
				notSorted = false;
				for (size_t j = 0; j < length-1; j++)
				{
					if (collection[j] > collection[j+1])
					{
						Swap(collection[j], collection[j + 1]);
						notSorted = true;
					}
				}
				length--;
			}

			
		}

		void Sort::MergeSort(std::vector<int>& collection, int left, int right)
		{
			if (left < right)
			{
				int middle = left + (right - left) / 2;

				MergeSort(collection, left, middle);
				MergeSort(collection, middle+1, right);

				Merge(collection, left, middle, right);

			}
			
		}


		void Sort::Merge(std::vector<int>& collection, int left,int middle, int right)
		{
			int i = 0, j = 0, k = 0;
			int leftPartSize = middle - left + 1;
			int rightPartSize = right - middle;
			
			std::vector<int> leftPart(leftPartSize), rightPart(rightPartSize);
			for (i = 0; i < leftPartSize; i++)
			{
				leftPart[i] = collection[left+i];
			}
			for (j = 0; j < rightPartSize; j++)
			{
				rightPart[j] = collection[middle +1 + j];
			}
			i = 0;
			j = 0;
			k = left;

			while (i < leftPartSize && j < rightPartSize )
			{
				if (leftPart[i] < rightPart[j])
				{
					collection[k] = leftPart[i];
					i++;
				}
				else
				{
					collection[k] = rightPart[j];
					j++;
				}
				k++;
			}

				while (i < leftPartSize )
				{

					collection[k] = leftPart[i];
					i++;
					k++;
				}
				while (j < rightPartSize )
				{
					collection[k] = rightPart[j];
					j++;
					k++;
				}
		}

		void Sort::MaxHeapify(std::vector<int>& collection,int length, int index)
		{
			int largest = index;
			int leftChild = 2 * index + 1;
			int rightChild = 2 * index + 2;

			if (leftChild < length && collection[leftChild] > collection[largest])
			{
				largest = leftChild;
			}

			if (rightChild < length && collection[rightChild] > collection[largest])
			{
				largest = rightChild;
			}

			if (largest != index)
			{
				Swap(collection[index], collection[largest]);

				MaxHeapify(collection,length, largest);
			}


		}

		void Sort::Swap(int& leftValue, int& rightValue)
		{
			int tempValue = leftValue;
			leftValue = rightValue;
			rightValue = tempValue;
		}
	}

}