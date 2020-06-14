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

			void Swap(int& leftValue, int& rightValue);
		};
	}
}


