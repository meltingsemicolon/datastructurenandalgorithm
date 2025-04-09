#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself to make it circular
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) { // Traverse until you reach the last node
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head; // Make the new node point back to the head to make it circular
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

// Function to delete the entire linked list
void deleteList(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* current = *head;
    struct Node* next;

    while (current->next != *head) { // Traverse until you reach the head again
        next = current->next;
        free(current);
        current = next;
    }
    free(current); // Free the last node
    *head = NULL; // Set the head to NULL after deleting all nodes
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 112);
    insertAtEnd(&head, 221);
    insertAtEnd(&head, 371);

    // Print the linked list
    printf(" circular Linked List: ");
    printList(head);

    // Delete the linked list
    deleteList(&head);

    return 0;
}
