#include <stdio.h>

int main() {

	// arithmetic operators + - * / % ++ --
	
	int x = 10;
	int y = 2;
	int z = 0;

	z = x + y;
	z = x - y;
	z = x * y;
	z = x / y;
	z = x % 2;

	// x++ increment
	// x-- decrement

	// augmented assignment operators
	x+=3;
	x-=3;
	x*=3;
	x/=3;

	printf("%d", x);

	return 0;
}