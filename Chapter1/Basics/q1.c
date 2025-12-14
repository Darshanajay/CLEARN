#include <stdio.h>
int main(){
  int a;
  printf("Enter a number: ");
  scanf("%d",&a);
  // printf("the number is:%d",a);
  if(a>0 && a % 2 == 0){
    printf("Yes the number is even");
  }
  else
  {
    printf("THe number is odd");
  };
  
  return 0;
}