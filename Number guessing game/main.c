#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for random number generator seed


int main()
{
    int randomNumber;
    int guess;
    int numberOfGuesses;
    time_t t;

    //initialization of random number generator
    srand((unsigned) time(&t));

    //get the random number
    randomNumber = rand() %21;

    printf("\n This is a guessing game.\n");
    printf(" I have a chosen a number between 0 and 20, which you must guess.\n");


    // loop for guessing the number
    for (numberOfGuesses = 5; numberOfGuesses > 0; numberOfGuesses --){
        printf("\n You have %d tr%s left.", numberOfGuesses , numberOfGuesses == 1 ? "y" : "ies");
        printf("\n Please enter a guess: ");
        scanf("%d", &guess);

        if (guess == randomNumber){
            printf("\n Congratulations. You guessed it!\n");
            break;
        }
        else if (guess > 20 || guess < 0){ //checking for invalid guess
            printf("\n I said the number is between 0 and 20.");
        }
        else if (guess < randomNumber){
            printf("\n Sorry, %d is wrong. My number is greater than that.\n", guess);
        }
        else {
            printf("\n Sorry, %d is wrong. My number is less than that.\n", guess);
        }

        if (guess != randomNumber && numberOfGuesses == 1){
        printf("\n You have had 5 tries and failed. The number was %d\n", randomNumber);
        }

    }

    return 0;
}
