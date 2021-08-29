#include "dictionary.h"
#include "dict_func.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void cover_zero(struct dict *city, int dsize) {

	for (int i = 0; i < dsize; i++)
	{
		memcpy(city[i].full_name, "empty", 6);
		memcpy(city[i].address, "empty", 6);
		memcpy(city[i].phone_num, "empty", 6);
	}
}

char *trim_str(char *str) {
		char *ptr;
		if(!str)
				return NULL;
		if(!*str)
				return str;
		for (ptr = str + strlen(str) - 1; (ptr >= str) && isspace(*ptr); --ptr);
		ptr[1] = '\0';
		return str;
}

void show_list(struct dict *city, int dsize) {

		printf("___________\n");

	for (int i = 0; i < dsize; i++){

		printf("%d) person\n", i);

		printf("FIO: %s\n", city[i].full_name);

		printf("Address: %s\n", city[i].address);

		printf("Phone_number:%s\n\v", city[i].phone_num);

		printf("___________\n");
	}
}

void add_person(struct dict *city, int *i) {

				printf("You decide add person\n");

				printf("Enter full_name: ");
				fgets(city[*i].full_name, sizeof(city[*i].full_name), stdin);
				fflush(stdin);
				trim_str(city[(*i)].full_name);

				printf("Enter the address: ");
				fgets(city[*i].address, sizeof(city[*i].address), stdin);
				fflush(stdin);
				trim_str(city[*i].address);

				printf("Enter the phone number: ");
				fgets(city[*i].phone_num, sizeof(city[*i].phone_num), stdin);
				fflush(stdin);
				trim_str(city[*i].phone_num);

				(*i)++;
}

void delete_person(struct dict *city, int dsize, int *idelete){

		printf("Yout decide delete person.Enter number person: \n");

		for( ;(*idelete) < (dsize--); (*idelete)++) {

			strcpy(city[*idelete].full_name, city[(*idelete) + 1].full_name);
			strcpy(city[*idelete].address, city[(*idelete) + 1].address);
			strcpy(city[*idelete].phone_num, city[(*idelete) + 1].phone_num);

		}

		memcpy(city[*idelete].full_name, "empty", 6);
		memcpy(city[*idelete].address, "empty", 6);
		memcpy(city[*idelete].phone_num, "empty", 6);

		printf("Press a number for: \n");
	}

void find_person(struct dict *city, int dsize) {

		const int max_size = 30;
		int not_found = 1;
		char str[max_size];

		printf("Enter a data about person(Name, address, phone number):\n");
		fgets(str, max_size, stdin);

			while(not_found)
			{
					for (int i = 0; i < dsize; i++) {

							if (strcmp(str, city[i].full_name) == 0)
							{
								not_found = 0; // we found Add_person

								printf("___________\n");
								printf("%d) person\n", i);
								printf("FIO: %s\n", city[i].full_name);
								printf("Address: %s\n", city[i].address);
								printf("Phone_number:%s\n\v", city[i].phone_num);
								printf("___________\n");
							}

							if (strcmp(str, city[i].address) == 0 && not_found == 1)
							{
								not_found = 0; // we found Add_person

								printf("___________\n");
								printf("%d) person\n", i);
								printf("FIO: %s\n", city[i].full_name);
								printf("Address: %s\n", city[i].address);
								printf("Phone_number:%s\n\v", city[i].phone_num);
								printf("___________\n");
							}

							if (strcmp(str, city[i].phone_num) == 0 && not_found == 1)
							{
								not_found = 0; // we found Add_person

								printf("___________\n");
								printf("%d) person\n", i);
								printf("FIO: %s\n", city[i].full_name);
								printf("Address: %s\n", city[i].address);
								printf("Phone_number:%s\n\v", city[i].phone_num);
								printf("___________\n");
							}
					}

							if (not_found == 1)
							{
								printf("Not found a person in Dictionary\n");
							}

			}
}
