#include"scenes.h"

void scene1()
{
	PIMAGE BG = newimage(), obj1 = newimage(), obj2 = newimage(), obj3 = newimage(), obj4 = newimage(), obj1s = newimage(), obj2s = newimage(), obj3s = newimage(), obj4s = newimage(), introfb = newimage();
	getimage(obj1, "story1/1-1.png");
	getimage(obj1s, "story1/1-2.png");
	getimage(obj2, "story1/2-1.png");
	getimage(obj2s, "story1/2-2.png");
	getimage(obj3, "story1/3-1.png");
	getimage(obj3s, "story1/3-2.png");
	getimage(obj4, "story1/4-1.png");
	getimage(obj4s, "story1/4-2.png");
	getimage(BG, "story1/scene 1.jpg");
	getimage(introfb, "story1/introfb.png");
	bool stage1 = true, object1 = true, object2 = true, object3 = true, object4 = true;
	mouse_msg mouse = { 0 };
	setfont(20, 0, "gameovercre");
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		putimage(1, -1, BG);
		while (mousemsg())
			mouse = getmouse();
		if (stage1 == true)
		{
			if (object1 == true)
			{
				putimage_transparent(NULL, obj1, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 16) && (mouse.x < 185) && (mouse.y < 145))
				{
					putimage_transparent(NULL, obj1s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						outtextrect(300, 600, 700, 50, "It's a suitcase stuffed with car models, I really like cars.");
						getch();
						object1 = false;
					}
				}
			}
			if (object2 == true)
			{
				putimage_transparent(NULL, obj2, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 450) && (mouse.x < 505) && (mouse.y < 100) && (mouse.y > 64))
				{
					putimage_transparent(NULL, obj2s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						outtextrect(300, 600, 700, 50, "It's a Beatle my dad bring back from Hong Kong.");
						getch();
						object2 = false;
					}
				}
			}
			if (object3 == true)
			{
				putimage_transparent(NULL, obj3, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 688) && (mouse.x < 828) && (mouse.y < 204))
				{
					putimage_transparent(NULL, obj3s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						outtextrect(300, 600, 700, 50, "Mom and dad seems to like coffee a lot.");
						getch();
						object3 = false;
					}
				}
			}
			if ((object1 == false) && (object2 == false) && (object3 == false))
				stage1 = false;
		}
		else
		{
			if (object4 == true)
			{
				putimage_transparent(NULL, obj4, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 700) && (mouse.x < 763) && (mouse.y > 144) && (mouse.y < 266))
				{
					putimage_transparent(NULL, obj4s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						//viewstory

						object4 = false;
						putimage(600 - (getwidth(introfb) / 2), 350 - getheight(introfb) / 2, introfb);
						getch();
						return;
					}
				}
			}
		}
	}
	getch();
}