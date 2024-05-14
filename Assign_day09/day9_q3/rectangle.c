#include<stdio.h>
#include"rectangle.h"

void rect_peri(int len, int bre)
{
	int peri = 2*(len + bre);
	printf("Perimeter of a rectangle = %d\n", peri);
}

void rect_area(int len, int bre)
{
	int area = len * bre;
	printf("Area of a rectangle = %d\n", area);
}

