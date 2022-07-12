#include"general.h"

PIMAGE start_pic;
PIMAGE over_pic;
PIMAGE button1, button2;
PIMAGE story1, story2;
PIMAGE wall_pic, grass_pic, man_pic, ground_pic;
PIMAGE game1_back;
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
	getimage_pngfile(man_pic, "img/labyrinth/man_25x25.png");
	
	story2 = newimage();
	getimage(story2, "img/story/story2.jpg");
	
	
	
}
void display_transparent(PIMAGE image, int x, int y)
{
	putimage_withalpha(NULL, image, x, y);
}