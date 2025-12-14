#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int customerID;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert customer at the end
void insertEnd(int id) {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->customerID = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Customer %d added to billing queue.\n", id);
    display();
}

// Function to remove customer from the beginning
void deleteBegin() {
    struct Node *temp;

    if (head == NULL) {
        printf("Billing queue is empty. No customer to remove.\n");
        return;
    }

    temp = head;
    printf("Customer %d billing completed.\n", temp->customerID);
    head = head->next;
    free(temp);
    display();
}

// Function to display the list
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("Billing Queue: Empty\n\n");
        return;
    }

    temp = head;
    printf("Billing Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->customerID);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// Main function
int main() {
    insertEnd(101);
    insertEnd(102);
    insertEnd(103);

    deleteBegin();
    deleteBegin();
    deleteBegin();
    deleteBegin(); // Extra delete to show empty case

    return 0;
}
