#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

double dist(double *point_a, double point_b);

int main(int argc, char **argv){

  int nflag, opt, num_cities;

  srand48(time(NULL));

  nflag=0;

  while((opt=getopt(argc,argv,"n:"))!=-1){
    switch(opt){

    case 'n':
      nflag=1;
      num_cities=atoi(optarg);

    }
  }

  return 0;
}
