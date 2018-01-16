
#include <stdio.h>

//typedef union{...} u;

//unsigned f2u(float f){
//	return *((unsigned*) &f);
//}

unsigned f2u(float f){

	typedef union{
		float f;
		unsigned u;
	} u;

	u u1;
	u1.f = f;
	return u1.u;
}

//void printBinary(char a){
void printBinary(unsigned a){
	int i;

	//for(i = 7; i >= 0; i--){	
	for(i = 31; i >= 0; i--){

		printf("%d", a>>i & 1);
	}

	printf("\n");

	return;
}

int main(){
	float a = 8.5;

	printBinary(f2u(a));

	//printf("a = %d\n", a);

	return 0;
}


/* float 8.5 represented in  base 2

1.	8.5 => 1000.1
2.	1000.1 == 1.0001 x 2^3	(1000.1 >> 3)
3.	E = e + 127 = 3 + 127 = 130 => 10000010

8.5 == |0|10000010|00010000000000000000000|
	   |s| exp	  |    	 frac         	  |

*/

/*	0x42100000 to decimal float

0.	|0|100 0010 0|001 000000...|
	|s|	  exp	 |	  frac  ...|
	s = 0
	E = 132
	e = 132 - 127 = 5

	1.001 x 2^5 = 100100 = 36.0
*/
