#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// 1. Function to create a circular linked list with "n" nodes
void createCircularLinkedList(struct Node** head_ref) {
    int n,data;
    printf("How many nodes do you want to create? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }
    for (int i=1;i<=n;i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;

        if (*head_ref == NULL) {
            *head_ref = new_node;
            new_node->next = *head_ref; // Point to itself
        } else {
            struct Node* temp = *head_ref;
            // Traverse to the last node
            while (temp->next != *head_ref) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = *head_ref; // Complete the circle
        }
    }
    printf("Circular linked list created successfully.\n");
}

//Function to display the circular linked list
void displayCircularLinkedList(struct Node* head) {

    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD: %d)\n", head->data);
}

//Function to search for a node in the circular linked list
void searchNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    struct Node* temp = head;
    int position = 1;
    do {
        if (temp->data == key) {
            printf("Node with data %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    printf("Node with data %d not found in the circular linked list.\n", key);
}

//Function to insert an item at a specific position in the circular linked list
void insertAtPosition(struct Node** head_ref, int data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    // Case 1: Insert into an empty list
    if (*head_ref == NULL) {
        if (position != 1) {
            *head_ref = new_node;
            new_node->next = *head_ref; // Point to itself
            printf("Inserted %d at position 1 in the circular linked list.\n", data);
        } else {
            printf("Invalid position. The list is empty, so the only valid position is 1.\n");
            free(new_node);
        }
        return;
    }

    // Case 2: Insert at the head (position 1)
    if (position == 1) {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        new_node->next = *head_ref;
        last->next = new_node;
        *head_ref = new_node;
        printf("Inserted %d at position 1 in the circular linked list.\n", data);
        return;
    }
    
    // Case 3: Insert at a specific position (not head)
    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 ; i++) {
        temp = temp->next;
    
    if (temp == *head_ref) {
        printf("Position out of bounds. Insertion failed.\n");
        free(new_node);
        return;
    }
 }
 new_node->next = temp->next;
    temp->next = new_node;
    printf("Inserted %d at position %d in the circular linked list.\n", data, position);
}

//Function to delete a node at a specific position in the circular linked list(1-based indexing)
void deleteFromPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("The circular linked list is empty. Deletion failed.\n");
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* last = *head_ref;

    // Case 1: Delete the head node (position 1)
        if (position ==1) {
            // Find the last node to update its next pointer
            while (last->next != *head_ref) {
                last = last->next;
            }

            // If there's only one node in the list
            if (last == *head_ref) {
                *head_ref = NULL;
            } else {
                *head_ref = temp->next; //This updates the head in main()
                last->next = *head_ref; //Relink the circle
                
            }
            free(temp);
            printf("Deleted node at position 1 from the circular linked list.\n");
            return;
        }

        // Case 2: Delete a node at a specific position (not head)
        struct Node* prev = NULL;
        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == *head_ref) {
                printf("Position out of bounds. Deletion failed.\n");
                return;
            }
        }
        prev->next = temp->next;
        printf("Deleted node at position %d with value %d from the circular linked list.\n", position, temp->data);
        free(temp);
    


}

int main () {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
        printf("3. Search for a Node\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createCircularLinkedList(&head);
                break;
            case 2:
                displayCircularLinkedList(head);
                break;
            case 3:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                printf("Enter the position to delete from(1-based index): ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}