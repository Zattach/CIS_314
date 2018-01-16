/*
Zach Domke
Assignment 1
Problem 2.64
*/

#include <stdio.h>

// determines if there are any odd bits equal to 1 and outputs 1 if true or 0 if false
int any_odd_one(unsigned x){

	unsigned mask = 0x55555555;

	unsigned odds = x & ~(mask);

	unsigned out = 0 != odds;

	return out;
}

// shows off function any_odd_one
int main(){

	unsigned x = 0x0;
	int out =any_odd_one(x);
	printf("0x%X: %X\n", x, out);

	x = 0x1;
	out = any_odd_one(x);
	printf("0x%X: %X\n", x, out);

	x = 0x2;
	out = any_odd_one(x);
	printf("0x%X: %X\n", x, out);

	x = 0x3;
	out = any_odd_one(x);
	printf("0x%X: %X\n", x, out);

	x = 0xFFFFFFFF;
	out = any_odd_one(x);
	printf("0x%X: %X\n", x, out);

	x = 0x55555555;
	out = any_odd_one(x);
	printf("0x%X: %X\n", x, out);

	return 0;	
}