
// REMEMBER TO COMPILE USING "gcc -o test test.c"
// This will give the result in the form of "test"

#include <stdio.h>

typedef unsigned char * byte_pointers;



/*
int main(){

	char a = 7;

	printf("a=%d\n &%X\n", a, &a);

	printf("a=%d\n &%d\n", a, *(&a));

	return 0;
} */

void show_bytes(byte_pointers start, int len){
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2X", start[i]);
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointers) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointers) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointers) &x, sizeof(void *));
}

int main(){

	float a = 7;
	int b = 7;
	void *c;

	show_float(a);

	show_int(b);

	show_pointer(c);

	return 0;
}

/*
int main(int argc, char** argv){

	int a = 0;
	int b = 2;

	printf("a||b = %d, a|b = %d\n", a||b, a|b);

	return 0;
}*/

/*
#include <stdio.h>

int main(){

	char a = 1;

	a<<=2;

	printf("a = %d\n", a);

	return 0;
} */