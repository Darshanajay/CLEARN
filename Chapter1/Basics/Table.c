#include <stdio.h>

void Table(int a){
  for(int i=1;i<=10;i++){
    int r = a * i;
    printf("%d * %d = %d\n",a,i,r);
    // return 0;
  }
}


int main(){
  int num;
  printf("Enter a number: ");
  scanf("%d",&num);
  Table(num);
  return 0;
}