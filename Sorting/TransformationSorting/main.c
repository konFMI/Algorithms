#include <stdio.h>
#include "setSort.c"

void readValues (unsigned m[], unsigned size)
{
	unsigned integer = 0;
	for (unsigned i = 0; i < size; i++)
	{
		//scanf("%d", &integer);
		m[size - 1 - i] = i;
	}
}

void printValues(unsigned m[], unsigned size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", m[i]);
	}
	
	printf("\n");
}

int main()
{
	unsigned size = 0;

	do
	{
		printf ("%s demonstration:\nPlease enter number of elements between 1 - %u ","SetSort", MAX_VALUE - 1);
		scanf("%u", &size);
	} while (size < 1 || size >= MAX_VALUE);
	unsigned m[MAX_VALUE];

	readValues (m, size);
	printf("\nBefore Sort:\n");
	printValues (m, size);
	setSort (m, size);
	printf("After Sort:\n");
	printValues (m, size);
	
	return 0;
}
