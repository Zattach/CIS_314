#include <stdio.h>

//Use the following code for f2u:
unsigned f2u(float f) {

	return *((unsigned*) &f);
}

int float_le(float x, float y) {

	unsigned ux = f2u(x);
	unsigned uy = f2u(y);

	/* Get the sign bits */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	/* Give an expression using only ux, uy, sx, and sy */
	return (ux == uy) | (sx > sy) | (~sy & ((ux << 1) < (uy << 1)));
}

int main(){
	int ans = float_le(0.0f, 0.0f);
	printf("float_le(0.0f, 0.0f): %d\n", ans);

	ans = float_le(-0.0f, 0.0f);
	printf("float_le(-0.0f, 0.0f): %d\n", ans);

	ans = float_le(-1.0f, 0.0f);
	printf("float_le(-1.0f, 0.0f): %d\n", ans);

	ans = float_le(0.0f, 1.0f);
	printf("float_le(0.0f, 1.0f): %d\n", ans);

	ans = float_le(1.0f, 0.0f);
	printf("float_le(1.0f, 0.0f): %d\n", ans);

	ans = float_le(0.0f, -1.0f);
	printf("float_le(0.0f, -1.0f): %d\n", ans);
}