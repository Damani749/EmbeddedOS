#include"circle.h"
#include<stdio.h>

void circle_peri(int rad)
{
	int peri = rad * 2 * pi;
	printf("Perimeter of circle = %d\n", peri);
}

void circle_area(int rad)
{
	int area = rad * rad * pi;
	printf("Area of circle = %d\n", area);
}
