//Program in C for Heap Sort
#include <stdio.h>

void heapSort(int[], int);
void heapify(int[], int, int);
void buildMaxHeap(int[], int);
void swap(int*, int*);
int main() 
{
    int n;
    int a[100], i;

    printf("Enter number of data items: \n");
    scanf("%d", &n);

    printf("Enter %d data items: \n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    printf("The data items before sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    heapSort(a, n);
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
void heapSort(int a[], int n) 
{
    buildMaxHeap(a, n);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
void buildMaxHeap(int a[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(a, n, i);
    }
}
void heapify(int a[], int n, int i) 
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
    // If left child is larger than root
    if (left < n && a[left] > a[largest]) 
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) 
    {
        largest = right;
    }
    if (largest != i) 
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
