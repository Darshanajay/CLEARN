#include <stdio.h>

void getData(int arr[],int n){
  printf("Enter a %d array elements: ",n);
  for(int i=0;i<n;i++){
    printf("Enter a element %d ",i+1);
    scanf("%d",&arr[i]);
  }
}

void printData(int arr[],int n){
  printf("Array elements are: ");
  for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
  }
  printf("\n");
}

int large(int arr[],int n){
  int Max = 0;
  for(int i=1;i<n;i++){
    if(arr[i]>arr[Max]){
      Max = i;
    }
  }
  return Max;
}

int small(int arr[],int n){
  int Min = 0;
  for(int i=1;i<n;i++){
    if(arr[i]<arr[Min]){
      Min = i;
    }
  }
  return Min;
}

void swap(int arr[],int Large,int Small){
  int temp;
  temp = Large;
  Large = Small;
  Small = temp;

  printf("Large number after swap: %d\n",arr[Large]);
  printf("Small number after swap: %d\n",arr[Small]);
}



int main(){
  int arr[100];
  int n,Large,Small;
  
  printf("Enter a arr size\n");
  scanf("%d",&n);

  getData(arr,n);
  printData(arr,n);
  Large = large(arr,n);
  Small = small(arr,n);

  printf("Large number before swaping %d\n",arr[Large]);
  printf("Small number before swaping %d\n",arr[Small]);

  swap(arr,Large,Small);
  return 0;
}