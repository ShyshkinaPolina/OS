#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(int x){
	return exp(-abs(x))*sin(x);
}

double g(int x){
	return exp(-abs(x))*cos(x);
}

int main()
{
	int x;
	printf("Enter x: ");
	scanf("%d",&x);
	printf("f=%lf\n", f(x));
	printf("g=%lf\n", g(x));
}
