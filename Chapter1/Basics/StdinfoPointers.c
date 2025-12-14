#include <stdio.h>

struct StdInfo
{
  char Name [10];
  char USN [10];
  int age;
};


void readData(struct StdInfo s1[10]){
  for (int i = 0; i <2; i++)
  {
    printf("Enter Your Name: \n");
    scanf("%s",s1[i].Name);
    printf("Enter your USN: \n");
    scanf("%s",s1[i].USN);
    printf("Enter Your age: \n");
    scanf("%d",&s1[i].age);
  }
}

void writeData(struct StdInfo s1[10]){
  for (int i = 0; i < 2; i++)
  {
    printf("Your Name is: %s\n",s1[i].Name);
    printf("Your Name is: %s\n",s1[i].USN);
    printf("Your Name is: %d\n",s1[i].age);
  }
}

int main(){
  struct StdInfo s1[10];
  readData(s1);
  writeData(s1);
  return 0;
}