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
		Sort<int,int> sort;
		const size_t sizeOfVector = 50;
	public:

		TEST_METHOD(SwapIntegersTest)
		{
			int left = 5,
				right = 10,
				expectedLeft = right,
				expectedRight = left;

			sort.Swap(left, right);

			Assert::AreEqual( left, expectedLeft );
			Assert::AreEqual( right, expectedRight );
		}

		TEST_METHOD(SwapIntegersIdentityTest)
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

		TEST_METHOD(SwapElementIdentityTest)
		{

			Element<int, int> left = { 5,7 },
				right = { 10, 12 },
				expectedLeft = left,
				expectedRight = right;

			sort.Swap(&left, &right);
			sort.Swap(&left, &right);

			bool leftEqual = left == expectedLeft;
			bool rightEqual = right == expectedRight;
			Assert::IsTrue(leftEqual);
			Assert::IsTrue(rightEqual);
		}

		TEST_METHOD(SwapElementTest)
		{
			Element<int, int> left = { 5,7 },
				right = { 10, 12 },
				expectedLeft = right,
				expectedRight = left;

			sort.Swap(&left, &right);

			bool leftEqual = left == expectedLeft;
			bool rightEqual = right == expectedRight;
			Assert::IsTrue(leftEqual);
			Assert::IsTrue(rightEqual);
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

			bool areEqual = actuall == expected;
			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(ShakeSortBasicTest)
		{
			std::vector<Element<int,int>> expected;
			std::vector<Element<int,int>> actuall;
			for (int i = 0; i <= sizeOfVector; i++)
			{
				actuall.push_back(Element<int, int>{(int)sizeOfVector - i, i});
				expected.push_back(Element<int, int>{i, (int)sizeOfVector - i});
			}

			sort.Shake(actuall);

			bool areEqual = true;
			for (size_t i = 0; i < sizeOfVector; i++)
			{
				areEqual = areEqual && expected[i] == actuall[i];
			}

			Assert::IsTrue(areEqual);
		}
	};
}
