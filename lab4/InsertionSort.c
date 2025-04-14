//Program in C for Insertion Sort
#include <stdio.h>
// Function prototype for insertion sort
void insertionSort(int[], int);
int main() 
{
    int n;
    int a[100], i;
    // Input number of data items
    printf("Enter number of data items: \n");
    scanf("%d", &n);
    // Input data items
    printf("Enter %d data items: \n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    // Display data items before sorting
    printf("The data items before sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    // Call insertion sort function
    insertionSort(a, n);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform insertion sort
void insertionSort(int a[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = a[i];
        j = i - 1;
        // Move elements of a[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while ((j >= 0) && (a[j] > key)) 
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
