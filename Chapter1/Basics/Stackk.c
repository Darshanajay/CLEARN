#include <stdio.h>

#define Max 3
typedef struct
{
  int st[Max];
  int top;
}stack;

void init(stack *s){
  s->top = -1;
}

int isFull(stack *s){
  return s->top == Max -1;
}

int isEmpty(stack *s){
  return s->top == -1;
}

void push(stack *s,int ele){
  if (isFull(s))
  {
    printf("Stack is Full...");
  }
  else
  {
    s->top++;
    s->st[s->top] = ele;
    printf("inserted element is%d\n",ele);
  }
}

void pop(stack *s){
  if(isEmpty(s)){
    printf("Stack is empty...");
  }
  else{
    int ele = s->st[s->top--];
    printf("poped element is %d",ele);
  }
}

void display(stack *s){
  if(isEmpty(s)){
    printf("Stack is empty...");
  }
  else{
    for(int i =0;i<=s->top;i++){
      printf("%d,",s->st[i]);
    }
  }
}


int main(){
  stack s;
  init(&s);

  push(&s,20);
  push(&s,200);
  push(&s,10);

  display(&s);

  //pop(&s);
  
  return 0;
}