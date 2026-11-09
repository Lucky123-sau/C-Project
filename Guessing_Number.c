
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;
    int attempts = 0;

    srand(time(0));
    secretNumber = rand() % 100 + 1;

    printf("=================================\n");
    printf("     NUMBER GUESSING GAME\n");
    printf("=================================\n");
    printf("Guess a number between 1 and 100.\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > secretNumber) {
            printf("Too high! Try a lower number.\n");
        }
        else if (guess < secretNumber) {
            printf("Too low! Try a higher number.\n");
        }
        else {
            printf("\nCongratulations! You guessed it!\n");
            printf("Secret number: %d\n", secretNumber);
            printf("Total attempts: %d\n", attempts);
        }

    } while (guess != secretNumber);

    printf("Thanks for playing!\n");

    return 0;
}
