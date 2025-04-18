//Program in C for Radix Sort
#include <stdio.h>
// Function prototypes for radix sort, counting sort, and utility functions
void radixSort(int[], int);
void countingSort(int[], int, int);
int getMax(int[], int);
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
    // Call radix sort function
    radixSort(a, n);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform radix sort
void radixSort(int a[], int n) 
{
    // Find the maximum number to determine the number of digits
    int max = getMax(a, n);
    // Do counting sort for every digit. Note that instead of passing the digit number,
    // exp is passed. exp is 10^i where i is the current digit number.
    for (int exp = 1; max / exp > 0; exp *= 10) 
    {
        countingSort(a, n, exp);
    }
}
// Function to get the maximum value in an array
int getMax(int a[], int n) 
{
    int max = a[0];
    for (int i = 1; i < n; i++) 
    {
        if (a[i] > max) 
        {
            max = a[i];
        }
    }
    return max;
}
// Function to perform counting sort based on the digit represented by exp
void countingSort(int a[], int n, int exp) 
{
    int output[n]; // Output array
    int count[10] = {0}; // Initialize count array as 0
    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) 
    {
        count[(a[i] / exp) % 10]++;
    }
    // Change count[i] so that it contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) 
    {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    // Copy the output array to a[], so that a[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) 
    {
        a[i] = output[i];
    }
}
