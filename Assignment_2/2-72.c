
#include <stdio.h>
#include <string.h>

/* Copy integer into buffer if space is available */
/* WARNING: The following code is buggy */
void copy_int(int val, void *buf, int maxbytes) {
	printf("copy_int(42, buffer, %d): ", maxbytes);

	if (maxbytes-sizeof(val) == 0){
		memcpy(buf, (void *) &val, sizeof(val));

		printf("memcpy should be called\n");
		return;
	}

	printf("memcpy should NOT be called\n");
} 

int main(){
	int buffer[10];
	copy_int(42, buffer, 4); //gets inside if statement
	copy_int(42, buffer, 2); //doesn't get inside if statement
	return 0;
}

/*

Part A: the if statement used in copy_int() will always return true because it is testing (unsigned >= 0) which will have to be true. 

*/