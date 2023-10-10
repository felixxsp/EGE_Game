#include<graphics.h> //EGE
#include<stdio.h>

int coordinate[7][2] = { {675, 615}, {690, 480}, {840, 400}, {715, 235}, {500, 100}, {360, 285}, {510, 375} };

void mapExec(PIMAGE mapL, PIMAGE mapD, int x, int y, int nextX, int nextY)
{
	//cloudIn();
	PIMAGE base = newimage();
	getimage(base, "mediaMain/mindLimit.jpg");
	int moveL, moveR, moveU, moveD;
	key_msg k = { 0 };
	int swap = 1;
	bool light = true;
	char temp[32];
	setfont(20, 0, "gameovercre");
	setbkmode(TRANSPARENT);
	for (; is_run(); delay_fps(60))
	{
		swap++;
		if (swap > 90)
		{
			swap = 1;
			light = !light;
		}
		if (kbhit())
		{
			k = getkey();
			if ((k.key == key_right) && (moveR < 70000))
				x += 2;
			else if ((k.key == key_left) && (moveL < 70000))
				x -= 2;
			else if ((k.key == key_up) && (moveU < 70000))
				y -= 2;
			else if ((k.key == key_down) && (moveD < 70000))
				y += 2;
		}
		if (y >= 630)
			y = 630;
		cleardevice();
		putimage(0, 0, base);
		moveR = getpixel(x + 2, y);
		moveL = getpixel(x - 2, y);
		moveU = getpixel(x, y - 2);
		moveD = getpixel(x, y + 2);
		if (light == false)
			putimage(0, 0, mapD);
		else
			putimage(0, 0, mapL);
		//sprintf(temp, "%d %d %d %d", moveR, moveL, moveD, moveU);
		setcolor(GREEN);
		setfillcolor(GREEN);
		fillellipse(nextX, nextY, 10, 10);
		setcolor(RED);
		setfillcolor(EGERGB(255, 0, 0));
		fillellipse(x, y, 5, 5);
		setcolor(WHITE);
		outtextrect(20, 600, 900, 300, "Use the arrow keys to go to the green area");
		if (((x - nextX) * (x - nextX)) + ((y - nextY) * (y - nextY)) <= 100)
		{
			setcolor(GREEN);
			outtextrect(400, 350, 900, 300, "Press ENTER to go into the memory");
			if (kbhit())
			{
				k = getkey();
				if (k.key == key_enter)
					return;
			}
		}
		//outtextrect(200, 200, 300, 300, temp);
	}
}


void map(int pos)
{
	PIMAGE mapL = newimage(), mapD = newimage();
	MUSIC mindM;
	mindM.OpenFile("mediaMain/mindMusic.mp3");
	mindM.Play();
	int x = coordinate[pos - 1][0], y = coordinate[pos - 1][1], nextX = coordinate[pos][0], nextY = coordinate[pos][1];
	switch (pos)
	{
	case 1:
		getimage(mapL, "mediaMain/2-1.jpg");
		getimage(mapD, "mediaMain/2-2.jpg");
		break;
	case 2:
		getimage(mapL, "mediaMain/3-1.jpg");
		getimage(mapD, "mediaMain/3-2.jpg");
		break;
	case 3:
		getimage(mapL, "mediaMain/4-1.jpg");
		getimage(mapD, "mediaMain/4-2.jpg");
		break;
	case 4:
		getimage(mapL, "mediaMain/5-1.jpg");
		getimage(mapD, "mediaMain/5-2.jpg");
		break;
	case 5:
		getimage(mapL, "mediaMain/6-1.jpg");
		getimage(mapD, "mediaMain/6-2.jpg");
		break;
	case 6:
		getimage(mapL, "mediaMain/mind1.jpg");
		getimage(mapD, "mediaMain/mind2.jpg");
		break;
	}
	mapExec(mapL, mapD, x, y, nextX, nextY);
}