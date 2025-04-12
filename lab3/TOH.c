#include <stdio.h>

void towerofHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk from %c to %c ", source, destination);
    }
    towerofHanoi(n - 1, source, auxiliary, destination);
    printf("move disk from %c to %c \n", source, destination);
    towerofHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int num_disks;
    printf("Enter numver of disks: ");
    scanf("%d",&num_disks);
    towerofHanoi(num_disks,'a','c','b');
    return 0;
}
