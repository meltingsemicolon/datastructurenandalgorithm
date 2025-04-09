#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10 // Maximum size of the circular queue

int queue[MAX_SIZE]; // Array to store elements of the queue
int front = -1;      // Front pointer
int rear = -1;       // Rear pointer

// Function to check if the circular queue is full
int isFull()
{
    return ((rear + 1) % MAX_SIZE == front);
}

// Function to check if the circular queue is empty
int isEmpty()
{
    return (front == -1 && rear == -1);
}

// Function to enqueue an element into the circular queue
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty())
    {
        front = 0;      // For the first element
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
}

// Function to dequeue an element from the circular queue
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear)
    {
        // If there was only one element
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

// Function to display the elements of the circular queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    int i = front;
    printf("Elements of circular queue: ");
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main()
{
    int choice = 0, element;
    printf("Enter 1 for enqueue, 2 for dequeue,3 for display and 10 to end:\n ");
    while (choice != 10)
    {
        printf("input operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            if (!isEmpty())
            {
                element = dequeue();
                printf("Dequeued element: %d\n", element);
            }
            else
            {
                printf("Cannot dequeue. Queue is empty\n");
            }
            break;
        case 3:
            display();
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}
