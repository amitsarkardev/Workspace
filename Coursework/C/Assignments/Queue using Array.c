#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// i. Insertion operation of the Queue
void insert() {
    int val;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert more elements.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter the element to insert: ");
        scanf("%d", &val);
        rear++;
        queue[rear] = val;
        printf("Inserted %d into the queue.\n", val);
    }
}

// ii. Deletion operation of the Queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! The queue is empty.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        
        // Reset the queue if it becomes empty after deletion
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// iii. Display the elements of the Queue
void display() {
    if (front == -1 || front > rear) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Operations (Array) ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: 
                printf("Exiting program...\n"); 
                return 0;
            default: printf("Invalid choice! Please select an option between 1 and 4.\n");
        }
    }
    return 0;
}