//Program in C for Selection Sort
#include <stdio.h>
// Function prototype for selection sort
void selectionSort(int[], int);
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
    // Call selection sort function
    selectionSort(a, n);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform selection sort
void selectionSort(int a[], int n) 
{
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) 
    {
        // Assume the minimum is the first element
        minIndex = i;
        // Test against elements after i to find the smallest
        for (j = i + 1; j < n; j++) 
        {
            // If this element is less, then it is the new minimum
            if (a[j] < a[minIndex]) 
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) 
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}
