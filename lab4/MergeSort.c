//Program in C for Merge Sort
#include <stdio.h>
// Function prototypes for merge sort and merge
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
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
    // Call merge sort function
    mergeSort(a, 0, n - 1);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform merge sort
void mergeSort(int a[], int left, int right) 
{
    if (left < right) 
    {
        // Find the middle point
        int mid = left + (right - left) / 2;
        // Recursively sort the first and second halves
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        // Merge the sorted halves
        merge(a, left, mid, right);
    }
}
// Function to merge two halves
void merge(int a[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temporary arrays
    int L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    // Merge the temporary arrays back into a[left..right]
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = left; // Initial index of the merged subarray
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i++;
        } 
        else 
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) 
    {
        a[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) 
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
