#include"flappyBird.h"

inline void scoreRect() //score board background
{
	setfillcolor(BLACK);
	bar(60, 20, 210, 100);
	setcolor(BLACK);
	fillellipse(60, 60, 40, 40);
	fillellipse(210, 60, 40, 40);
	setfillcolor(WHITE);
	bar(65, 25, 205, 95);
	setcolor(WHITE);
	fillellipse(60, 60, 35, 35);
	fillellipse(210, 60, 35, 35);
}

void flappyBird()
{
	PIMAGE bird = newimage(), BG = newimage(), pillar = newimage(), gameover = newimage(); //creating all the image files
	MUSIC test;
	test.OpenFile("media/helep.mp3");
	test.Play();
	int birdY = 400, x = -75, y;
	int pillarCoord[2][5]; //array for pillar coordinate
	getimage(bird, "media/bird2.png"); //input in the image
	getimage(BG, "media/bg.jpg");
	getimage(pillar, "media/pipe.png");
	key_msg k = { 0 }; //variable for keybard input
	int i, pillarX = 1200, last = 4, score = 0; //initialization for game system variables 
	bool alive = true; //state of the game
	char scoreStr[32]; //score string
	setfont(45, 0, "gameovercre"); //Set font
	setbkmode(TRANSPARENT); //background for font
	for (i = 0; i < 5; i++) //initialize the pillars, all starts on the right side outside of the screen
	{
		pillarCoord[1][i] = (rand() % (200)) - 550;
		pillarCoord[0][i] = pillarX;
		pillarX += 400;
	}
	for (; is_run(); delay_fps(60)) //main function
	{
		if (alive == true) //running the movement calculation
		{
			if (kbhit()) //keyboard inout for bird movements
			{
				k = getkey();
				if (k.key == key_space)
					x = -75; //reset the curve equation
			}
			y = (((x - 5) ^ 2) + 25) / 10; //using basic curve equation to make the bird trajectory -> 10y = (x-5)^2 + 25
			birdY += y; //add the bird position with the y equation to move the bird
			if (birdY <= 0) //limits the bird so it didn't go outside of the screen
				birdY = 0;
			else if (birdY >= 580)
				birdY = 580;
			cleardevice();
			x++; //keeps adding x in the equation 
			int idk = 0; //a random number as a placeholder ^_^
			for (i = 0; i < 5; i++) //calculates all the pillars next position and check if there is any collision
			{
				if ((pillarCoord[0][i] < 476) && (pillarCoord[0][i] > 220)) //when the bird's X coordinate overlaps the pillar
				{
					if ((pillarCoord[1][i] + 600 < birdY) && (pillarCoord[1][i] + 800 > birdY)) //checks if the bird's Y coordinate didn't overlap with the pillar
						idk++; //no collision, so this is just something random :3
					else //collision: both the bird's X and Y coordinate overlaps
						alive = false;
					if (pillarCoord[0][i] == 390) //the bird passes a pillar, score +1
						score++;
				}

				pillarCoord[0][i] -= 2; //move the pillar 2 pixels to the left 60 times a second
				if (pillarCoord[0][i] < -200) //the pillar is outside of the screen (left), reset the coordinate and randomize a new height coordinate
				{
					pillarCoord[0][i] = pillarCoord[0][last] + 400; //moves behind the last pillar
					pillarCoord[1][i] = (rand() % (250)) - 450; //new random height
					last = i;//the newly moved pillar becomes the last pillar
				}
			}
		}
		else //when the game ends,
		{
			setcolor(EGERGB(237, 28, 36));
			setfont(45, 0, "gameovercre");
			if (score < 15)
				outtextrect(300, 350, 900, 300, "\tGame Over\npress R to reset the game");
			setcolor(EGERGB(34, 177, 76));
			if (score >= 15)
				outtextrect(150, 350, 1000, 300, "\t\tYou Win!\npress Enter to continue to the next game");
			k = getkey(); //press key to reset the game
			if ((k.key == 'r') || (k.key == 'R'))
			{
				alive = true;
				pillarX = 1200;
				score = 0;
				x = -75;
				for (i = 0; i < 5; i++) //reposition all the pillar outside of the screen (right)
				{
					pillarCoord[1][i] = (rand() % (200)) - 550;
					pillarCoord[0][i] = pillarX;
					pillarX += 400;
					last = 4;
				}
				birdY = 400; //resets the bird position
			}
			else if ((k.key == key_enter) && (score >= 15))
				return;
		}
		putimage(0, -200, BG); //displays all the image and text, with the location based on all the above calculation
		for (i = 0; i < 5; i++) //display all pillars
			putimage_transparent(NULL, pillar, pillarCoord[0][i], pillarCoord[1][i], EGERGB(195, 195, 195));
		putimage_transparent(NULL, bird, 400, birdY, EGERGB(195, 195, 195)); //display the bird
		sprintf(scoreStr, "Score %d", score); //sets the score string
		scoreRect(); //score background function
		setcolor(BLACK);
		setfont(45, 0, "gameovercre");
		outtextxy(40, 40, scoreStr); //prints the score text
		setfont(20, 0, "gameovercre");
		outtextrect(20, 600, 900, 300, "Press SPACE to jump\nScore over 15 to pass this minigame");
	}
}