//Program in C for Binary Search
#include <stdio.h>
// Function prototype for binary search
int binarySearch(int[], int, int, int);
int main() 
{
    int n, key;
    int a[100], i;
    // Input number of data items
    printf("Enter number of data items: \n");
    scanf("%d", &n);
    // Input data items (sorted)
    printf("Enter %d sorted data items: \n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    // Input the key to search
    printf("Enter the key to search: \n");
    scanf("%d", &key);
    // Perform binary search
    int result = binarySearch(a, 0, n - 1, key);
    // Print the result
    if (result == -1) 
    {
        printf("Key not found\n");
    } 
    else 
    {
        printf("Key found at index: %d\n", result);
    }
    return 0;
}
// Function to perform binary search
int binarySearch(int a[], int left, int right, int key) 
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        // Check if key is present at mid
        if (a[mid] == key) 
        {
            return mid;
        }
        // If key greater, ignore left half
        if (a[mid] < key) 
        {
            left = mid + 1;
        }
        // If key is smaller, ignore right half
        else 
        {
            right = mid - 1;
        }
    }
    // Key not found
    return -1;
}
