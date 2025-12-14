#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* link;
};

struct node* top = NULL;

void push(int ele){
  struct node* nnode = malloc(sizeof(struct node));
  nnode->data = ele;
  nnode->link = NULL;

  if(nnode == NULL){
    printf("Stack overflow");
  }
  nnode->link = top;
  top = nnode;
  printf("%d pushed onto stack\n", ele);
}
void pop(){
  if(top == NULL){
    printf("stack underflow");
  }
  else{
    struct node* temp = top;
    printf("poped element is: %d",temp->data);
    top = top->link;
    free(temp);
  }
}
void display(){
  struct node* temp = top;
  printf("Stack elements are: ");
  while(temp->link != NULL){
    printf("%d\t",temp->data);
    temp = temp->link;
  }
}

int main(){
  int ch,item;
  do{
    printf("\nstack menu\n");
    printf("1.push\n");
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
      push(item);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
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