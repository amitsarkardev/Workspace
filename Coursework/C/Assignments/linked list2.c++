#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class to handle operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // 1. Create a linked list (appends n nodes)
    void createList() {
        int n, val;
        cout << "How many nodes do you want to create? ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid number of nodes." << endl;
            return;
        }

        for (int i = 1; i <= n; i++) {
            cout << "Enter data for node " << i << ": ";
            cin >> val;

            Node* newNode = new Node(val);

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        cout << "Linked list updated successfully." << endl;
    }

    // 2. Search an item in the linked list
    void searchItem() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        int key;
        cout << "Enter the value to search: ";
        cin >> key;

        Node* temp = head;
        int pos = 1;
        bool found = false;

        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Item " << key << " found at position " << pos << "." << endl;
                found = true;
                break;
            }
            temp = temp->next;
            pos++;
        }

        if (!found) {
            cout << "Item " << key << " not found in the list." << endl;
        }
    }

    // 3. Display the items on the linked list
    void displayList() {
        if (head == nullptr) {
            cout << "The linked list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 4. Insert an item at a particular position (1-based index)
    void insertAtPosition() {
        int val, pos;
        cout << "Enter the value to insert: ";
        cin >> val;
        cout << "Enter the position to insert at (1-based index): ";
        cin >> pos;

        if (pos < 1) {
            cout << "Invalid position. Position must be >= 1." << endl;
            return;
        }

        Node* newNode = new Node(val);

        // Case 1: Insert at the beginning (Position 1)
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << val << " at position 1." << endl;
            return;
        }

        // Case 2: Insert at middle or end
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // If the position is greater than the number of nodes + 1
        if (temp == nullptr) {
            cout << "Position out of bounds. Insertion failed." << endl;
            delete newNode; // Avoid memory leak
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " at position " << pos << "." << endl;
        }
    }

    // 5. Delete an item from a particular position (1-based index)
    void deleteFromPosition() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        int pos;
        cout << "Enter the position to delete from (1-based index): ";
        cin >> pos;

        if (pos < 1) {
            cout << "Invalid position. Position must be >= 1." << endl;
            return;
        }

        Node* temp = head;

        // Case 1: Delete from the beginning (Position 1)
        if (pos == 1) {
            head = temp->next;
            cout << "Deleted node with value " << temp->data << " from position 1." << endl;
            delete temp;
            return;
        }

        // Case 2: Delete from middle or end
        Node* prev = nullptr;
        for (int i = 1; i < pos && temp != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }

        // If the position is greater than the number of nodes
        if (temp == nullptr) {
            cout << "Position out of bounds. Deletion failed." << endl;
            return;
        }

        // Unlink the node and delete it
        prev->next = temp->next;
        cout << "Deleted node with value " << temp->data << " from position " << pos << "." << endl;
        delete temp;
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\n--- Linked List Operations Menu ---" << endl;
        cout << "1. Create / Add to linked list" << endl;
        cout << "2. Search for an item" << endl;
        cout << "3. Display the linked list" << endl;
        cout << "4. Insert an item at a particular position" << endl;
        cout << "5. Delete an item from a particular position" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            // Handle invalid non-integer input
            cout << "Invalid input. Exiting..." << endl;
            break;
        }

        switch (choice) {
            case 1:
                list.createList();
                break;
            case 2:
                list.searchItem();
                break;
            case 3:
                list.displayList();
                break;
            case 4:
                list.insertAtPosition();
                break;
            case 5:
                list.deleteFromPosition();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please select an option between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}