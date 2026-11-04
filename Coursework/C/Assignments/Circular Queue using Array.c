#include <stdio.h>

#define MAX 5 // Small size to easily demonstrate circular wrapping

int queue[MAX];
int front = -1;
int rear = -1;

// i. Insertion operation
void insert() {
    int val;
    // Check if the queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Circular queue is full.\n");
        return;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &val);
    
    if (front == -1) { // Inserting the first element
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; // Circular increment
    }
    queue[rear] = val;
    printf("Inserted %d into the circular queue.\n", val);
}

// ii. Deletion operation
void delete() {
    if (front == -1) {
        printf("Queue Underflow! The circular queue is empty.\n");
        return;
    }
    
    printf("Deleted element: %d\n", queue[front]);
    
    if (front == rear) { 
        // If it was the only element in the queue, reset
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; // Circular increment
    }
}

// iii. Display the elements
void display() {
    if (front == -1) {
        printf("The circular queue is empty.\n");
        return;
    }
    
    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break; // Stop after printing the rear element
        }
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Operations (Array) ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Please select 1-4.\n");
        }
    }
    return 0;
}