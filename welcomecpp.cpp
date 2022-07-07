#include"welcome.h"
#include <string.h>
PIMAGE start;
PIMAGE over;
PIMAGE button1, button2;
int button1_status = 0;
int button2_status = 0;
int isnt_click = 1;
struct button {
	PIMAGE img;
	int x;
	int y;
	char text[100];
	void(* click)();
} but[2];//300x90
void place_button()
{
	setfont(32, 0, "宋体");
	setbkmode(TRANSPARENT);
	for (int i = 0; i < 2; i++) {
		if (button1_status == 1 && i == 0) {
			setcolor(YELLOW);
		}
		else if (button2_status == 1 && i == 1) {
			setcolor(YELLOW);
		}
		else {
			setcolor(WHITE);
		}
		display_transparent(but[i].img, but[i].x, but[i].y);
		outtextxy(but[i].x + 90, but[i].y + 40, but[i].text);
	}
}
void startup()
{
	setcaption("建大大冒险");
	but[0].img = button1;
	but[1].img = button2;
	but[0].x = 580; but[0].y = 400; 
	but[1].x = 580; but[1].y = 500;
	strcpy(but[0].text, "开始游戏");
	strcpy(but[1].text, "退出游戏");

}
void start_view()
{
	mouse_msg msg;
	cleardevice();
	while (isnt_click) {
		putimage(0, 0, start);
		place_button();
		msg = mouse_msg();
		while (mousemsg()) {
			//有则读取
			msg = getmouse();
			if (msg.x>but[0].x && msg.x<but[0].x + 300 && msg.y>but[0].y && msg.y<but[0].y + 90) {
				button1_status = 1;
			} else button1_status = 0;
			if (msg.x>but[1].x && msg.x<but[1].x + 300 && msg.y>but[1].y && msg.y<but[1].y + 90) {
				button2_status = 1; 
			} else button2_status = 0;
			if (msg.is_down() && msg.is_left()) {
				if (msg.x > but[0].x && msg.x<but[0].x + 300 && msg.y>but[0].y && msg.y < but[0].y + 90) {
					isnt_click = 0;
				}
				else if (msg.x > but[1].x && msg.x<but[1].x + 300 && msg.y>but[1].y && msg.y < but[1].y + 90) exit(0);
			}
		}
		delay_fps(60);
	}
}
void gmae_over()
{

}
void load_resources()
{
	start = newimage();
	getimage(start, "img/start.png");
	button1 = newimage();
	button2 = newimage();
	getimage_pngfile(button1, "img/button.png");
	getimage_pngfile(button2, "img/button.png");
}
void display_transparent(PIMAGE image, int x, int y)
{
	putimage_withalpha(NULL, image, x, y);
}