#include <stdio.h>

const int rows = 5;
const int cols = 5;

void first_task(int arr[][cols]);
void second_task();
void third_task();
void four_task();

int main() {

	int arr[rows][cols]; //for first_task check passing 2D arrays

	first_task(arr);
	second_task();
	third_task();
	four_task();

	return 0;
}

void first_task(int arr[][cols]) {

	printf("Fill square matrix\v\n");

	int count = 1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[rows][cols] = count;
			printf("%5d", arr[rows][cols]);
			count++;
		}
			printf("\n");
	}
			printf("\vFirst task completed\n");
}

void second_task() {
			int arr[rows];
			printf("\vIncreasing sequence: ");

				for (int i = 0; i < rows; i++) {
					arr[i] = (i+1);
					printf("%4d", arr[i]);
				}

			printf("\nDescending sequence: ");
				for (int i = (rows-1); i >= 0; --i) {
					printf("%4d", arr[i]);
				}
			printf("\n\vSecond task completed\n");
}

void third_task() {

		printf("\vTriangle matrix\n\v");
		int arr[rows][cols];

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					arr[i][j] = 0;
				}
				for (int k = 0; k < (cols - i); k++) {
					arr[i][k] = 1;
				}
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					printf("%5d", arr[i][j]);
				}
					printf("\n");
			}

		printf("\nThird task completed\n");
}

void four_task() {
		printf("\vSnail matrix\v\n");
		//set matrix size
		int rows = 5;
		int cols = 5;
		int arr[rows][cols];
		int count = 1;

			//cover zero
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
						arr[i][j] = 0;
				}
			}
			//fill snail matrix
			for (int start = 0; start < rows; start++) {

					for (int j = start; j < (cols - start); j++) {
							arr[start][j] = count++;
					}

					for (int i = (start + 1); i < (rows - start); i++) {
							arr[i][(cols - 1 - start)] = count++;
					}

					for (int j = (cols - 2 - start); j >= (0 + start); --j) {
							arr[rows - 1 - start][j] = count++;
					}

				for (int i = (rows - 2 - start); i > (0 + start); i--) {
							arr[i][start] = count++;
					}
			}

			//output matrix
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					printf("%5d", arr[i][j]);
				}
					printf("\n");
			}
					printf("\vFour task completed\n");

}
