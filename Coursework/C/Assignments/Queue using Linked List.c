#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// i. Insertion operation of the Queue
void insert() {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &val);
    
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        // If queue is empty, both front and rear point to the new node
        front = rear = newNode;
    } else {
        // Add the new node at the end of the queue and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d into the queue.\n", val);
}

// ii. Deletion operation of the Queue
void delete() {
    if (front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next; // Move front pointer to the next node

    // If front becomes NULL, the queue is empty, so rear must also be NULL
    if (front == NULL) {
        rear = NULL;
    }
    
    free(temp); // Free the memory of the deleted node
}

// iii. Display the elements of the Queue
void display() {
    if (front == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Operations (Linked List) ---\n");
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
                // Free remaining memory
                while (front != NULL) delete(); 
                return 0;
            default: printf("Invalid choice! Please select an option between 1 and 4.\n");
        }
    }
    return 0;
}