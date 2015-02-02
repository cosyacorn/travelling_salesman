#include<math.h>

double dist(double **coords, int point_a, int point_b){

  double length, x, y;

  x=coords[point_a][0]-coords[point_b][0];
  y=coords[point_b][1]-coords[point_b][1];
  length=x*x+y*y;
  length=sqrt(length);

  return length;
}
