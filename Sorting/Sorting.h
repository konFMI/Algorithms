#pragma once
#include<vector>

namespace Algorithms
{
	namespace Sorting
	{
		template <typename TypeKey, typename TypeValue>
		class Element
		{
		public:
			TypeKey key;
			TypeValue value;
			
			//TODO: Not sure if this is ok.
			Element<TypeKey, TypeValue>& operator=(const Element<TypeKey, TypeValue> element)
			{
				if (this != &element)
				{
					this->key = element.key;
					this->value = element.value;
				}

				return *this;
			}
			bool operator==(const Element<TypeKey, TypeValue> element)
			{
				bool condition = this->key == element.key && this->value == element.value;

				return condition;
			}
		private:
		};
		template <typename TypeKey, typename TypeValue>
		class Sort
		{
		public:
			Sort();

			void Inserion(std::vector<int>& collection);

			void Selection(std::vector<int>& collection);

			void Bubble(std::vector<int>& collection);
			void Shake(std::vector<Element<int, int>>& collection);

			void MergeSort(std::vector<int>& collection, int left, int right);
			void Merge(std::vector<int>& collection, int left, int middle, int right);

			//TODO:
			void HeapSort(std::vector<int>& collection)
			{
				size_t length = collection.size();
				for (size_t i = length / 2 - 1; i >= 0; i--)
				{
					MaxHeapify(collection, length, i);
				}

				for (size_t i = length - 1; i > 0; i--)
				{
					Swap(collection[0], collection[i]);

					MaxHeapify(collection, i, 0);
				}

			}
			void MaxHeapify(std::vector<int>& collection, int length, int index);

			void Swap(int& leftValue, int& rightValue);
			void Swap(Element<TypeKey, TypeValue>* leftElement, Element<TypeKey, TypeValue>* rightElement);
		};
	}

	namespace Sorting
	{
		template<typename TypeKey, typename TypeValue>
		Sort<TypeKey, TypeValue>::Sort()
		{
		}

		template<typename TypeKey, typename TypeValue>
		void Sort<TypeKey, TypeValue>::Inserion(std::vector<int>& collection)
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
		void Sort<typename TypeKey, typename TypeValue>::Selection(std::vector<int>& collection)
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
		
		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::Bubble(std::vector<int>& collection)
		{
			size_t length = collection.size();
			bool notSorted = true;
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
			}


		}

		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::Shake(std::vector<Element<int, int>>& collection)
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
		void Sort<typename TypeKey, typename TypeValue>::MaxHeapify(std::vector<int>& collection, int length, int index)
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

				MaxHeapify(collection, length, largest);
			}


		}

		template<typename TypeKey, typename TypeValue>
		void Sort<typename TypeKey, typename TypeValue>::Swap(int& leftValue, int& rightValue)
		{
			int tempValue = leftValue;
			leftValue = rightValue;
			rightValue = tempValue;
		}

		template<typename TypeKey, typename TypeValue>
		inline void Sort<TypeKey, TypeValue>::Swap(Element<TypeKey, TypeValue>* leftElement, Element<TypeKey, TypeValue>* rightElement)
		{
			Element<TypeKey, TypeValue> temp = *leftElement;
			*leftElement = *rightElement;
			*rightElement = temp;



		}
	}
}


