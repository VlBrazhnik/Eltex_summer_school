#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "dictionary.h"
#include "dict_func.h"

int ielement = 0;
int idelete = 0;

void menu(unsigned int input, struct dict* city, int dsize)
{
	switch (input)
	{
		case 1: show_list(city, dsize); break;

		case 2:	if( ielement < dsize) add_person(city, &ielement);
						else printf("Dictionary is overflow\n");
		       	break;

		case 3:	printf("Press number for: \n");
						scanf("%d\n", &idelete);
						fflush(stdin);
						delete_person(city, dsize, &idelete);
						break;

		case 4:	find_person(city, dsize);	break;

		case 5:	printf("Closing dictionary\n"); break;

		default: printf("Incorrect input, try again\n");
	}
}
