#include <stdio.h>

int main(){
  int age = 44;
  int *ptr = &age;
  
  int _age = *ptr;
  
  printf("%d",age);

  // printf("%u",&ptr)777;
  printf("%u",&age);
  return 0;
}