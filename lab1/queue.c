#include <stdio.h>
#include <stdlib.h>

#define maxSize 15
int array[maxSize], first = -1, last = -1;

int isfull() {
    return last == maxSize - 1;
}

int isempty() {
    return first == -1 && last == -1;
}

void enqueue(int element) {
    if (isfull()) {
        printf("Queue overflow:\n");
    } else {
        if (isempty()) {
            first = 0;
        }
        last++;
        array[last] = element;
    }
}

int dequeue() {
    int x;
    if (isempty()) {
        printf("Queue empty\n");
        return -1;
    } else {
        x = array[first];
        first++;
        if (first > last) {
            first = last = -1;
        }
    }
    return x;
}

int main() {
    int choice=0, element;
    printf("Enter 1 for enqueue, 2 for dequeue, and 10 to end:\n ");
    while (choice!=10) {
        printf("input operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                if (!isempty()) {
                    element = dequeue();
                    printf("Dequeued element: %d\n", element);
                } else {
                    printf("Cannot dequeue .Queue is empty\n");
                }
                break;
            case 10:
            printf("exiting program....\n");
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}
