/*
Zach Domke
Assignment 1
Problem 2.57
*/

#include <stdio.h>

// creates a pointer to a char called byte_pointers
typedef unsigned char * byte_pointers;

// creates a procedure used by other functions that shows the bytes of the given variable
void show_bytes(byte_pointers start, int len){
	int i;
	for(i = 0; i < len; i++){
		printf(" %.2X", start[i]);
	}
	printf("\n");
}

// uses show_bytes to show the bytes of the given short int
void show_short(short int s){
	show_bytes((byte_pointers) &s, sizeof(short int));
}

// uses show_bytes to show the bytes of the given long int
void show_long(long int l){
	show_bytes((byte_pointers) &l, sizeof(long int));
}

// uses show_bytes to show the bytes of the given double
void show_double(double d){
	show_bytes((byte_pointers) &d, sizeof(double));
}

// shows off show_short, show_long, show_double
int main(){
	short int a = 56;
	long int b = 47029;
	double c = 39.582;

	show_short(a);
	show_long(b);
	show_double(c);

	return 0;
}