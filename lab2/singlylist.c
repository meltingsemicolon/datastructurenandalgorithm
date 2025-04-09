// implementation of singly linklist
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d &(%d) ", head->data,head->next);
        head = head->next;
    }
    printf("\n");
}

// Function to delete the entire linked list
void deleteList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL; // Set the head to NULL after deleting all nodes
}

int main()
{
    // Initialize an empty linked list
    struct Node *head = NULL;
    int num, n = 5;
    printf("Enter element : ");
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            insertAtEnd(&head, num);
        }
    }
    // Insert elements into the linked list
    // insertAtEnd(&head, 112);
    // insertAtEnd(&head, 221);
    // insertAtEnd(&head, 371);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete the linked list
    deleteList(&head);

    return 0;
}
