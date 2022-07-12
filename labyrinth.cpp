#include"labyrinth.h"
#include "story.h"
#define OFFSET_X 150
#define BRICK_SIZE 25
int laby_curse_x = 1;
int laby_curse_y = 1;
int map[23][23] = { 
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
	{1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

/*
0 -> 路（地面）
1 -> 墙
*/

void laby_story() {
	PlaySound(TEXT("sounds/labyrinth/bgm.wav"), NULL, SND_LOOP| SND_ASYNC |SND_SYSTEM);
	char text[] = "第一次来到大学先去找找我的宿舍吧";
	draw_story(story1, text);
}

void draw_labyrinth() {
	for (int i =0;i<23;i++)
		for (int j = 0; j < 23; j++)
		{
			if (map[i][j] == 0){
				display_transparent(ground_pic, i * BRICK_SIZE + OFFSET_X, j * BRICK_SIZE);
			}
			else if (map[i][j] == 1) {
				putimage(i * BRICK_SIZE + OFFSET_X, j * BRICK_SIZE,wall_pic);
			}
		}
}

void playLabyrinth() {
	cleardevice();
	laby_story();
	putimage(0, 0, game1_back);
	draw_labyrinth();
	unsigned char c;
	while (1) {
		putimage(0, 0, game1_back);
		draw_labyrinth();
		putimage_withalpha(NULL, man_pic, OFFSET_X + laby_curse_x * BRICK_SIZE, laby_curse_y * BRICK_SIZE);
		if (laby_curse_x == 22 && laby_curse_y == 4) {
			break;
		}
		c = getch();
		switch (c) {
		case 'a':
		case 'A':
			if (map[laby_curse_x - 1][laby_curse_y] == 0 && laby_curse_x>0) laby_curse_x--;
			break;
		case 'd':
		case 'D':
			if (map[laby_curse_x + 1][laby_curse_y] == 0 && laby_curse_x<22) laby_curse_x++;
			break;
		case 'W':
		case 'w':
			if (map[laby_curse_x][laby_curse_y - 1] == 0&& laby_curse_y>0) laby_curse_y--;
			break;
		case 's':
		case 'S':
			if (map[laby_curse_x][laby_curse_y + 1] == 0 && laby_curse_y<22) laby_curse_y++;
			break;
		}
		PlaySound(TEXT("sounds/labyrinth/labyrinth.wav"), NULL, SND_NOSTOP | SND_ASYNC | SND_NOWAIT);
		cleardevice();
	}
}