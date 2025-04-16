//Program in C for Quick Sort
#include <stdio.h>
// Function prototypes for quick sort and partition
void quickSort(int[], int, int);
int partition(int[], int, int);
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
    // Call quick sort function
    quickSort(a, 0, n - 1);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform quick sort
void quickSort(int a[], int low, int high) 
{
    if (low < high) 
    {
        // Partition the array
        int pi = partition(a, low, high);
        // Recursively sort the sub-arrays
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
// Function to partition the array
int partition(int a[], int low, int high) 
{
    int pivot = a[high];  // Pivot element
    int i = (low - 1);    // Index of smaller element
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller than or equal to pivot
        if (a[j] <= pivot) 
        {
            i++;  // Increment index of smaller element
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}
