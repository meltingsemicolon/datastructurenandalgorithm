#include <stdio.h>

// Function to move disks from source to destination using auxiliary rod
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk from %c to %c\n", source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int num_disks;
    
    // Input number of disks from user
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    
    // Call the Tower of Hanoi function
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    
    return 0;
}
