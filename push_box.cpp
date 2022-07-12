#include "push_box.h"
#include "story.h"
#define OFFSET_X 150
void moveToDown();
int box_curse_x = 11;
int box_curse_y = 9;
int box_down_i = 0; int box_left_i = 0; int box_right_i = 0; int box_up_i = 0;
int boxes = 4;
int box_map[11][13] = {
{8,8,8,1,1,1,1,1,1,1,8,8,8},
{1,1,1,1,0,0,0,0,0,1,8,8,8},
{1,0,0,0,2,1,1,1,0,1,8,8,8},
{1,0,1,0,1,0,0,0,0,1,1,8,8},
{1,0,1,0,3,0,6,1,2,0,1,8,8},
{1,0,1,0,0,0,0,0,1,0,1,8,8},
{1,0,2,1,4,0,7,0,1,0,1,8,8},
{1,1,0,0,0,0,1,0,1,0,1,1,1},
{8,1,0,1,1,1,2,0,0,0,0,0,1},
{8,1,0,0,0,0,0,1,1,0,0,0,1},
{8,1,1,1,1,1,1,1,1,1,1,1,1},
};
void push_box_story() {
	PlaySound(TEXT("sounds/labyrinth/bgm.wav"), NULL, SND_LOOP | SND_ASYNC	 | SND_SYSTEM);
	char text[] = "在建大生活的这么多年，我们学会了很多，跌倒过，失败过，可是我们不曾放弃，只为了去奔赴光明的未来……";
	draw_story(story2, text);
}


/*
floor->0
wall->1
end->2
math->3
gongtu->4
discrete->5
cprogrammer->6
wuli->7
space->8
*/

void box_draw_map() {
	for(int i=0 ;i<11;i++)
		for (int j = 0; j < 13; j++) {
			if (box_map[i][j] == 0)
				putimage(OFFSET_X + j * 45, i * 45, box_wall);
			else if (box_map[i][j] == 1)
				putimage(OFFSET_X + j * 45, i * 45, box_floor);
			else if (box_map[i][j] == 2)
				putimage(OFFSET_X + j * 45, i * 45, box_end);
			else if (box_map[i][j] == 3)
				putimage(OFFSET_X + j * 45, i * 45, box_math);
			else if (box_map[i][j] == 4)
				putimage(OFFSET_X + j * 45, i * 45, box_gongtu);
			else if (box_map[i][j] == 5)
				putimage(OFFSET_X + j * 45, i * 45, box_discrete);
			else if (box_map[i][j] == 6)
				putimage(OFFSET_X + j * 45, i * 45, box_cprogrammer);
			else if (box_map[i][j] == 7)
				putimage(OFFSET_X + j * 45, i * 45, box_wuli);
		}
}

void play_push_box() {
	cleardevice();
	push_box_story();
	putimage(0, 0, game1_back);
	box_draw_map();
	putimage_withalpha(NULL, man_pic, box_curse_x*45+OFFSET_X, (box_curse_y-1)*45, 0, 180, 45, 90);
	unsigned char c;
	while (1) {
		c = getch();
		switch (c) {
		case 'a':
		case 'A':
			//moveToLeft();
			break;
		case 'd':
		case 'D':
			//moveToRight()
			break;
		case 'W':
		case 'w':
			//moveToUp();
			break;
		case 's':
		case 'S':
			moveToDown();
			break;
		}
	}
}
void moveToDown()
{
	if (box_map[box_curse_x][box_curse_y + 1] == 0)
	{
		box_curse_y++;
	}
	else if (box_map[box_curse_x][box_curse_y + 1] == 3 || box_map[box_curse_x][box_curse_y + 1] == 4 || box_map[box_curse_x][box_curse_y + 1] == 5 || box_map[box_curse_x][box_curse_y + 1] == 7)
	{
		if (box_map[box_curse_x][box_curse_y + 2] == 1) {

		}
		else if (box_map[box_curse_x][box_curse_y + 2] == 2) {
			box_curse_y++;
			box_map[box_curse_x][box_curse_y + 2] = box_map[box_curse_x][box_curse_y + 1];
			box_map[box_curse_x][box_curse_y + 1] = 0;
			boxes--;

		}
		else {
			box_map[box_curse_x][box_curse_y + 2] = box_map[box_curse_x][box_curse_y + 1];
			box_curse_y++;
		}
	}
	else if (box_map[box_curse_x][box_curse_y + 1] == 1) {};

	cleardevice();
	putimage(0, 0, game1_back);
	box_draw_map();
	box_down_i = box_down_i == 3 ? 0 : box_down_i;


	putimage_withalpha(NULL, man_pic, OFFSET_X+box_curse_x * 45, box_curse_y * 45-45, box_down_i * 45, 90, 45, 90);
	box_down_i++;
}
