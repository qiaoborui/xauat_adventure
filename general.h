#pragma once
#include<graphics.h>
#include<Mmsystem.h>
#include <tchar.h>
#pragma comment(lib,"Winmm.lib")
void load_resources();
void display_transparent(PIMAGE image, int x, int y);
extern PIMAGE start_pic, button1, button2, story1, story2, wall_pic, grass_pic, man_pic, ground_pic, game1_back;