#include <stdio.h>

int decode2(int x, int y, int z){

	// x at %ebp+8, y at %ebp+12, z at %ebp+16

	int var1 = y;
	var1 = var1 - z;
	int var2 = var1;
	var2 = var2 << 31;
	var2 = var2 >> 31;
	var1 = var1 * x;
	var2 = var1 ^ var2;
	
	return var2;

}

int main(){

	printf("%d\n", decode2(1, 2, 4));

	printf("%d\n", decode2(-4, -8, -12));

	return 0;
}