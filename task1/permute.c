#include<stdio.h>
void swap(int v[], int i, int j);
double dist(double **coords, int point_a, int point_b);


int **permute(int *order, int n, int i, int **route){

  int j;

  if(i==n){
    for(j=0;j<n;j++){
      printf("%d ", j);
      route[i][j]=order[j];
    }
    printf("\n");
  }else{

    for(j=i;j<n;j++){
      swap(order,i, j);
      permute(order, n, (i+1), route);
      swap(order, i, j); 
    }
  }
  

  return route;

  //for(i=0;i<n;i++)
  //printf("%d\n", order[i]);
}
