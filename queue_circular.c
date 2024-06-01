#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int front = -1;
int rear = -1;
int CQUEUE[MAX];

void enqueue(int value);
void dequeue();
void display();
void peek();

void main() {
    int choice, value;
    do {
        printf("\t MENU\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
}

void enqueue(int value) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Circular Queue is full\n");
    } else if(front == -1) {
        front = 0;
        rear = 0;
        CQUEUE[rear] = value;
    } else if(rear == MAX - 1 && front != 0) {
        rear = 0;
        CQUEUE[rear] = value;
    } else {
        rear++;
        CQUEUE[rear] = value;
    }
}

void dequeue() {
    if(front == -1) {
        printf("Circular Queue is empty\n");
    } else if(front == rear) {
        printf("Dequeued element: %d\n", CQUEUE[front]);
        front = -1;
        rear = -1;
    } else if(front == MAX - 1) {
        printf("Dequeued element: %d\n", CQUEUE[front]);
        front = 0;
    } else {
        printf("Dequeued element: %d\n", CQUEUE[front]);
        front++;
    }
}

void display() {
    int i;
    if(front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements: ");
        if(front<  rear) {
            for(i = front; i <= rear; i++) {
                printf("%d ", CQUEUE[i]);
            }
        } else {
            for(i = front; i < MAX; i++) {
                printf("%d ", CQUEUE[i]);
            }
            for(i = 0; i <= rear; i++) {
                printf("%d ", CQUEUE[i]);
            }
        }
        printf("\n");
    }
}

void peek() {
    if(front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Front element: %d\n", CQUEUE[front]);
    }
}
