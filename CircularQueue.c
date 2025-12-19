#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
int cqueue[MAX];
int rear = 0;
int front = 0;
bool isEmpty() {
    return front == rear ;
}
bool isFull() {
    return (rear + 1) % MAX == front;
}
void enqueue() {
    int item;
    if (isFull()) {
        printf("\nQueue Overflow.Cannot insert\n");
    } else {
        printf("Insert the element in queue : ");
        scanf("%d", &item);
        rear = (rear + 1) % MAX;
        cqueue[rear] = item;
        printf("Enqueued element: %d\n", item);
    }
}
void dequeue() {
    if(isEmpty()) {
        printf("Queue Underflow.Cannot delete.\n");
        return;
    } else {
        front = (front + 1) % MAX;
        printf("Element deleted from queue is : %d\n", cqueue[front]);
    }
}
void display() {
    int i;
    if (isEmpty() ) {
        printf("Queue is empty \n");
    } else { 
        printf("Queue is : ");
        for (i = (front + 1) % MAX; i != (rear + 1) % MAX; i = (i + 1) % MAX) {
            printf("%d ", cqueue[i]);
        }
        printf("\n");
    }
}
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1; 
    } else {
        return cqueue[(front + 1) % MAX];
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert element to queue ");
        printf("\n2. Delete element from queue ");
        printf("\n3. Display all elements of queue");
        printf("\n4. Peek ");
        printf("\n5. Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                {
                    int x = peek();
                    if(x != -1) {
                        printf("Front element is: %d\n", x);
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong choice \n");
        }
    }
    return 0;
}