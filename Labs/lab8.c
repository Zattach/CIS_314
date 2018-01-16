/*
Optimization Blockers		(Question on this on final. Answer will be:)
1) function call
2) pointer alias
	int* a;
	int* b;
	...
	b = a;
	b[i] = 6 -> a[i] = 6

Chapter 5 (75 pages about Optimization)
*/

//	1.1 Perspective (or Logical Detour)

if(x != 0){
	x = 0;
}	// functionally equivalent as: 
x = 0;

if(x == true){
	x = false;
} else {
	x = true;
}	// functionally equivalent as: 
x != x;

//	1.2 Inlining

long counter = 0;

inline long f(){
	return counter++;
}

long func(){
	return f() + f() + f() + f();
}

//	1.3 Unroll Loop

int sum(int a[]){
	int i, sum = 0;
	for(i = 0; i < 256; i++){
		sum += a[i];
	}
	return sum;
}
// becomes
int sum(int a[]){
	int i, sum = 0;
	for(i = 0; i < 256; i += 8){
		sum += a[i];
		sum += a[i+1];
		sum += a[i+2];
		sum += a[i+3];
		sum += a[i+4];
		sum += a[i+5];
		sum += a[i+6];
		sum += a[i+7];
	}
	return sum;
}

//	1.4 Loop Jamming
	combinging loops when there are multiple unneccesary loops.

// 1.5 Loop Inversion
int up(int a[]){	// slower
	int i, sum = 0;
	for(i = 0; i < SIZE; i++){
		sum += a[i];
	}
	return sum;
}

int down(int a[]){	// faster but same solution
	int i, sum = 0;
	for(i = SIZE - 1; i != 0; i--){
		sum += a[i];
	}
	return sum;
}

//	1.6 Strength Reduction
void f(){	//OLD and SLOW
	int x = w % 8;		// slowest instruction
	int y = pow(x, 2.0);
	int z = y * 33;
	for (int i = 0; i < MAX; i++){
		h = 14 * i;
		printf("%d", h);
	}
}

void g(){	// NEW and FAST
	x = w & 7;
	y = x * x;
	z = (y << 5) + y;
	for(i = h = 0; i < MAX; i++){
		printf("%d", h);
		h += 14;
	}
}

//	1.7 Arithmetic Reordering
float a, b, c, d, f, g;		// OLD and SLOW
	a = b / c * d;
	f = b * g / c;

float a, b, c, d, f, g;		// NEW and FAST
float div  = b / c;
	a = div * d;
	f = div * g;

//	2.1 Alignment Padding
	consider slop, the addresses padded around some types of variable.