#include<graphics.h>
#include<iostream>

int num[4][4] = { 0 }, move[4][4] = { 0 }, checkX, checkY;

void left()
{
	bool moved = false;
	for (int row = 0; row < 4; row++)
	{
		bool noGo[4] = { false, false, false, false };
		for (int chk = 1; chk < 4; chk++)
		{
			for (int next = chk - 1; next >= 0; next--)
			{
				if (num[row][next] == 0)
				{
					num[row][next] = num[row][next + 1];
					num[row][next + 1] = 0;
				}
				else if ((num[row][next] == num[row][next + 1]) && (noGo[next] == false))
				{
					num[row][next] *= 2;
					num[row][next + 1] = 0;
					noGo[next] = true;
				}
			}
		}
	}
}

void right()
{
	bool moved = false;
	for (int row = 0; row < 4; row++)
	{
		bool noGo[4] = { false, false, false, false };
		for (int chk = 2; chk >= 0; chk--)
		{
			for (int next = chk + 1; next < 4; next++)
			{
				if (num[row][next] == 0)
				{
					num[row][next] = num[row][next - 1];
					num[row][next - 1] = 0;
					moved = true;
				}
				else if ((num[row][next] == num[row][next - 1]) && (noGo[next] == false))
				{
					num[row][next] *= 2;
					num[row][next - 1] = 0;
					noGo[next] = true;
					moved = true;
				}
			}
		}
	}
}

void up()
{
	bool moved = false;
	for (int col = 0; col < 4; col++)
	{
		bool noGo[4] = { false, false, false, false };
		for (int chk = 1; chk < 4; chk++)
		{
			for (int next = chk - 1; next >= 0; next--)
			{
				if (num[next][col] == 0)
				{
					num[next][col] = num[next + 1][col];
					num[next + 1][col] = 0;
					moved = true;
				}
				else if ((num[next][col] == num[next + 1][col]) && (noGo[next] == false))
				{
					num[next][col] *= 2;
					num[next + 1][col] = 0;
					noGo[next] = true;
					moved = true;
				}
			}
		}
	}
}

void down()
{
	bool moved = false;
	for (int col = 0; col < 4; col++)
	{
		bool noGo[4] = { false, false, false, false };
		for (int chk = 2; chk >= 0; chk--)
		{
			for (int next = chk + 1; next < 4; next++)
			{
				if (num[next][col] == 0)
				{
					num[next][col] = num[next - 1][col];
					num[next - 1][col] = 0;
					moved = true;
				}
				else if ((num[next][col] == num[next - 1][col]) && (noGo[next] == false))
				{
					num[next][col] *= 2;
					num[next - 1][col] = 0;
					noGo[next] = true;
					moved = true;
				}
			}
		}
	}
}

color_t numCol(int num)
{
	switch (num)
	{
	case 2:
		return EGERGB(224, 227, 245);
	case 4:
		return EGERGB(189, 224, 254);
	case 8:
		return EGERGB(162, 210, 255);
	case 16:
		return EGERGB(133, 196, 255);
	case 32:
		return EGERGB(104, 137, 223);
	case 64:
		return EGERGB(163, 117, 189);
	case 128:
		return EGERGB(208, 138, 191);
	case 256:
		return EGERGB(255, 133, 177);
	case 512:
		return EGERGB(255, 153, 190);
	case 1024:
		return EGERGB(255, 194, 217);
	case 2048:
		return EGERGB(245, 0, 90);
	}
}

inline void board()
{
	setfillcolor(EGERGB(203, 193, 180));
	bar(400, 150, 800, 550);
	setfillcolor(EGERGB(185, 173, 160));
	setcolor(EGERGB(185, 173, 160));
	bar(395, 150, 405, 550);
	bar(400, 145, 800, 155);
	bar(400, 545, 800, 555);
	bar(795, 150, 805, 550);

	bar(595, 150, 605, 550);
	bar(400, 345, 800, 355);
	bar(495, 150, 505, 550);
	bar(400, 245, 800, 255);
	bar(695, 150, 705, 550);
	bar(400, 445, 800, 455);
	fillellipse(400, 150, 5, 5);
	fillellipse(800, 150, 5, 5);
	fillellipse(400, 550, 5, 5);
	fillellipse(800, 550, 5, 5);
}

void create()
{
	int init, initX, initY;
	while (true)
	{
		init = rand() % 16;
		initY = init / 4;
		initX = init % 4;
		if (num[initX][initX] == false)
		{
			num[initX][initY] = 2;
			break;
		}
	}
}

void G2048()
{
	setfont(75, 0, "arial black");
	setbkcolor(EGERGB(250, 248, 240));
	setbkmode(TRANSPARENT);
	color_t word;
	int coordinateX[4] = { 405,505,605,705 }, coordinateY[4] = { 155, 255, 355, 455 };
	key_msg kb = { 0 };
	create();
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		board();
		if (kbhit())
		{
			kb = getkey();
			if (kb.key == key_up)
				up();
			else if (kb.key == key_down)
				down();
			else if (kb.key == key_right)
				right();
			else if (kb.key == key_left)
				left();
			create();
		}
		for (checkY = 0; checkY < 4; checkY++)
		{
			for (checkX = 0; checkX < 4; checkX++)
			{
				setfillcolor(RED);
				if (num[checkX][checkY] != 0)
				{
					setcolor(numCol(num[checkX][checkY]));
					setfillcolor(numCol(num[checkX][checkY]));
					bar(coordinateX[checkY], coordinateY[checkX], coordinateX[checkY] + 90, coordinateY[checkX] + 90);
					setcolor(WHITE);
					char n[10];
					sprintf(n, "%d", num[checkX][checkY]);
					outtextxy(coordinateX[checkY] + 15, coordinateY[checkX] + 15, n);
				}
			}
		}
	}
}