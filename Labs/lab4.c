#include <stdio.h>

void dummy(){

	int result;

	asm __volatile__(
		"F:\n\t"
		"pushl %%ebp;"
		"movl %%esp, %%ebp;"

		"movl 8(%%ebp), %%eax;"
		"imull $3, %%eax;"

		"popl %%ebp;"
		"retl;"

		"G:\n\t"
		"pushl %%ebp;"
		"movl %%esp, %%ebp;"

		"pushl 8(%%ebp);"
		"call F;"
		"movl %%eax, %%ecx;"
		"pushl 12(%%ebp), (%%esp);"
		"call F;"
		"addl %%ecx, %%eax;"

		"addl $8, %%esp;"

		"popl %%ebp;"
		"retl;"
		: "=a"(result));

	return;
}

int main(){

	int i;
	int result = 0;

	for(i = 0; i <= 10; i++){
		result += i;
	}

	while(i <= 10){
		result += i;
		i++;
	}

	do{
		result += i;
		i++;
	}while(i <= 10);

	loop:
		result += i;
		i++;
	if(i <= 10){
		goto loop;
	}

	// sets result to 10
	asm __volatile__(
		"movl $10, %%eax;"
		: "=a"(result));

	asm __volatile__(
		"movl $0, %%ecx;"
		"movl $0, %%eax;"
		"loop:"
		"addl %%ecx, %%eax;"
		"addl $1, %%ecx;"
		"compl $10, %%ecx;"
		"jle loop;"
		: "=a"(result));

	asm __volatile__(
		"pushl $1;"
		"call F;"
		"addl $4, %%esp;"
		: "=a"(result));

	asm __volatile__(
		"pushl $1;"
		"pushl $2;"
		"call G;"
		"addl $8, %%esp;"
		: "=a"(result));

	printf("result is %d\n", result);

	reutrn 0;
}