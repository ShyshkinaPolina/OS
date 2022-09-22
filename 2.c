#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "g.h"

int main()
{
	int x;
	printf("Enter x: ");
	scanf("%d",&x);
	printf("f=%lf\n", f(x));
	printf("g=%lf\n", g(x));
}
