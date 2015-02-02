#include<math.h>

double dist(double *point_a, double *point_b){

  double length, x, y;

  x=point_a[0]-point_b[0];
  y=point_b[1]-point_b[1];
  length=x*x+y*y;
  length=sqrt(length);

  return length;
}
