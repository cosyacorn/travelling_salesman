#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>

double dist(double **coords, int point_a, int point_b);
void permute(int *order, int n, int i, int **route);

int factorial(int n){
  if (n<=1)
    return(1);
  else
    n=n*factorial(n-1);
  return(n);
}


int main(int argc, char **argv){

  int nflag, *order, opt, num_cities, i, j, k, num_perms, **route;
  double **points, **dists;

  srand48(time(NULL));

  nflag=0;

  while((opt=getopt(argc,argv,"n:"))!=-1){
    switch(opt){

    case 'n':
      nflag=1;
      num_cities=atoi(optarg);

    }
  }

  if(nflag!=1){
    num_cities=10;
  }


  //INITIALISE THE POINTS
  points=(double**)malloc(sizeof(double*)*num_cities);
  for(i=0;i<num_cities;i++){
    points[i]=(double*)malloc(sizeof(double)*2);
    for(j=0;j<2;j++){
      points[i][j]=drand48();
      //printf("%f ", points[i][j]);
    }
    //printf("\n");
  }


  num_perms=factorial(num_cities-1);
  
  
  route=(int**)malloc(sizeof(int*)*num_perms);
  for(k=0;k<num_perms;k++){
    route[k]=(int*)malloc(sizeof(int)*num_cities);
    for(j=0;j<num_cities;j++){
      route[k][j]=j;
    }
  }





  dists=(double**)malloc(sizeof(double*)*num_cities);
  for(i=0;i<num_cities;i++){
    dists[i]=(double*)malloc(sizeof(double)*(num_cities-(i+1)));
    for(j=i+1;j<num_cities;j++){
      dists[i][j]=dist(points, i, j);
      //printf("%f %d %d\n", dists[i][j], i, j);
    }
  }

  
  order=(int*)malloc(sizeof(int)*num_cities);
  for(i=0;i<num_cities;i++){
    order[i]=i;
    //printf("%d ", order[i]);
  }
  //printf("\n");

  //permute(order, num_cities, 0);


  //for(i=0;i<num_cities;i++){
  permute(order, num_cities, 1, route);

  for(i=0;i<num_perms;i++){
    for(j=0; j<num_cities;j++){
      printf("%d ", route[i][j]);
    }
    printf("\n");
  }

  return 0;
}
