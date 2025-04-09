// DMA in C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray;
    int size=0, newSize=0;

    // Get initial size of the array from the user
    printf("Enter the initial size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the dynamic array
    dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }

    // Input values into the array
    printf("Enter %d elements into the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Print the original array
    printf("Original Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Get the new size for the array from the user
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);

    // Resize the array using realloc
    dynamicArray = (int *)realloc(dynamicArray, newSize * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Memory reallocation failed.\n");
        return 1; // Exit the program with an error code
    }

    // Input values into the resized array
    printf("Enter %d elements into the resized array:\n", (newSize-size));
    for (int i = size; i < newSize; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Print the resized array
    printf("Resized Array:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Free the memory allocated for the dynamic array
    free(dynamicArray);

    return 0;
}
