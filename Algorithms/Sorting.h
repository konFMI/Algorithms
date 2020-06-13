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
		private:

			void Swap(int& leftValue, int& rightValue);
		};
	}
}


