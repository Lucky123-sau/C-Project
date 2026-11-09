
#include <stdio.h>

int main() {
    int a, b;
    char operator;

    printf("Enter First Number: ");
    scanf("%d", &a);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter Second Number: ");
    scanf("%d", &b);

    switch (operator) {
        case '+':
            printf("Sum = %d\n", a + b);
            break;

        case '-':
            printf("Subtract = %d\n", a - b);
            break;

        case '*':
            printf("Multiply = %d\n", a * b);
            break;

        case '/':
            if (b != 0) {
                printf("Divide = %d\n", a / b);
            } else {
                printf("Error: Cannot divide by zero!\n");
            }
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
