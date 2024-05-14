#include<stdio.h>
#include<stdlib.h>
#include"circle.c"
#include"square.c"
#include"rectangle.c"
int main()
{
	circle_peri(4);
	circle_area(4);
	square_peri(5);
	square_area(5);
	rect_peri(7,5);
	rect_area(7,5);
	return 0;
}
