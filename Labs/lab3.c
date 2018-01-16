/*
int a = 7;
int *b = &a;	//&a -> 0xX		*a -> ?
b -> 0xX
*b -> 7
&b -> 0xX
*/

#include <stdio.h>
#include <stdlib.h>

//#define SIZE 500000000

/*
int main(){

	int a = 7;
	int* b = &a;

	printf("*b = %d\n", b[0]);

	return 0;
}
*/
/*
void printArray(int* a, int SIZE){
	int i;
	for(i=0; i<SIZE; i++){
		printf("a[%d] = %d\n", i, *(a+i));
	}

	return;
}

int main(){

	int SIZE = 20;

	//int a[SIZE];
	int* a = malloc(sizeof(int) * SIZE);

	int i;
	for(i=0; i< SIZE; i++){
		a[i] = i;
	}

	//for(i=0; i<5; i++){
	//	printf("a[%d] = %d\n", i, a[i]);
	//}

	//printf("a = 0x%X\n", a);

	//printf("&a[0] = 0x%X\n", &a[0]);

	//printf("a+1 = 0x%X\n", a+1); // a + 1( * sizeof(int))

	//printf("*a = %d\n", *a);

	//printf("*(a+1) = %d\n", *(a+1));

	printArray(a, SIZE);

	free(a);	// always free when using malloc

	return 0;
}
*/

void swap(int* a, int* b){

	*a ^= *b;
	*b ^= *a;
	*a ^= *b;

	return;
}

int main(){

	int a = 2;
	int b = 5;

	printf("a = %d, b = %d\n", a, b);

	swap(&a, &b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}

// gcc lab3.c -S -m32 -01 to check answers

/*
int main(){

	int size;

	printf("Enter size:\n");
	scanf("%d", &size);

	printf("you entered: %d\n", size);

	return 0;
}
*/