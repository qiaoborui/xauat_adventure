#pragma once
#include"main.h"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define GRID_N 15
#define GRID_SIZE 30
#define OFFSET_X 50
#define OFFSET_Y 50
#define HALF_GRID (int)(1/2.0*GRID_SIZE)
#pragma once
void draw_chess();
void draw_back();
void loadimages();
void draw_cursor();
int judgeWiner(int x, int y);
void play();
void play();

void game1();