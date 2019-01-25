/*
Same process can write and read in the pipe
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	int p[2], x =10, y = 193434;
	pipe(p);
	write(p[1], &x, 5);
	read(p[0], &y, 5);
	cout<<y<<endl;	// 10
	return 0;
}