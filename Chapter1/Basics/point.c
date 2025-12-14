#include <stdio.h>
#include <stdlib.h>
int main(){
  int *p,n;
  printf("Enter a n value");
  scanf("%d",&n);
  p = (int *)malloc(n*sizeof(int));
  printf("Int number");
  for(int i = 0;i<n;i++){
    printf("%d",*p);
    scanf("%d",p+i);
  }

  free(p);
  return 0;
}