#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
 into an unsigned */
typedef unsigned packed_t;


/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum){

	signed ms = (word >> (bytenum << 3));
	ms = (ms << 24); 
	ms = (ms >> 24); 


	return ms;
}

int main(){
	packed_t word = 0x00007700;
	int bytenum = 1;
	int returned = xbyte(word, bytenum);

	printf("xbyte(0x%.8X, %d): 0x%.8X\n", word, bytenum, returned);

	word = 0x00EE0000;
	bytenum = 2;
	returned = xbyte(word, bytenum);

	printf("xbyte(0x%.8X, %d): 0x%.8X\n", word, bytenum, returned);

	return 0;

}



/* Failed attempt at xbyte 

int xbyte(packed_t word, int bytenum){
	return (word >> (bytenum << 3)) & 0xFF;
}

Part A: This does not give an arithmetic right shift. Instead it just returns the byte that we want.
*/