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
					if (collection[swapIndex] < collection[j])
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
				for (size_t i = length, j = 0; j < i - 1; j++,i--)
				{
					if (collection[j] > collection[j+1])
					{
						collection[length - 1]++;
						Swap(collection[j], collection[j + 1]);
						notSorted = true;
					}
				}
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