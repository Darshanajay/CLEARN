#include <stdio.h>

int sum(int a,int b);

int main(){
  int s = sum(3,4);
  printf("Sum is: %d",s);
  
  int s2 = sum(44,55);
  printf("Sum is: %d",s2);

  return 0;
}

int sum(int a , int b){
  return a + b;
}