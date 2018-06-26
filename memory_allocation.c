#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//bipolartransistor.txt

struct Marmot{

	struct Marmot * pnext;
	float age;
	float weight;

};

void PrintMarmotAges( struct Marmot *top )
{
	struct Marmot * iterMarmot = top;
	while (iterMarmot)
	{
		printf("This Marmot is %3.3f old.\n",iterMarmot->age );
		iterMarmot = iterMarmot->pnext;
	}
}


struct transistor{
	char device[20];
	int beta;
	float pd_w;
	float Ic_A;
	int BVceo_V;
}transistor;


int main(void)
{
	// make this zero so it terminate in a loop
	struct Marmot Larry = { 0, 3.4, 19.7 };
	struct Marmot Jane = { &Larry, 2.5, 13.1 };
	struct Marmot Felix = { &Jane, 2.9, 15.6 };

	/*

	void * malloc( unsigned int size );
	void * calloc( unsigned int num_item, unsigned int item_size );

	malloc() takes a single argument: The number of bytes that you wish to allocate from the free pool.
	calloc() takes two arguments: The number of items that you want to fit into the memory block and
	their size in bytes.

	*/

	struct transistor * tp;

	if ( tp = calloc(200, sizeof(transistor)) )
	{
		printf("slkdfj\n");
	} else {
		printf("little kid\n");
	}

	int * ip;

	if ( ip = calloc(3, sizeof(int)))
	{
		*(ip)   = 3;
		*(ip+1) = 4;
		*(ip+2) = 8;
	}

	printf("%d\n <--ip[2], amazing right?!\n", ip[2]);

	char* ex1;

	if ( ex1=malloc(1000))
	{
		printf("1000 bytes up\n");
	}

	float * flt;
	if ( flt=calloc(500, sizeof(float ) ) )
	{
		printf("It got the floats in !!\n");
	}

	if(ip)free(ip);
	if(tp)free(tp);
	if(ex1)free(ex1);
	if(flt)free(flt);
}