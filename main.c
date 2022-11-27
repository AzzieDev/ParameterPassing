#include <stdio.h>
int w;
int z[3];

//call by value
void f (int m, int n) {
  w = w + 1;
  //next two lines are irrelevant
  n = 3;
  m = n * 10;
  //m and n are discarded
  //z[w] --> z[1] = 20
  //z[0] = 10
}

//call by value-result simulation
void g(int *p, int *q){
  //copy data locally
  int m = *p;
  int n = *q;
  
  w = w + 1;
  n = 3;
  //next line is irrelevent
  m = n * 10; 
  
  //copy back the data
  *p = m; //z[0] = 10 --> m = 30
  *q = n; //z[0] = 30 --> n = 3
}

//call by reference
void h (int *m, int *n) {
  w = w + 1;
  *n = 3;
  *m = *n * 10;
  //m and n share address locations with z[1] and z[0]
  //z[w] = z[0] --> z[1] = 20
  //z[0] = 10 --> m = 30
}

//call by name simulation
void k (int m, int n) {
  w = w + 1;
  n = 3;
  m = n * 10;

  //simulated sequence
  z[w] = m; //"z[w]" = z[1] = 20 --> m = 30
  z[0] = n; //"z[0]" = z[0] = 10 --> n = 3
}

int main () {
  
  //call by value
  w = 0;
  z[0] = 10;
  z[1] = 20;
  z[2] = 30;
  f(z[w], z[0]);
  printf("Call by Value:\n");
  printf("%d , %d\n\n" , z[w], z[0]);
  //z[1] = 20
  //z[0] = 10

  //call by value-result simulation
  w = 0;
  //next 3 lines are unnecessary
  z[0] = 10;
  z[1] = 20;
  z[2] = 30;
  g(&z[w], &z[0]);
  printf("Call by Value-Result:\n");
  printf("%d , %d\n\n" , z[w], z[0]);
  //z[1] = 20
  //z[0] = 3

  //call by reference
  w = 0;
  z[0] = 10;
  z[1] = 20;
  z[2] = 30;
  printf("Call by Reference:\n");
  h(&z[w], &z[0]);
  printf("%d , %d\n\n" , z[w], z[0]);
  //z[1] = 20
  //z[0] = 30
  
  //call by name simulation
  w = 0;
  z[0] = 10;
  z[1] = 20;
  z[2] = 30;
  printf("Call by Name:\n");
  k(z[w], z[0]);
  printf("%d , %d\n\n" , z[w], z[0]);
  //z[1] = 30
  //z[0] = 3
  
}
