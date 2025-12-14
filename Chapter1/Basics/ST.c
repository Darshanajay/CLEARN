#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
  int top;
  int Sarr[MAX];
}stack;

void init(stack *s){
  s->top = -1;
}

int isEmpty(stack *s){
  return s->top == -1;
}

int isFull(stack *s){
  return s->top == MAX - 1;
}


int push(stack *s,int ele){
  if(isFull(s)){
    printf("stack overflow");
  }
  else{
    s->top++;
    s->Sarr[s->top] = ele;
    printf("Pushed %d to stack\n", ele);
  }
  return 0;
}


int pop(stack *s){
  if(isEmpty(s)){
    printf("stack underflow");
  }
  else{
    int ele;
    ele = s->Sarr[s->top];
    s->top--;
    printf("poped element: %d",ele);
  }
  return 0;
}

void display(stack *s){
  if(isEmpty(s)){
    printf("stack underflow");
  }
  printf("Elements are: ");
  for(int i =0;i<=s->top;i++){
    printf("%d\t",s->Sarr[i]);
  }
}

int main(){
  stack st;
  init(&st);
  int ch,item;
  do{
    printf("\nstack menu\n");
    printf("1.piush\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.Exit.........\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
      printf("Enter a element: ");
      scanf("%d",&item);
      push(&st,item);
      break;
    case 2:
      pop(&st);
      break;
    case 3:
      display(&st);
      break;
    case 4:
      printf("Exiting.......\n");
      break;
    default:
      printf("invalid choice, try again");
      break;
    }
  }while(ch != 4);
  return 0;
}