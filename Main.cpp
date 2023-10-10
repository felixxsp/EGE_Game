#include<graphics.h> //EGE
#include<stdio.h>
#include<time.h>
#include"2048.h"
#include"start.h"
#include"flappyBird.h"
#include"map.h"
#include"scenes.h"


inline void cloudIn()
{
	PIMAGE cloud = newimage();
	PIMAGE base = newimage();
	setbkcolor(WHITE);
	getimage(base, "mediaMain/mindLimit.jpg");
	getimage(cloud, "mediaMain/transition.jpg");
	//putimage(0, 0, base);
	putimage_transparent(NULL, cloud, 0, 0, EGERGB(0, 0, 0));
	getch();
	return;
}


int main() //initializing the page and functions
{
	initgraph(1200, 700, INIT_WITHLOGO);
	srand(time(NULL));
	intro();
	prologue();
	map(1);
	scene1();
	flappyBird();
	map(2);
	scene3();
	G2048();
}