/*
Zach Domke
Assignment 1
Problem 2.68
*/

#include <stdio.h>

/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
* Assume 1 <= n <= w
*/
int lower_one_mask(int n){

	unsigned mask = 0xFFFFFFFF << (n - 1);

	mask = mask << 1;

	return ~mask;
	
}

// shows off lower_one_mask
int main(){

	int in = 1;
	int out = lower_one_mask(in);
	printf("%d: %d\n", in, out);

	in = 2;
	out = lower_one_mask(in);
	printf("%d: %d\n", in, out);
	
	in = 3;
	out = lower_one_mask(in);
	printf("%d: %d\n", in, out);
	
	in = 5;
	out = lower_one_mask(in);
	printf("%d: %d\n", in, out);

	in = 32;
	out = lower_one_mask(in);
	printf("%d: %d\n", in, out);
	
	
	return 0;
}