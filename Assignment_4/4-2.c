#include <stdio.h>
#include <stdlib.h>

#define M 13

typedef int Marray_t[M][M];

void transposeOpt(Marray_t* A){
	int i = 0;
	int j = 0;
	int* mark = A[0][0];
	int t;
	
	do{
		do{
			t = *A[i][j];
			*A[i][j] = *mark;
			j++;
			*mark = t;
			mark += 54;
		}while(j < i);
		i++;
	}while(i < M);

	return;
}

void printArray(Marray_t* A){
	int f, g;

	printf("Marray_t A:\n");
	for(f = 0; f < M; f++){
		printf("[");
		for(g = 0; g < M; g++){
			printf(" %3d", *A[f][g]);
		}
		printf("]\n");
	}

	return;
}

Marray_t* populateArray(){
	int l, m;
	int counter = 0;

	Marray_t* A = malloc(sizeof(Marray_t));

	for(l = 0; l < M; l++){
		for(m = 0; m < M; m++){
			*A[l][m] = counter;
			counter++;
		}
	}

	return A;
}

int main(){
	
	Marray_t* A = populateArray();

	printArray(A);

	transposeOpt(A);

	printArray(A);

	free(A);

	return 0;
}