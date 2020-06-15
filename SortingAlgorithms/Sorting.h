#include<vector>

namespace Algorithms
{

	namespace Sorting
	{
		class Sort
		{
		public:
			Sort();

			void Inserion(std::vector<int> &collection);

			void Selection(std::vector<int>& collection);

			void Bubble(std::vector<int>& collection);

			void MergeSort(std::vector<int>& collection,int left, int right);
			void Merge(std::vector<int>& collection, int left, int middle, int right);

			void HeapSort(std::vector<int>& collection)
			{
				size_t length= collection.size();
				for (size_t i = length/2 - 1; i >=0; i--)
				{
					MaxHeapify(collection, length,i);
				}

				for (size_t i = length - 1; i > 0 ; i--)
				{
					Swap(collection[0], collection[i]);

					MaxHeapify(collection, i, 0);
				}

			}
			void MaxHeapify(std::vector<int>& collection,int length, int index);

			void Swap(int& leftValue, int& rightValue);
		};
	}
}


