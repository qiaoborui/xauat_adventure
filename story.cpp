#include"story.h"


void draw_story(PIMAGE story_back,char *story_text) {
	static int level = 1;
	cleardevice();
	xyprintf(430,280,"µÚ%d¹Ø",level);
	Sleep(1000);
	int story_status = 1;
	unsigned char c;
	while (story_status) {
		putimage(0,0,story1);
		setcolor(EGERGB(0x00, 0x00, 0x00));
		outtextrect(10,480,880,110,story_text);
		c = getch();
		switch (c) {
		case ' ':
			story_status = 0;
			break;
		}
	}
}
