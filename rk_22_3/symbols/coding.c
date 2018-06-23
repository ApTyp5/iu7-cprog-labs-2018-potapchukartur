#include <assert.h>

#define		NON_HAPPY_END	-2
#define		HAPPY_END	0
#define 	N		4
#define		ARR		"AGTH"

int coding(char c)
{
	for (int i = 0; i < N; i++)
		if (c == ARR[i])
			return i;

	return NON_HAPPY_END;
}



char encoding(int i)
{
	assert(i >= 0 && i <=3);
	return ARR[i];
}
