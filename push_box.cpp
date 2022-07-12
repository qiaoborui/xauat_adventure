#include "push_box.h"
#include "story.h"
/*
int box_map[11][13] = {
	{8,1,1,1,1,1,1,1,8,8,8},
	{8,1,0,0,0,0,0,1,1,1,1},
	{8,1,0,1,1,1,2,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,1},
	{1,0,2,1,3,0,4,0,1,0,1},
	{1,0,1,0,0,5,0,0,1,0,1},
	{1,0,1,0,6,0,7,1,2,0,1},
	{1,0,1,0,1,0,0,0,0,1,1},
	{1,0,0,0,2,1,1,1,0,1,1},
	{1,1,1,1,0,0,0,0,0,0,1},
	{8,8,8,1,1,1,1,1,0,0,1},
	{8,8,8,8,8,8,8,1,0,0,1},
	{8,8,8,8,8,8,8,1,1,1,1},


};
void push_box_story() {
	PlaySound(TEXT("sounds/labyrinth/bgm.wav"), NULL, SND_LOOP | SND_ASYNC	 | SND_SYSTEM);
	char text[] = "在建大生活的这么多年，我们学会了很多，跌倒过，失败过，可是我们不曾放弃，只为了去奔赴光明的未来……";
	draw_story(story2, text);
}

void play_push_box() {
	cleardevice();
	push_box_story();
	putimage(0, 0, game1_back);
}
*/

/*
floor->0
wall->1
end->2
math->3
gongtu->4
english->5
cprogrammer->6
wuli->7
space->8
*/
/*
void box_draw_map() {
	for(int i ;i<11;i++)
		for (int j; j < 13; j++) {
			if (box_map[i][j]==0)
				putimage(j * 50, i * 50, box_floor);
			else if (box_map[i][j] == 1)
				putimage(j * 50, i * 50, box_wall);
			else if (box_map[i][j] == 2)
				putimage(j * 50, i * 50, box_end);
			else if (box_map[i][j] == 3)
				putimage(j * 50, i * 50, box_math);
			else if (box_map[i][j] == 4)
				putimage(j * 50, i * 50, box_gongtu);
			else if (box_map[i][j] == 5)
				putimage(j * 50, i * 50, box_english);
			else if (box_map[i][j] == 6)
				putimage(j * 50, i * 50, box_cprogrammer);
			else if (box_map[i][j] == 7)
				putimage(j * 50, i * 50, box_wuli);
			else if (box_map[i][j] == 8)
				putimage(j * 50, i * 50, box_space);
		}
}*/