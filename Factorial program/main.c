#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// your code goes here

	int X, i;
	unsigned long long int Y = 1;


	printf("Please enter a valid number from 2 to 100: ");
	scanf("%d", &X);


        for ( i = 1; i <= X; i++){
            Y = Y * i;
        }
        printf("Factorial of %d is %llu.\n", X, Y);

	return 0;
}
