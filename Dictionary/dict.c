#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "dict_func.h"
#include "int-input.h"

int main()
{
	int dsize = 10;
	int exit_prog = 5; // the number last function
	struct dict city[dsize];
	unsigned int input = 0;
	cover_zero(city, dsize);

	printf("Hello user, this is Dictionary to SIZE = %d\n", dsize);

	while (input != exit_prog) {

			printf("\nPress number for:\n1)Show all dictionary");
			printf("\n2)Add_person");
			printf("\n3)Delete_person");
			printf("\n4)Find person\n");
			printf("5)EXIT\n");
			getIntegerFromStdin(&input);
			menu(input, city, dsize);
	}

	return 0;
}
