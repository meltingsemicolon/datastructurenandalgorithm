//  stack implementation
#include <stdio.h>
int top = -1;
void push(int stx[], int x)
{
    top++;
    stx[top] = x;
}
void pop(int arr[])
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
        arr[i] = NULL;
        top--;
    }
}

int main()
{
    int num, size;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    int stack[size];
    printf("Give input to stack: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &num);
        push(stack, num);
    }
    printf("Removing from stack:\n");
    pop(stack);

    return 0;
}