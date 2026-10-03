  struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 ; i++) {
        temp = temp->next;
    
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Inserted %d at position %d in the circular linked list.\n", data, position);
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