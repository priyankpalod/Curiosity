/*
* When is sizeof computed - compile time or runtime?
* Generated the assembly for this program to see if the constants are present.
* Result:-
* 	sizeof computed at compile time except for the two variable length arrays vla1 & vla2 - And it is equal to 4*(size of the array)
*	sizeof for any other pointer to the same array is still 8, even if the pointer is const
*/

#include <stdio.h>

int main()
{
	int a_fix[100], n1 = 100, n2;
	int vla1[n1];
	int *int_ptr = a_fix;
	const int *const_int_ptr = a_fix;

	scanf("%d", &n2);
	int vla2[n2];

	printf("%lu\n", sizeof a_fix );		// 400
	printf("%lu\n", sizeof n1);			// 4
	printf("%lu\n", sizeof vla1 );		// 400
	printf("%lu\n", sizeof int_ptr );	// 8, Since it is 64 bit machine
	printf("%lu\n", sizeof const_int_ptr );	// 8, Since it is 64 bit machine
	printf("%lu\n", sizeof vla2 );		// IF input n2 100, it is 400

	return 0;
}