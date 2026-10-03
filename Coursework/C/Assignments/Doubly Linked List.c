#include <stdio.h>
#include <stdlib.h>

//Define structure for a doubly Linked List Node
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

//Create the Doubly Linked List
void createDoublyLinkedList(struct Node** head_ref){
    int n,data;
    printf("Enter the number of nodes to create: ");
    if(scanf("%d", &n)!= 1 || n<= 0){
        printf("Invalid number of nodes. Please enter a positive integer.\n");
        return;
    }

    struct Node* temp= *head_ref;
    if(temp!=NULL){
    while(temp->next!=NULL){
        temp=temp->next;
        }
    }
    for (int i=1;i<=n;i++){
    printf("Enter data for node %d: ",i);
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    if(*head_ref ==NULL){
        *head_ref=newNode;
        temp=newNode;
    }
    else{
        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
        }
    }
    printf("Doubly Linked List created successfully.\n");
}

//Search for an item in the Doubly Linked List
void searchItem(struct Node* head,int key){
    if(head==NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    int pos=1;
    while(temp!=NULL){
        if(temp->data == key){
            printf("Item %d found at position %d. \n", key,pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Item %d not found in the Doubly Linked List.\n",key);
}

//Display the items in the Doubly Linked List
void displayList(struct Node* head) {
    if (head==NULL){
        printf("The Doubly Linked List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: NULL <->");
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Insert an item at a particular position (1 based index)
void insertAtPosition(struct Node** head_ref, int data, int pos){
    if(pos<1){
        printf("Invalid position! Position must be >=1. \n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    
    //Case 1: Insert at the beginnning (Position 1)
    if (pos ==1){
        newNode->next= *head_ref;
        if(*head_ref !=NULL) {
            (*head_ref)->prev = newNode;
        }
        *head_ref = newNode;
        printf("Inserted %d at position 1. \n",data);
        return;
    }
    
    //Case 2: Insert at the middle or end
    struct Node* temp= *head_ref;
    for (int i=1;i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Position out of bounds! Insertion failed.\n");
        free(newNode);
        return;
    }

    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;

    printf("Inserted %d at postion %d.\n",data,pos);
}

//Delete an item from a particular position(1 based index)
void deleteByPosition(struct Node** head_ref, int pos){
    if (*head_ref ==NULL){
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    if(pos<1){
        printf("Invalid position!\n");
        return;
    }

    struct Node* temp= *head_ref;

    //Case 1: Delete the first node (Position 1)
    if(pos == 1) {
        *head_ref = temp->next;
        if(*head_ref!=NULL){
            (*head_ref)->prev=NULL;
        }
        printf("Deleted element %d from position 1.\n",temp->data);
        free(temp);
        return;
    }

    //Traverse to the node to be deleted
    for(int i=1;i<pos && temp!=NULL; i++){
        temp=temp->next;
    }

    if(temp == NULL){
        printf("Position out of bounds! Deletion failed.\n");
        return;
    }

    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next = temp->next;
    }

    printf("Deleted element %d from position %d.\n", temp->data, pos);
    free(temp);
}

//Delete a specific element by value
void deleteByValue(struct Node** head_ref,int key){
    if (*head_ref ==NULL){
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head_ref;

    //Search for the node with the given value
    int pos=1;
    while (temp!=NULL && temp->data!=key){
        temp = temp->next;
        pos++;
    }
    
    if (temp == NULL){
        printf("Element %d not found in the list.\n",key);
        return;
    }

    //If Node to be deleted is the head node
    if (*head_ref == temp){
        *head_ref = temp->next;
    }

    // Update next node's prev pointer
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }

    // Update prev node's next pointer
    if(temp->prev !=NULL){
        temp->prev->next=temp->next;
    }

    printf("Deleted element %d (found at position %d).\n", key, pos);
    free(temp);
}

// Menu using switch case
int main(){
    struct Node* head = NULL;
    int choice,data,pos;

    while(1){
        printf("\n Doubly Linked List Menu Operations \n");
        printf("1. Create Doubly Linked List \n");
        printf("2. Search for an item \n");
        printf("3. Display the Doubly Linked List \n");
        printf("4. Insert an item at a particular position \n");
        printf("5. Delete an item by position \n");
        printf("6. Delete an item by value \n");
        printf("7. Exit \n");
        printf("\n Enter your choice: ");

        if(scanf("%d", &choice)!=1){
            printf("Invalid input. Exiting.... \n");
            break;
        }

        switch (choice) {
            case 1:
                createDoublyLinkedList(&head);
                break;
            case 2:
                printf("Enter the item to search: ");
                scanf("%d", &data);
                searchItem(head,data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position (1-based index): ");
                scanf("%d",&pos);
                insertAtPosition(&head,data,pos);
                break;
            case 5:
                printf("Enter the position to delete (1-based index): ");
                scanf("%d", &pos);
                deleteByPosition(&head,pos);
                break;
            case 6:
                printf("Enter the element (value) to delete: ");
                scanf("%d",&data);
                deleteByValue(&head,data);
                break;
            case 7:
                printf("Exiting Program...\n");
                while(head!=NULL){
                    struct Node* temp=head;
                    head=head->next;
                    free(temp);
                }       
                return 0;
            default:
                printf("Invalid Choice! Please select 1-7. \n");

        }
    }
    return 0;
}