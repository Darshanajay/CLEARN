#include <stdio.h>

struct std{
  char usn[10];
  char name[10];
  float cgpa;
  int age;
};

void getInfo(struct std s[], int n){
  for(int i=0;i<n;i++){
    printf("Enter student %d details\n",i+1);
    printf("Enter a USN: \n");
    scanf("%9s", s[i].usn);
    printf("Enter a Name: \n");
    scanf("%9s", s[i].name);
    printf("Enter a cgpa: \n");
    scanf("%f", &s[i].cgpa);
    printf("Enter a Age: \n");
    scanf("%d", &s[i].age);
  }
}

void printData(struct std s[], int n){
  for(int i=0;i<n;i++){
    if(s[i].cgpa > 7.5f){
      printf("USN is %s\n", s[i].usn);
      printf("Name is %s\n", s[i].name);
      printf("CGPA is %.2f\n", s[i].cgpa);
      printf("AGE is %d\n", s[i].age);
    }
  }
}

int main(){
  struct std s[66];
  int n;

  printf("Enter n number details: \n");
  scanf("%d",&n);

  getInfo(s,n);
  printData(s,n);

  return 0;
}