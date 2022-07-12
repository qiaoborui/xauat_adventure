#pragma once
#include<graphics.h>
#include<Mmsystem.h>
#include <tchar.h>
#pragma comment(lib,"Winmm.lib")
void load_resources();
void display_transparent(PIMAGE image, int x, int y);
extern PIMAGE start_pic, button1, button2;


extern PIMAGE story1, wall_pic, man_pic, ground_pic, game1_back;
extern PIMAGE story2, game2_back;


extern PIMAGE game2_back, box_math, box_gongtu, box_discrete, box_cprogrammer, box_wuli, box_floor, box_wall, box_end;