#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
  int items[MAX];
  int top;
}Stack;

void initstack(Stack *s){
  s->top = -1;
}

int isEmpty(Stack *s){
  return s->top == -1;
}

int isFull(Stack *s){
  return s->top == MAX - 1;
}

void push(Stack *s,int value){
  if (isFull(s))
  {
    printf("Stack overflow we cann't add %d\n" ,value);
    return;
  }
  s->items[++(s->top)] = value;
  printf("Pushed %d to stack\n", value);
}

int pop(Stack *s){
  if(isEmpty(s)){
    printf("stack is underflow we cann't pop the item\n");
  }
  return s->items[(s->top)--];
}
int peek(Stack *s){
  if(isEmpty(s)){
    printf("stack is underflow");
  }
  return s->items[(s->top)];
}
int main(){
  Stack s;
  initstack(&s);
  //push(&s,10);
  //push(&s,20);
  //push(&s,30);
  //push(&s,40);
  //push(&s,50);

  pop(&s);
  return 0;
}