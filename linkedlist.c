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
};


int main(void)
{
	// make this zero so it terminate in a loop
	struct Marmot Larry = { 0, 3.4, 19.7 };
	struct Marmot Jane = { &Larry, 2.5, 13.1 };
	struct Marmot Felix = { &Jane, 2.9, 15.6 };

	PrintMarmotAges(&Felix);

	struct transistor bipolartrans[10];

	FILE *fp;
	char buff[255];
	fp = fopen("./bipolartransistor.txt","r");

	int dev;
	for(int i=0; i < 35;i++)
	{
		dev = i % 7;

		if ( i >= 0 && i <7)
		{
			fscanf(fp, "%s", bipolartrans[dev].device);
			printf("device names are %s\n", bipolartrans[dev].device);
		}
		if (i >= 7 && i < 14)
		{
			fscanf(fp, "%d", &bipolartrans[dev].beta);
			printf("beta names are %d\n", bipolartrans[dev].beta);
		}
		if (i >= 14 && i < 21)
		{
			fscanf(fp, "%f", &bipolartrans[dev].pd_w);
			printf("pd w are %2.2f\n", bipolartrans[dev].pd_w);
		}
		if (i >= 21 && i < 28)
		{
			fscanf(fp, "%f", &bipolartrans[dev].Ic_A);
			printf("Ic_A names are %2.2f\n", bipolartrans[dev].Ic_A);
		}
		if (i >= 28 && i < 35)
		{
			fscanf(fp, "%d", &bipolartrans[dev].BVceo_V);
			printf("BVceo_V names are %d\n", bipolartrans[dev].BVceo_V);
		}
	}	
	
	fclose(fp);

}