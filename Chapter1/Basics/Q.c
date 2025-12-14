#include <stdio.h>
#include <stdlib.h>
#define MAX 4


typedef struct {
  int rear;
  int front;
  int qarr[MAX];
}Q;

void init (Q *q){
  q->front = -1;
  q->rear = -1;
}

int isFull(Q *q){
  return q->rear == MAX-1;
}
int isEmpty(Q *q){
  return q->front || q->rear == -1;
}

void enque(Q *q,int ele){
  if(isFull(q)){
    printf("Q Overflow");
  }
  if(isEmpty(q)){
    q->front = 0;
  }
  else{
    q->rear++;
    q->qarr[q->rear] = ele;
    printf("%d inserted onto Q",ele);
  }
}

void deque(Q *q){
  if(isEmpty(q)){
    printf("Q Underflow");
  }
  else{
    int ele;
    ele = q->qarr[q->front];
    q->front--;
    printf("del element%d",ele);
  }
}

void display(Q *q){
  if(isEmpty(q)){
    printf("Q Underflow");
  }
  printf("queue elements are: ");
  for(int i = q->front;i<=q->rear;i++){
    printf("%d\t",q->qarr[i]);
  }
  printf("\n");
}


int main(){
  Q q;
  init(&q);
  int ch,item;
  do{
    printf("\nstack menu\n");
    printf("1.enque\n");
    printf("2.deque\n");
    printf("3.display\n");
    printf("4.Exit.........\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
      printf("Enter a element: ");
      scanf("%d",&item);
      enque(&q,item);
      break;
    case 2:
      deque(&q);
      break;
    case 3:
      display(&q);
      break;
    case 4:
      printf("Exiting.......\n");
      break;
    default:
      printf("invalid choice, try again");
      break;
    }
  }while(ch != 4);

}