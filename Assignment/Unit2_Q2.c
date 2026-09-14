/* A service centre uses a fixed-size request buffer in which released positions must be reused.
Write a C program to implement a Circular Queue using an array with insertion, deletion, display,
overflow and underflow operations. Demonstrate that positions freed after deletion can be reused
for new requests. */

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d inserted\n", value);
}

void delete() {
    int value;

    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    value = queue[front];
    printf("%d deleted\n", value);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    delete();
    delete();

    display();

    insert(60);
    insert(70);

    display();

    insert(80);

    return 0;
}