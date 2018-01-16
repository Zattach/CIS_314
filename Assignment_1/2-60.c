/*
Zach Domke
Assignment 1
Problem 2.60
*/

#include <stdio.h>

// replaces byte i with char b
unsigned replace_byte(unsigned x, int i, unsigned char b){

	unsigned mask = 0xFF << (i << 3);

	unsigned out = x & (~mask);

	unsigned new = b << (i << 3);

	out = new | out;

	return out;
}

// shows off replace_byte
int main(){

	unsigned x = 0x12345678;
	int i = 2;
	unsigned char b = 0xAB;
	int out = replace_byte(x, i, b);
	printf("replace_byte(0x%X, %d, 0x%X) --> 0x%.8X\n", x, i, b, out);

	x = 0x12345678;
	i = 0;
	b = 0xAB;
	out = replace_byte(x, i, b);
	printf("replace_byte(0x%X, %d, 0x%X) --> 0x%.8X\n", x, i, b, out);

	return 0;
}