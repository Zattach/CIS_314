
#include<stdio.h>
#include <stdlib.h>

// allocates an array using input from user
int* readArray(int length){

	int i;
	int* array = malloc(sizeof(int) * length);

	for(i = 0; i < length; i++){
		printf("Enter array[%d]: ", i);
		scanf("%d", (array + i));
	}
	
	return array;
}

// swaps the values given
void swap(int *xp, int *yp){

	int var = *yp;
	*yp = *xp;
	*xp = var;

	return;
}

// Uses Selection Sort to sort the array, use swap
void sortArray(int* array, int length){

	int i;
	int j;
	int min;

	for(i = 0; i < length - 1; i++){
		min = i;
		for(j = i + 1; j < length; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		swap(&array[min], &array[i]);
	}

	return;
}

// prints the array: [1, 3, 5, 7]
void printArray(int* array, int length){

	int i;

	printf("[");
	for(i = 0; i < (length - 1); i++){
		printf("%d, ", *(array + i));
	}

	printf("%d]\n", *(array + (length - 1)));

	return;
}

// takes in the length of the array, calls other functions
int main(){
	int length;

	printf("Enter the length: ");
	scanf("%d", &length);

	int* array = readArray(length);

	sortArray(array, length);

	printArray(array, length);

	free(array);

	return 0;
}