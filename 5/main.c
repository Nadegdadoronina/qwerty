#include <stdio.h>

extern void mult(double, int);

extern void print(double f)
{
	printf("%lf", f);
}


int main()
{
	mult(246.777, 4);
	return 0;
}