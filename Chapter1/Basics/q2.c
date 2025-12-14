#include <stdio.h>
int main(){
  int age;
  printf("Enter your age");
  scanf("%d",&age);
  if (age<18)
  {
    printf("your a baby");
  }
  else
  {
    printf("you are adul");
  }
  return 0;
}