#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int fileNo;
    int memory;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Memory Allocation List: Empty\n\n");
        return;
    }

    printf("Memory Allocation List:\n");
    while (temp != NULL) {
        printf("File No: %d | Memory: %d KB\n", temp->fileNo, temp->memory);
        temp = temp->next;
    }
    printf("\n");
}

// Insert a new file at the front
void insertFront(int fno, int mem) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->fileNo = fno;
    newNode->memory = mem;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("File %d inserted with %d KB memory.\n", fno, mem);
    display();
}

// Delete a file from a specified position
void deleteAtPosition(int pos) {
    struct Node *temp = head;
    int i;

    if (head == NULL) {
        printf("Memory is empty. No file to delete.\n");
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    printf("File %d deleted from memory.\n", temp->fileNo);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    display();
}

// Display all files


// Main function
int main() {
    insertFront(1, 200);
    insertFront(2, 350);
    insertFront(3, 150);

    deleteAtPosition(2);
    deleteAtPosition(1);

    return 0;
}
