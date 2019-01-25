/*
Learnt that linux does lazy allocation.
Unless you access the object, it is not actually allocated.
Therefore if m[0] = 0; is commented out, program doesn't throw segmentation fault.
*/

#include <stdlib.h>
int main()
{
	int *m = (int *)malloc(10000000000000*sizeof(int));
	// m[0] = 0;
	return 0;
}
