#include<graphics.h>
#include<iostream>

//int coordinate[7][2] = { {675, 615}, {690, 480}, {840, 400}, {715, 235}, {500, 100}, {360, 285}, {510, 375} };

void intro()
{
	PIMAGE introP = newimage(), start1 = newimage(), start2 = newimage();
	getimage(introP, "intro/frontpage.png");
	getimage(start1, "intro/start1.png");
	getimage(start2, "intro/start.png");
	MUSIC introM;
	introM.OpenFile("intro/intro.mp3");
	introM.Play();
	mouse_msg mouse = { 0 };
	int x = 0, y = -50;
	bool right = true, down = true;
	for (; is_run(); delay_fps(30))
	{
		{
			if (x == 50)
				right = false;
			else if (x == -50)
				right = true;
			if (right == true)
				x++;
			else if (right == false)
				x--;
		}
		{
			if (y == -50)
				down = true;
			else if (y == 50)
				down = false;
			if (down == true)
				y++;
			else if (down == false)
				y--;
		}
		putimage(x, y, introP);
		putimage_transparent(NULL, start1, 600 - (getwidth(start1) / 2), 550 - (getheight(start1) / 2), EGERGB(0, 0, 0));
		while (mousemsg())
			mouse = getmouse();
		if (((mouse.x > 600 - (getwidth(start1) / 2)) && (mouse.x < 600 + (getwidth(start1) / 2))) && ((mouse.y > 550 - (getheight(start1) / 2)) && (mouse.y < 600 + (getheight(start1) / 2))))
		{
			putimage_transparent(NULL, start2, 600 - (getwidth(start1) / 2), 550 - (getheight(start1) / 2), EGERGB(34, 177, 76));
			if (mouse.is_left() == true)
				return;
		}
	}
}

void prologue()
{
	PIMAGE frame = newimage();
	setfont(20, 0, "gameovercre");
	getimage(frame, "intro/1.jpg");
	char filename[32];
	char text[15][100] = { "",
						"Today, Jones went out for coffee", //slide 1
						"He came to the supermarket", //slide 2-4
						"Something becomes a little foggy", //slide 9
						"The fog began to spread", //slide 10-12
						"Oh, here's coffee", //slide 13-14
						"The fog become fierce!", //slide 17-19
						"Jones quickly left the supermarket", //slide 22-23
						"Everything seems to be at peace", //slide 24
						"But the fog chased on", //slide 25
						"The fog becomes thicker and thicker", //slide 26-27
						"The fog even drowned his home", //slide 30-31
						"Jones watched the roads fade in front of him", //slide 32-39
						"Finally, the world become completely white" }; //slide 41-42
	int textInt[45] = { 0, 1, 1, 2, 2, 0,
					0, 0, 0, 3, 4,
					4, 4, 5, 5, 0,
					0, 6, 6, 6, 0,
					0, 7, 7, 8, 9,
					10, 10, 0, 0, 11,
					11, 12, 12, 12, 12,
					12, 12, 12, 12, 0,
					13, 13, 0, 0 };
	int pos = 1;
	int change = 2, slide = 1;
	bool skip = true;
	MUSIC prologueM;
	prologueM.OpenFile("intro/prologueMusic1.mp3");
	prologueM.Play();
	for (; is_run(); delay_fps(60))
	{
		if (pos > 42)
			break;
		change++;
		if (change > 90)
		{
			change = 1;
			sprintf(filename, "intro/%d.jpg", pos);
			pos++;
			slide++;
			getimage(frame, filename);
		}

		cleardevice();
		putimage(0, 0, frame);
		outtextrect(400, 600, 700, 50, text[textInt[pos]]);
		//while (mousemsg())
	//		mouse = getmouse();
	}
	setfont(40, 0, "gameovercre");
	outtextrect(300, 600, 700, 50, "Help Jones regain his memory!");
	getch();
}