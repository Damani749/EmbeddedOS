#include<stdio.h>
#include"circle.h"
#include"rectangle.h"
#include"square.h"
int main()
{
  printf("The area of the rectangle is %f\n",rectangle_area(12.3,2.4));
  printf("The area of the square is %f\n",square_area(12.8));
  printf("The area of the circle is %f\n",circle_area(23.3));
  return 0;
}
