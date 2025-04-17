//Program in C for Shell Sort
#include <stdio.h>
// Function prototype for shell sort
void shellSort(int[], int);
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
    // Call shell sort function
    shellSort(a, n);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform shell sort
void shellSort(int a[], int n) 
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        // Perform a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i++) 
        {
            // Save a[i] in temp and make a hole at position i
            int temp = a[i];
            // Shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
            {
                a[j] = a[j - gap];
            }
            // Put temp (the original a[i]) in its correct location
            a[j] = temp;
        }
    }
}
