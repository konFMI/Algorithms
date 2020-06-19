#include <assert.h>

const unsigned  MAX_VALUE =  10000;

void setSort( unsigned m[], unsigned n)
{
	char set[MAX_VALUE];
	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		set[i] = 0;
	}

	for (j = 0; j < n; j++)
	{
		assert (m[j] >= 0 && m[j] < n && set[m[j]] == 0);
		set[m[j]] =  1;
	}

	for (i = j = 0; i < n; i++)
	{
		if (set[i])
		{
			m[j++] = i;
		}
	}

	assert ( j == n);
}
