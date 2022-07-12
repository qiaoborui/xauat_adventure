#include<stdio.h>
#include"main.h"

int main()
{
	initgraph(900, 600);//生成画布
	load_resources();//加载资源
	startup();//初始化
	start_view();//界面一
	playLabyrinth();//游戏一
	//play_push_box();
}