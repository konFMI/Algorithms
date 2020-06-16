#pragma once
#include<vector>
#include<stack>

namespace Algorithms
{
	namespace Sorting
	{
		template <typename TypeKey, typename TypeValue>
		struct Element
		{
			TypeKey key;
			TypeValue value;


			bool operator==(const Element<TypeKey, TypeValue> element)
			{
				bool condition = this->key == element.key && this->value == element.value;

				return condition;
			}
		};

		template <typename TypeKey, typename TypeValue>
		class Sort
		{
		public:
			Sort();

			void InserionSort(std::vector<int>& collection);

			void SelectionSort(std::vector<int>& collection);
			void ShellSort(std::vector<Element<TypeKey, TypeValue>>& collection);

			void BubbleSort(std::vector<int>& collection);
			void ShakeSort(std::vector<Element<TypeKey, TypeValue>>& collection);
			void RabbitTurtleSort(std::vector<Element<TypeKey, TypeValue>>& collection);

			void MergeSort(std::vector<int>& collection, int left, int right);

			//TODO:
			void HeapSort(std::vector<Element<TypeKey,TypeValue>>& collection);
			
			void QuickSort(std::vector <Element<TypeKey, TypeValue>>& collection);

			void SetSort(std::vector<type_t)

			void Swap(int& leftValue, int& rightValue);
			void Swap(Element<TypeKey, TypeValue>* leftElement, Element<TypeKey, TypeValue>* rightElement);

		private:
			//Used by MergeSort.
			void Merge(std::vector<int>& collection, int left, int middle, int right);

			//Used by HeapSort.
			void MaxHeapify(std::vector<Element<TypeKey, TypeValue>>& collection, int length, int index);

			size_t log3Floor(size_t value);

		};
	}


	namespace Sorting
	{
		template<typename TypeKey, typename TypeValue>
		Sort<TypeKey, TypeValue>::Sort()
		{
		}

		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::InserionSort(std::vector<int>& collection)
		{
			size_t lenght = collection.size();
			for (size_t index = 1; index < lenght; index++)
			{
				int j = index - 1;
				int key = collection[index];
				while (j >= 0 && collection[j] > key)
				{
					collection[j + 1] = collection[j];
					j--;
				}
				collection[j + 1] = key;

			}
		}

		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::SelectionSort(std::vector<int>& collection)
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

		//TODO: Not sure if it is still Shell sort or more like Rabbit Turrtle sort. Now it needs an implementation.
		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::ShellSort(std::vector<Element<TypeKey, TypeValue>>& collection)
		{
			
		}
		
		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::BubbleSort(std::vector<int>& collection)
		{
			size_t length = collection.size();
			/*bool notSorted = true;
			while (notSorted)
			{
				notSorted = false;
				for (size_t j = 0; j < length - 1; j++)
				{
					if (collection[j] > collection[j + 1])
					{
						Swap(collection[j], collection[j + 1]);
						notSorted = true;
					}
				}
				length--;
			}*/

			for (size_t i = 1; i < length; i++)
			{
				for (size_t j = length - 1; j >= i; j--)
				{
					if (collection[j-1] > collection[j] )
					{
						Swap(collection[j - 1], collection[j]);
					}
				}
			}

		}

		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::ShakeSort(std::vector<Element<TypeKey, TypeValue>>& collection)
		{
			int k = collection.size(),
				rightIndex = collection.size() - 1,
				leftIndex = 1,
				j = 0;

			do
			{
				for  (j = rightIndex; j >= 1; j--)
				{
					if (collection[j - 1].key > collection[j].key)
					{
						Swap(&collection[j - 1], &collection[j]);
						k = j;
					}
				}

				leftIndex = k + 1;
				for (j = leftIndex; j <= rightIndex; j++)
				{
					if (collection[j - 1].key > collection[j].key)
					{
						Swap(&collection[j - 1], &collection[j]);
						k = j;
					}
				}

				rightIndex = k - 1;
			} while (leftIndex <= rightIndex);
		}

		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::RabbitTurtleSort(std::vector<Element<TypeKey, TypeValue>>& collection)
		{
			size_t swaps = 0, i = 0, j = 0, gap = collection.size();

			do
			{
				// This line is heavy because of the devision
				//gap = size_t(gap / 1.3);
				// If we remove devision like this
				 gap = gap*6 >> 3;
				// It will be faster but it wont be the optimal series.

				swaps = 0;

				if (gap < 1)
				{
					gap = 1;
				}


				for (i = 0; i < collection.size() - gap; i++)
				{
					j = i + gap;
					if (collection[i].key >= collection[j].key)
					{
						Swap(&collection[i], &collection[j]);
						swaps++;
					}
				}

			} while (gap > 1 || swaps > 0);
		}
		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::MergeSort(std::vector<int>& collection, int left, int right)
		{
			if (left < right)
			{
				int middle = left + (right - left) / 2;

				MergeSort(collection, left, middle);
				MergeSort(collection, middle + 1, right);

				Merge(collection, left, middle, right);

			}

		}

		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::HeapSort(std::vector<Element<TypeKey,TypeValue>>& collection)
		{

			size_t length = collection.size();
			for (int i = length / 2 - 1; i >= 0; i--)
			{
				MaxHeapify(collection, length, i);
			}

			for (size_t i = length - 1; i > 0; i--)
			{
				Swap(&collection[0], &collection[i]);

				MaxHeapify(collection, i, 0);
			}


		}

		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::Merge(std::vector<int>& collection, int left, int middle, int right)
		{
			int i = 0, j = 0, k = 0;
			int leftPartSize = middle - left + 1;
			int rightPartSize = right - middle;

			std::vector<int> leftPart(leftPartSize), rightPart(rightPartSize);
			for (i = 0; i < leftPartSize; i++)
			{
				leftPart[i] = collection[left + i];
			}
			for (j = 0; j < rightPartSize; j++)
			{
				rightPart[j] = collection[middle + 1 + j];
			}
			i = 0;
			j = 0;
			k = left;

			while (i < leftPartSize && j < rightPartSize)
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

			while (i < leftPartSize)
			{

				collection[k] = leftPart[i];
				i++;
				k++;
			}
			while (j < rightPartSize)
			{
				collection[k] = rightPart[j];
				j++;
				k++;
			}
		}

		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::MaxHeapify(std::vector<Element<TypeKey,TypeValue>>& collection, int length, int index)
		{
			int largest = index;
			int leftChild = 2 * index + 1;
			int rightChild = 2 * index + 2;

			if (leftChild < length && collection[leftChild].key > collection[largest].key)
			{
				largest = leftChild;
			}

			if (rightChild < length && collection[rightChild].key > collection[largest].key)
			{
				largest = rightChild;
			}

			if (largest != index)
			{
				Swap(&collection[index], &collection[largest]);

				MaxHeapify(collection, length, largest);
			}


		}

		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::QuickSort(std::vector<Element<TypeKey, TypeValue>>& collection)
		{
			TypeKey leftIndex = 0, rightIndex = collection.size() - 1, leftCounter = leftIndex, rightCounter = rightIndex, pivotElement = 0;
			std::stack<std::pair<TypeKey, TypeKey>> workStack;

			workStack.push(std::pair<TypeKey, TypeKey>{ leftIndex, rightIndex });

			while (!workStack.empty())
			{
				leftIndex = workStack.top().first;
				rightIndex = workStack.top().second;
				workStack.pop();

				do
				{
					leftCounter = leftIndex;
					rightCounter = rightIndex;
					pivotElement = collection[(leftIndex + rightIndex) / 2].key;
					do
					{

						while (collection[leftCounter].key < pivotElement) { leftCounter++; }
						while (pivotElement < collection[rightCounter].key) { rightCounter--; }

						if (leftCounter <= rightCounter)
						{
							Swap(&collection[leftCounter], &collection[rightCounter]);
							leftCounter++;
							rightCounter--;
						}
					} while (leftCounter <= rightCounter);

					if (leftCounter < rightIndex)
					{
						workStack.push(std::pair<TypeKey, TypeKey>{leftCounter, rightIndex});
					}
					rightIndex = rightCounter;
				} while (leftIndex < rightIndex);
			}
		}
		
		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::Swap(int& leftValue, int& rightValue)
		{
			int tempValue = leftValue;
			leftValue = rightValue;
			rightValue = tempValue;
		}

		//TODO: Not sure if this inline is correct and if so is it useful?
		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::Swap(Element<TypeKey, TypeValue>* leftElement, Element<TypeKey, TypeValue>* rightElement)
		{
			Element<TypeKey, TypeValue> temp = *leftElement;
			*leftElement = *rightElement;
			*rightElement = temp;
		}
		
		template<typename TypeKey, typename TypeValue>
		size_t Sort<TypeKey, TypeValue>::log3Floor(size_t value)
		{
			{
				long result = 0;
				while (value > 1)
				{
					result++;
					value /= 3;
				}
				return result;
			}
		}

	}
}


