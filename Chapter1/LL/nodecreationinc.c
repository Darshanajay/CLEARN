#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};

int main(){
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 55;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 33;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 52;
    current->link = NULL;

    head->link->link = current;

    printf("%d\t",head->data);
    printf("%d\t",current->data);
    return 0;
}