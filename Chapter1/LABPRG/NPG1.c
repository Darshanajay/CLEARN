#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char usn[20];
    char dept[20];
    int marks;
} Student;

// ---- Simple Add Record Function ----
void addRecord(Student *s, int *count)
{
    printf("Enter Name: ");
    scanf("%s", s[*count].name);

    printf("Enter USN: ");
    scanf("%s", s[*count].usn);

    printf("Enter Department: ");
    scanf("%s", s[*count].dept);

    printf("Enter Total Marks: ");
    scanf("%d", &s[*count].marks);

    (*count)++;

    printf("Record Added Successfully!\n");
}

// ---- Display Function ----
void displayRecords(Student *s, int count)
{
    if (count == 0) {
        printf("No Records Available.\n");
        return;
    }

    printf("\n----- STUDENT RECORDS -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | USN: %s | Dept: %s | Marks: %d\n",
               i + 1, s[i].name, s[i].usn, s[i].dept, s[i].marks);
    }
}

// ---- Search by USN Function ----
void searchRecord(Student *s, int count)
{
    if (count == 0) {
        printf("No Records to Search.\n");
        return;
    }

    char searchUSN[20];
    printf("Enter USN to search: ");
    scanf("%s", searchUSN);

    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].usn, searchUSN) == 0) {
            printf("\nRecord Found!\n");
            printf("Name: %s\nUSN: %s\nDept: %s\nMarks: %d\n",
                   s[i].name, s[i].usn, s[i].dept, s[i].marks);
            return;
        }
    }

    printf("No Record Found with USN %s\n", searchUSN);
}

// ---- Main Function ----
int main()
{
    int choice;
    int count = 0;

    Student *list = malloc(100 * sizeof(Student)); // dynamic memory

    while (1) {
        printf("\n----- STUDENT RECORD SYSTEM -----\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search by USN\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addRecord(list, &count);
                break;

            case 2:
                displayRecords(list, count);
                break;

            case 3:
                searchRecord(list, count);
                break;

            case 4:
                printf("Exiting...\n");
                free(list);
                exit(0);

            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}
