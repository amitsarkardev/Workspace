#include <stdio.h>
#include <stdlib.h>

//Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

//1. Function to create a linked list with n nodes
void createList(struct Node** head_ref) {
    int n,data;
    printf("Enter the number of nodes: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }

    //If list already exists, warn the user (for simplicity, we just append or build new if empty)
    if(*head_ref != NULL) {
        printf("Warning: The list already exists. New nodes will be appended.\n");
    }

    struct Node* temp = *head_ref;
    //If the list has items, traverse to the last node
    while(temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    
    for(int i = 0; i <= n; i++){
        printf("Enter data for node %d: ",i);
        scanf("%d", &data);

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        if (*head_ref == NULL) {
            *head_ref = new_node; // If list is empty, new node becomes head
            temp = new_node;
        } else {
            temp->next = new_node; // Append to the end of the list
            temp = new_node;
        }
    }
    printf("Linked list created successfully.\n");
}

//2. Function to search for an item
void searchItem(struct Node* head, int key) {
    int pos=1;
    struct Node* temp=head;

    while(temp!=NULL) {
        if(temp->data==key) {
            printf("Item %d found at position %d.\n", key, pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    printf("Item %d not found in the list.\n", key);
}

//3. Function to display the linked list
void displayList(struct Node* head) {
    if(head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//4. Function to insert an item at a specific position (1 based index)
void insertAtPosition(struct Node** head_ref, int data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    // Case 1: Insert at the head (position 1)
    if(position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }
    
    // Case 2: Insert at a position other than the head
    struct Node* temp = *head_ref;
    for (int i=1; i<position-1 && temp!=NULL; i++) {
        temp = temp->next;
    }
    
    //If postion is greater than the number of nodes +1
    if (temp == NULL) {
        printf("Position %d is out of bounds. Cannot insert.\n", position);
        free(new_node);
    }
    else {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Inserted %d at position %d.\n", data, position);
    }
}

//5. Function to delete an item at a specific position (1 based index)
void deletefromPositon(struct Node** head_ref, int position) {
    if(*head_ref == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // Case 1: Delete the head node
    if(position == 1) {
        *head_ref = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted node at position %d.\n", position);
        return;
    }

    // Case 2: Delete a node from middle or end
    //Find the previous node of the node to be deleted
    for(int i=1; temp!=NULL && i<position-1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if(temp == NULL || temp->next == NULL) {
        printf("Position %d is out of bounds. Cannot delete.\n", position);
        return;
    }

    // temp->next is the node to be deleted
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // Unlink the node from linked list
    free(nodeToDelete); // Free memory
    printf("Deleted node at position %d.\n", position);
}

int main() {
    struct Node* head = NULL;
    int choice,data,position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Create/Add to Linked List\n");
        printf("2. Search for an Item\n");
        printf("3. Display Linked List\n");
        printf("4. Insert an Item at Particular Position\n");
        printf("5. Delete an Item from Particular Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            // Clear the input buffer
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                printf("Enter item to search: ");
                scanf("%d", &data);
                searchItem(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at(1-based index): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                printf("Enter position to delete from(1-based index): ");
                scanf("%d", &position);
                deletefromPositon(&head, position);
                break;
            case 6:
                printf("Exiting program.\n");
                // Free the linked list before exiting
                while(head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}