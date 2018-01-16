#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned char valid;
	unsigned int tag;
	unsigned char value[4];
} block;


int read(block* cache){

	unsigned int add;
	unsigned int tempTag;
	unsigned int set;
	unsigned int offset;
	printf("Enter 32-bit unsigned hex address: ");
	scanf(" %x", &add);
	set = (add >> 2) & 0xF;
	tempTag = add >> 6;
	offset = add & 0x3;
	printf("looking for set: %d - tag: %d\n", set, tempTag);
	if(cache[set].valid == 1){
		printf("found set: %d - tag: %d - offset: %d - valid: 1 - value: %.2x\n", set, tempTag, offset, cache[set].value[offset]);
		if(cache[set].tag == tempTag){
			printf("hit!\n");
		} else {
			printf("tags don't match - miss!");
		}
	} else {
		printf("no valid set found - miss!\n");
	}

	return 0;
}

int write(block* cache){

	unsigned int add;
	unsigned int tempTag;
	unsigned int set;
	unsigned int value;
	printf("Enter 32-bit unsigned hex address: ");
	scanf(" %x", &add);
	set = (add >> 2) & 0xF;
	tempTag = add >> 6;
	printf("Enter 32-bit unsigned hex value: ");
	scanf(" %x", &value);

	if(cache[set].valid == 1){
		printf("evicting block - set: %d - tag: %d - valid: 1 - value: ", set, cache[set].tag);
		for(int i = 0; i < 4; i++){
			printf("%x ", cache[set].value[i]);
		}
		printf("\n");
	}

	cache[set].valid = 1;
	cache[set].tag = tempTag;
	for(int i = 0; i < 4; i++){
		unsigned int mask = 0xFF; // << (8 * i);
		cache[set].value[i] = (value >> (8 * i)) & mask;
	}
	printf("wrote set: %d - tag: %d - valid: 1 - value: ", set, tempTag);
	for(int i = 0; i < 4; i++){
		printf("%.2x ", cache[set].value[i]);
	}
	printf("\n");

	return 0;
}

int print(block* cache){

	for(int i = 0; i < 16; i++){
		if(cache[i].valid == 1){
			printf("set: %d - tag: %d - valid: 1 - value: ", i, cache[i].tag);
			for(int j = 0; j < 4; j++){
				printf("%.2x ", cache[i].value[j]);
			}
			printf("\n");
		}
	}

	return 0;
}

int main(){
	char menu;
	block* cache = malloc(sizeof(block) * 16);

	do{
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
		scanf(" %c", &menu);
		switch(menu){
			case 'r': read(cache);
			break;
			case 'w': write(cache);
			break;
			case 'p': print(cache);
			break;
			case 'q': break;
			default: printf("%u is an invalid option. Please try again.\n", menu);
			break;
		}
	} while (menu != 'q');
	printf("You chose quit. Thank you.\n");
	return 0;
}