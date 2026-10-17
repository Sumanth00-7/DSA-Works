/*Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a
user. The program should insert a new page, move forward and backward, delete a specified
page, and display the pages from first-to-last and last-to-first while handling beginning and end
conditions correctly.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertPage(char page[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    printf("Page \"%s\" inserted.\n", page);
}

void moveForward() {
    static struct Node *current = NULL;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    if (current == NULL)
        current = head;
    else if (current->next != NULL)
        current = current->next;
    else {
        printf("Already at the last page.\n");
        return;
    }

    printf("Current page: %s\n", current->page);
}

void moveBackward() {
    static struct Node *current = NULL;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    if (current == NULL)
        current = tail;
    else if (current->prev != NULL)
        current = current->prev;
    else {
        printf("Already at the first page.\n");
        return;
    }

    printf("Current page: %s\n", current->page);
}

void deletePage(char page[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Page \"%s\" is not available.\n", page);
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp == tail)
        tail = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Page \"%s\" deleted.\n", page);
}

void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    printf("Pages (First to Last):\n");

    while (temp != NULL) {
        printf("%s", temp->page);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

void displayBackward() {
    struct Node *temp = tail;

    if (tail == NULL) {
        printf("No pages available.\n");
        return;
    }

    printf("Pages (Last to First):\n");

    while (temp != NULL) {
        printf("%s", temp->page);

        if (temp->prev != NULL)
            printf(" -> ");

        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    int choice;
    char page[100];

    while (1) {
        printf("\n--- Web Page History ---\n");
        printf("1. Insert New Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter page name/URL: ");
                scanf("%99s", page);
                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%99s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
