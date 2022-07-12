#include"general.h"

PIMAGE start_pic;
PIMAGE over_pic;
PIMAGE button1, button2;
PIMAGE story1, story2;
PIMAGE wall_pic, man_pic, ground_pic;
PIMAGE game1_back;
PIMAGE game2_back, box_math, box_gongtu, box_discrete, box_cprogrammer, box_wuli, box_floor, box_wall,box_end;
void load_resources()
{
	//开始界面的资源加载
	start_pic = newimage();
	button1 = newimage();
	button2 = newimage();
	getimage(start_pic, "img/start.jpg");
	getimage_pngfile(button1, "img/button.png");
	getimage_pngfile(button2, "img/button.png");
	
	//迷宫资源加载
	wall_pic = newimage();
	ground_pic = newimage();
	game1_back = newimage();
	man_pic = newimage();
	story1 = newimage();
	getimage(story1, "img/story/story1.jpg");
	getimage(wall_pic, "img/labyrinth/wall.jpg");
	getimage_pngfile(ground_pic, "img/labyrinth/ground.png");
	getimage(game1_back, "img/background/game1_back.jpg");
	getimage_pngfile(man_pic, "img/labyrinth/man_laby.png");
	
	story2 = newimage();
	box_floor = newimage();
	box_wall = newimage();
	box_math = newimage();
	box_discrete = newimage();
	box_wuli = newimage();
	box_cprogrammer = newimage();
	box_gongtu = newimage();
	box_end = newimage();
	man_pic = newimage();
	getimage(story2, "img/story/story2.jpg");
	getimage_pngfile(box_floor, "img/pushbox/floor.png");
	getimage_pngfile(box_math, "img/pushbox/math.png");
	getimage_pngfile(box_discrete, "img/pushbox/discrete.png");
	getimage_pngfile(box_wuli, "img/pushbox/wuli.png");
	getimage_pngfile(box_cprogrammer, "img/pushbox/cprogram.png");
	getimage_pngfile(box_gongtu, "img/pushbox/gongtu.png");
	getimage(box_wall, "img/pushbox/wall.jpg");
	getimage_pngfile(box_end, "img/pushbox/end.png");
	getimage_pngfile(man_pic, "img/pushbox/box_man.png");
}
void display_transparent(PIMAGE image, int x, int y)
{
	putimage_withalpha(NULL, image, x, y);
}