#include <stdio.h>
#include <math.h>

/*
	Lucas Hagel - June 21 2018

*/
float lucas(float a, float b, float c){
	return (a + b + c)/3.0;
}

void main( void )
{
	float s = 10.0;
	float t = 10.0;
	float u = 20.1;
	float v = lucas(s,t,u);
	int z = 42;

	float voltage;
	printf("Please enter the voltage: ");
	scanf("%f", &voltage);
	printf("The voltage is %3.2f\n",voltage);


//%3d -- the 3 is a field width specifier
//%6.2f -- use 6 fields to 2 decimal places
printf("The answer is %3d, or hex %3x, or octal %3o.\n", z, z, z );

printf("%ld\n", sizeof(int));

}

