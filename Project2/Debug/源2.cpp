#include <iostream> 
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <mmsystem.h>
#include "../theFourth.h"
#pragma comment(lib, "winmm.lib")
using namespace std;
theFourth the_fourth;
IMAGE img_title;
IMAGE img_gz;
IMAGE img_point, img_point1;
int point_y = 325;
void init() {
	initgraph(1400, 900);
	loadimage(&img_title, _T("E:\\Dawn\\image\\title.jpg"));
	loadimage(&img_point, _T("E:\\Dawn\\image\\point.jpg"));
	loadimage(&img_point1, _T("E:\\Dawn\\image\\point1.jpg"));
	loadimage(&img_gz, _T("E:\\Dawn\\image\\guize.jpg"));
	BeginBatchDraw();
}
void draw() {
	putimage(0, 0, &img_title);
	putimage(450, point_y, &img_point1, NOTSRCERASE);
	putimage(450, point_y, &img_point, SRCINVERT);
	FlushBatchDraw();
}
int main() {
	init();
	draw();
	char c = _getch();
	int x = 1;
	while (1) {
		while (c != 'e') {
			if (c == 'w' && x != 1) x--, point_y -= 113;
			else if (c == 's' && x != 3) x++, point_y += 113;
			draw();
			c = _getch();
		}
		if (x == 1) the_fourth.start();
		else if (x == 3) {
			putimage(350, 200, &img_gz);
			FlushBatchDraw();
			while (_getch() != 'e');
			draw();
		}
		else break;
		draw();
		c = _getch();
	}

	return 0;
}
