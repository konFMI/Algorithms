#include "pch.h"
#include "CppUnitTest.h"
#include "../Sorting.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Algorithms::Sorting;

namespace SortingTest
{
	TEST_CLASS(SortingTest)
	{
	private:
		Sort sort;
		const size_t sizeOfVector = 50;
	public:

		TEST_METHOD(SwapTest)
		{
			int left = 5,
				right = 10,
				expectedLeft = right,
				expectedRight = left;

			sort.Swap(left, right);

			Assert::AreEqual( left, expectedLeft );
			Assert::AreEqual( right, expectedRight );
		}

		TEST_METHOD(SwapAfterSwapShouldBeAnIdentity)
		{
			int left = 5,
				right = 10,
				expectedLeft = left,
				expectedRight = right;

			sort.Swap(left, right);
			sort.Swap(left, right);

			Assert::AreEqual(left, expectedLeft);
			Assert::AreEqual(right, expectedRight);
		}

		TEST_METHOD(SwapIdentityTest)
		{
			int left = 5,
				right = 10,
				expectedLeft = left,
				expectedRight = right;

			sort.Swap(left, left);
			sort.Swap(right, right);

			Assert::AreEqual(left, expectedLeft);
			Assert::AreEqual(right, expectedRight);
		}

		TEST_METHOD(BubbleSortBasicTest)
		{
			std::vector<int> expected;
			std::vector<int> actuall;
			for (size_t i = 0; i <= sizeOfVector; i++)
			{
				actuall.push_back(sizeOfVector - i);
				expected.push_back(i);

			}

			sort.Bubble(actuall);

			Assert::AreEqual(actuall == expected, true);
		}

		TEST_METHOD(InsertionSortBasicTest)
		{
			std::vector<int> expected;
			std::vector<int> actuall;
			for (size_t i = 0; i <= sizeOfVector; i++)
			{
				actuall.push_back(sizeOfVector - i);
				expected.push_back(i);

			}

			sort.Inserion(actuall);

			Assert::AreEqual(actuall == expected, true);
		}

		TEST_METHOD(SelectionSortBasicTest)
		{
			std::vector<int> expected;
			std::vector<int> actuall;
			for (size_t i = 0; i <= sizeOfVector; i++)
			{
				actuall.push_back(sizeOfVector - i);
				expected.push_back(i);

			}

			sort.Selection(actuall);

			Assert::AreEqual(actuall == expected, true);
		}

		TEST_METHOD(MergeSortBasicTest)
		{
			std::vector<int> expected;
			std::vector<int> actuall;
			for (size_t i = 0; i <= sizeOfVector; i++)
			{
				actuall.push_back(sizeOfVector - i);
				expected.push_back(i);

			}

			sort.MergeSort(actuall, 0, actuall.size() - 1);

			Assert::AreEqual(actuall == expected, true);
		}
	};
}
