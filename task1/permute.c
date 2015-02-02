#include<stdio.h>
void swap(int *x, int *y);

void permute(int *x, int n, int i){

  int j;

  if(i==n){
    for(j=0;j<n;j++) printf("%d ", x[j]);
    printf("\n");
  }
  else{
    for(j=i;i<n;j++){
      swap(x[i], x[j]);
      permute(x, n, i+1);
      swap(x[i], x[j]);
    }
  }
}
