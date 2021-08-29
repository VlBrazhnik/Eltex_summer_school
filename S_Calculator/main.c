#include <stdio.h>
#include "pfunc.h"

int main() {
	int input = 0;
	float first = 0;
	float second = 0;

	printf("Welcome to a calculator!\n");

	do {
		
		printf("Enter two numbers:\n ");
		scanf("%f %f", &first, &second);
		printf("You've entered %f and %f\n", first, second);

		menu();
		scanf("%d", &input);

		switch (input) {

			case 1: printf("a + b = %f\n", add(first, second));
				break;

			case 2: printf("a - b = %f\n", sub(first, second));
				break;

			case 3: printf("a * b = %f\n", mult(first, second));
				break;

			case 4: printf("a / b = %f\n", div(first, second));
				break;

			case 5: printf("Closing a calculator\n");
				break;

			default: printf("[ERROR]: Incorrect input, please, try again\n");
				break;
		}
	} while(input != 5);

	return 0;
}
