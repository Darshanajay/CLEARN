#include <stdio.h>

void greet(int inp);

int main(){
  greet(1);
  return 0;
}

void greet(int inp){
  if (inp == 1)
  {
    printf("Namasthe");
  }
  else{
    printf("Welcome");
  }
  
}