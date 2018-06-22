#include <stdio.h>

#define PI 3.14159
						// the parens enclosing the x important
						// what x= 2+c
#define parallel(x, y)   ((x)*(y))/((x)+(y))
#define RECIP2PI 1./2.*PI

void main(void){


	int x  = 13;
	int x2 = x<<3;
	printf("X shifted left 3: %d\n",x2);

	int y  = 19;
	int y2 = ~y;
	printf("Ones complement of y %d\n", y);

	int z  = 12;
	int z2 = z | x;
	printf("z or x: %d", z2 );

	int w = 0x0C;

	//To see if a specific bit is set
	if (w & 0x0C){
		w &= (~0x0C);
		printf("We did an and in an if, %3x\n", w);
	}

	// Coolest line?! for now
	int DDR = 0x09;
	DDR |= (0x01<<2);
	DDR &= ~(0x01<<3);
	printf("DDR result is %x\n",DDR);

	printf("Constant PI: %f\n",PI);

	double a = 9.65;
	double b = 3.42;
	double c = parallel( a, b );

	printf("The define c: %f", c);

	printf("\nThe #define worked: %f\n", RECIP2PI);

	double POWER_SUPPLY = 9.88756;

	printf("\nSize of powersupple var: %ld\n", sizeof(POWER_SUPPLY));

	int eightbit = 255;
	printf("Pre shift right %d\n", eightbit);
	eightbit = eightbit>>1;
	printf("After shift right %d\n", eightbit);
	
	int Y = 132;
	Y |= 1;
	printf("Y after we put least sig fig in %d\n", Y);

	int Z = 255;
	Z &= (~129);	
	printf("Z after took out most and least sig fig %d\n", Z);
	
	int W = 129;
	W = W ^ 255;
	printf("W after we notted it %d\n", W);
	
	int x8 = 0x04;
	int y8 = 0x09;
	printf("X|Y: %x X&Y: %x ~X: %x 0xf1&y8 %x \n", (x8|y8), (x8&y8), (~x8),(0xf1&y8) );

	int x9 = 0xf0;
	int y9 = 0x11;
	printf("X|Y: %x X&Y: %x ~X: %x 0xf1&y9 %x \n", (x9|y9), (x9&y9), (~x9),(0xf1&y9) );
}