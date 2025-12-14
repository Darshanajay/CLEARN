#include <stdio.h>
#include <stdlib.h>

// Structure for Stack Node
struct Node {
    int page;
    struct Node *next;
};

// Top of the stack
struct Node *top = NULL;

// Push: visit a new web page
void push(int page) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Overflow! Cannot visit more pages.\n");
        return;
    }

    newNode->page = page;
    newNode->next = top;
    top = newNode;

    printf("Visited Page: %d\n", page);
}

// Pop: go backward
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow! No pages to go back.\n");
        return;
    }

    temp = top;
    printf("Going Back... Removed Page: %d\n", temp->page);
    top = temp->next;
    free(temp);
}

// Display stack
void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("No pages in history.\n");
        return;
    }

    printf("\n--- PAGE HISTORY (Top to Bottom) ---\n");
    temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->page);
        temp = temp->next;
    }
    printf("------------------------------------\n");
}

// Main function
int main() {
    int choice, page;

    while (1) {
        printf("\n--- WEB BROWSER ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back (Pop)\n");
        printf("3. Show Page History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Page Number to Visit: ");
                scanf("%d", &page);
                push(page);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}
