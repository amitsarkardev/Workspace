#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// i. Insertion operation
void insert() {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &val);
    newNode->data = val;
    
    if (front == NULL) {
        // First node: front and rear point to it, and it points to itself
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        // Link new node at the end, and loop it back to the front
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Inserted %d into the circular queue.\n", val);
}

// ii. Deletion operation
void delete() {
    if (front == NULL) {
        printf("Queue Underflow! The circular queue is empty.\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Deleted element: %d\n", temp->data);
    
    if (front == rear) {
        // Only one node exists
        front = NULL;
        rear = NULL;
    } else {
        // Move front forward and update rear's link
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

// iii. Display the elements
void display() {
    if (front == NULL) {
        printf("The circular queue is empty.\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Circular Queue elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front); // Stop when we wrap back around to the front
    
    printf("(HEAD: %d)\n", front->data);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Operations (Linked List) ---\n");
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
            case 4: 
                while (front != NULL) {
                    // Free memory before exiting
                    delete(); 
                    if (front == NULL) break;
                }
                return 0;
            default: printf("Invalid choice! Please select 1-4.\n");
        }
    }
    return 0;
}