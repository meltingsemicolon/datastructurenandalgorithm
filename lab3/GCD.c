#include <stdio.h>

// Function to find GCD using Euclidean algorithm recursively
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return findGCD(b, a % b);
}

int main() {
    int num1, num2;
    
    // Input two numbers from user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Call function to find GCD and display result
    printf("GCD of %d and %d is %d\n", num1, num2, findGCD(num1, num2));
    
    return 0;
}
