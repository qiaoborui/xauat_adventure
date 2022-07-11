#include "game1.h"

int chess_board[15][15];
int curse_x = 7;
int curse_y = 7;
int start = 2;
PIMAGE pictures[4];

void game1() {
	char a[] = "作为建大的一份子志愿工作必不可少，今天我要去帮图书馆整理书籍";
	draw_story(story1, a);
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	setbkcolor(EGERGB(0xFF, 0xFF, 0xFF));
	ege_enable_aa(true);
	setcolor(BLACK);
	loadimages();
	draw_chess();
	draw_cursor();
	play();
	closegraph();
}
void draw_cursor()
{
	putimage_withalpha(NULL, pictures[3], OFFSET_X + (curse_x)*GRID_SIZE - HALF_GRID, OFFSET_Y + curse_y * GRID_SIZE - HALF_GRID);
}
void play()
{
	unsigned char c;
	while (1) {
		c = getch();
		switch (c) {
		case 'w':
		case 'W':
			if (curse_y - 1 >= 0) curse_y--;
			break;
		case 'A':
		case 'a':
			if (curse_x - 1 >= 0) curse_x--;
			break;
		case 'S':
		case 's':
			if (curse_y + 1 <= 14) curse_y++;
			break;
		case 'd':
		case 'D':
			if (curse_x + 1 <= 14)curse_x++;
			break;
		case ' ':
			if (chess_board[curse_x][curse_y] == 0)
			{
				PlaySound(TEXT("sounds/chess/chess.wav"), NULL, SND_FILENAME | SND_ASYNC);
				chess_board[curse_x][curse_y] = start;
				start = (start == 1) ? 2 : 1;
				if (judgeWiner(curse_x, curse_y))
				{
					draw_chess();
					setcolor(EGERGB(0x0, 0xFF, 0x0));
					setbkmode(TRANSPARENT);
					setfont(50, 0, "宋体");
					if (start == 2)	outtextxy(720, 300, "白方获胜");
					else	outtextxy(720, 300, "黑方获胜");
					getch();
					return;
				}
			}
		}
		draw_chess();
	}
}
void draw_back() {
	putimage(0, 0, pictures[0]);
	for (int i = 0; i < GRID_N; i++) {
		line(OFFSET_X, OFFSET_Y + i * GRID_SIZE, OFFSET_X + (GRID_N - 1) * GRID_SIZE, OFFSET_Y + i * GRID_SIZE);
		line(OFFSET_X + i * GRID_SIZE, OFFSET_Y, OFFSET_X + i * GRID_SIZE, OFFSET_Y + (GRID_N - 1) * GRID_SIZE);
	}

}
void loadimages()
{
	pictures[0] = newimage();
	pictures[1] = newimage();
	pictures[2] = newimage();
	pictures[3] = newimage();
	getimage(pictures[0], "img/five_chess/back.jpg");
	getimage_pngfile(pictures[1], "img/five_chess/bai.png");
	getimage_pngfile(pictures[2], "img/five_chess/hei.png");
	getimage_pngfile(pictures[3], "img/five_chess/cursor.png");
}
void draw_chess() {
	draw_back();
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			if (chess_board[i][j] == 1) {
				putimage_withalpha(NULL, pictures[1], OFFSET_X + (i)*GRID_SIZE - HALF_GRID, OFFSET_Y + j * GRID_SIZE - HALF_GRID);
			}
			else if (chess_board[i][j] == 2) {
				putimage_withalpha(NULL, pictures[2], OFFSET_X + (i)*GRID_SIZE - HALF_GRID, OFFSET_Y + j * GRID_SIZE - HALF_GRID);
			}
			draw_cursor();
		}


}	
int judgeWiner(int x, int y)
{
	int nx, ny;
	int lr = 1, ud = 1, ld = 1, lu = 1;
	nx = x, ny = y - 1;	//左右方向
	while (chess_board[nx][ny] == chess_board[x][y])	lr++, ny--;
	nx = x, ny = y + 1;
	while (chess_board[nx][ny] == chess_board[x][y])	lr++, ny++;
	nx = x - 1, ny = y;	//上下方向
	while (chess_board[nx][ny] == chess_board[x][y])	ud++, nx--;
	nx = x + 1, ny = y;
	while (chess_board[nx][ny] == chess_board[x][y])	ud++, nx++;
	nx = x - 1, ny = y - 1;	//左上到右下
	while (chess_board[nx][ny] == chess_board[x][y])	ld++, nx--, ny--;
	nx = x + 1, ny = y + 1;
	while (chess_board[nx][ny] == chess_board[x][y])	ld++, nx++, ny++;
	nx = x + 1, ny = y - 1;	//左下到右上
	while (chess_board[nx][ny] == chess_board[x][y])	lu++, nx++, ny--;
	nx = x - 1, ny = y + 1;
	while (chess_board[nx][ny] == chess_board[x][y])	lu++, nx--, ny++;
	if (lr >= 5 || ud >= 5 || ld >= 5 || lu >= 5)	return 1;
	else	return 0;
}