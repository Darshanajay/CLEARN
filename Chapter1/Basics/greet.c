#include <stdio.h>

char greet (char a[]);

int main(){
  char name[20];
  printf("Enter a your name: ");
  scanf("%s",name);
  greet(name);
  return 0;
}

char greet(char a[]){
  return printf("Welcome %s",a);
}