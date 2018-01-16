#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; i++) {
		sum += u[i] * v[i];
	}
	*dest = sum;
} 

void inner2(float *u, float *v, int length, float *dest){
	int i;
	float sum = 0.0f;
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	for(i = 0; i < length - 3; i += 4){
		sum += u[i] * v[i];
		sum1 += u[i + 1] * v[i + 1];
		sum2 += u[i + 2] * v[i + 2];
		sum3 += u[i + 3] * v[i + 3];
	}
	for (; i < length; i++) {
		sum += u[i] * v[i];
	}
	*dest = sum + sum1 + sum2 + sum3;
}

float* readArray(int length){
	int i;
	float* array = malloc(sizeof(float) * length);
	for(i = 0; i < length; i++){
		array[i] = 1;
	}
	
	return array;
}

int main(){
	int len;
	printf("Array Size: ");
	scanf("%d", &len);
	float* u = readArray(len);
	float* v = readArray(len);
	float dest;
	clock_t start, end;
	float cpu_time_used;

	start = clock();
	inner(u, v, len, &dest);
	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU: %f\n", cpu_time_used);

	start = clock();
	inner2(u, v, len, &dest);
	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU: %f\n", cpu_time_used);

	free(u);
	free(v);
	return 0;
}