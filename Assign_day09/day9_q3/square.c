#include"square.h"
#include<stdio.h>

void square_peri(int side)
{
	int peri = side * 4;
	printf("Perimeter of a square = %d\n", peri);
}

void square_area(int side)
{
	int area = side * side;
	printf("Area of a square = %d\n", area);
}
