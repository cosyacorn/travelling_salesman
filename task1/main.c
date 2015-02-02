#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

double dist(double **coords, int point_a, int point_b);

int main(int argc, char **argv){

  int nflag, opt, num_cities, i, j;
  double **points;

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

  printf("%f\n", dist(points, 1, 4));

  return 0;
}
