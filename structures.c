#include <stdio.h>
#include <string.h>
struct song{
	float length;
	int track;
	char title[50];

};

struct wavformat{
	int bitrate;
	double speed;
	double quality;
	struct song * associated_songs[25];
};

struct Quest{
	float X;
	long int Y;
	unsigned char Z;
};

//need to print a pointer to console?!
//ints are 4 bytes
// Never dereference an uninitialized pointer
void main(void){

	struct song waiting;
	struct song * nwait = &waiting;
	waiting.length = 3.87;
	waiting.track = 9;
	//waiting.title="waiting on the world to change";
	strcpy(&(waiting.title[0]),"waiting on the world to change");
	printf("%s\n",waiting.title);
	strcpy( nwait->title, "POOFTASTE");
	printf("%s\n",waiting.title);
	printf("Size of an int: %ld\n",sizeof(float));
	
	struct wavformat * theformat_arr[10];

	struct Quest Grail;
	printf("Address of grail X: %p\n",&(Grail.X));
	printf("Address of grail Y: %p\n",&(Grail.Y));
	printf("Address of grail Z: %p\n",&(Grail.Z));
}