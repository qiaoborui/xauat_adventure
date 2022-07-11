#include"general.h"

PIMAGE start_pic;
PIMAGE over_pic;
PIMAGE button1, button2;
PIMAGE story1, story2;

void load_resources()
{
	start_pic = newimage();
	getimage(start_pic, "img/start.png");
	button1 = newimage();
	button2 = newimage();
	getimage_pngfile(button1, "img/button.png");
	getimage_pngfile(button2, "img/button.png");
	story1 = newimage();
	getimage_pngfile(story1, "img/start.png");
}
void display_transparent(PIMAGE image, int x, int y)
{
	putimage_withalpha(NULL, image, x, y);
}