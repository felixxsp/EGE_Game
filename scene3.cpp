#include"scenes.h"

void scene3()
{
	PIMAGE BG = newimage(), obj1 = newimage(), obj2 = newimage(), obj3 = newimage(), obj4 = newimage(), obj1s = newimage(), obj2s = newimage(), obj3s = newimage(), obj4s = newimage();
	getimage(obj1, "story3/3-1-1.png");
	getimage(obj1s, "story3/3-1-2.png");
	getimage(obj2, "story3/3-2-1.png");
	getimage(obj2s, "story3/3-2-2.png");
	getimage(obj3, "story3/3-3-1.png");
	getimage(obj3s, "story3/3-3-2.png");
	getimage(obj4, "story3/3-4-1.png");
	getimage(obj4s, "story3/3-4-2.png");
	getimage(BG, "story3/scene 2.jpg");
	bool stage3 = true, object1 = true, object2 = true, object3 = true, object4 = true;
	mouse_msg mouse = { 0 };
	setfont(20, 0, "gameovercre");
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		putimage(-3, -2, BG);
		while (mousemsg())
			mouse = getmouse();
		if (stage3 == true)
		{
			if (object1 == true)
			{
				putimage_transparent(NULL, obj1, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 525) && (mouse.x < 825) && (mouse.y > 515))
				{
					putimage_transparent(NULL, obj1s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						outtextrect(300, 600, 700, 50, "This is the stocking area, there are hundreds of parts being stored here. I was a administrator for a period of time.");
						getch();
						object1 = false;
					}
				}
			}
			if (object2 == true)
			{
				putimage_transparent(NULL, obj2, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 622) && (mouse.x < 780) && (mouse.y < 524) && (mouse.y > 310))
				{
					putimage_transparent(NULL, obj2s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						outtextrect(300, 600, 700, 50, "This is the main controller of the system. I had to work for 3 years before they allow me to use it.");
						getch();
						object2 = false;
					}
				}
			}
			if (object3 == true)
			{
				putimage_transparent(NULL, obj3, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 880) && (mouse.x < 960) && (mouse.y < 435) && (mouse.y > 325))
				{
					putimage_transparent(NULL, obj3s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						outtextrect(300, 600, 700, 50, "That is a laser cutting machine, that was something a person taught me how to use.");
						getch();
						object3 = false;
					}
				}
			}
			if ((object1 == false) && (object2 == false) && (object3 == false))
				stage3 = false;
		}
		else
		{
			if (object4 == true)
			{
				putimage_transparent(NULL, obj4, 0, 0, EGERGB(0, 0, 0));
				if ((mouse.x > 170) && (mouse.x < 210) && (mouse.y > 105) && (mouse.y < 200))
				{
					putimage_transparent(NULL, obj4s, 0, 0, EGERGB(0, 0, 0));
					if (mouse.is_left())
					{
						//viewstory
						object4 = false;

						return;
					}
				}
			}
		}
	}

}