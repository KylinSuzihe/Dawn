#pragma once
#include<iostream> 
#include<graphics.h>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
using namespace std;

class theFirst {
private:
	IMAGE img_bk;//背景图片 
	IMAGE img_bd1, img_bd2;//人物图片
	IMAGE img_blood;
	IMAGE img_query;
	int x, y;//人物坐标
	int firstTask = 0, secondTask = 0, thirdTask = 0, fourthTask = 0;
	void startup() {
		initgraph(1400, 900);

		loadimage(&img_bk, _T("E:\\Dawn\\image\\theFirst\\background.jpg"));//导入背景图片
		loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));
		loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));
		x = 100;
		y = 710;//初始人物坐标
		BeginBatchDraw();
	}
	void show(){
		putimage(0, 0, &img_bk); //背景图片初始化
		putimage(x, y, &img_bd2, NOTSRCERASE);
		putimage(x, y, &img_bd1, SRCINVERT);
		FlushBatchDraw();

	}

	void updatewithoutinput() {
		if (x + 10 == 200 && y == 710 && firstTask == 0) {
			loadimage(&img_blood, _T("E:\\Dawn\\image\\right_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}

		}
		else if (x - 10 == 840 && y == 510 && secondTask == 0)
		{
			loadimage(&img_blood, _T("E:\\Dawn\\image\\left_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}
		else if (x + 10 == 520 && y == 300)
		{
			loadimage(&img_blood, _T("E:\\Dawn\\image\\right_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}
		else if (x == 740 && y == 300)
		{
			loadimage(&img_blood, _T("E:\\Dawn\\image\\left_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(x, y, &img_bd2, NOTSRCERASE);
				putimage(x, y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}


	}
	bool move(char m) {
		switch (m) {
			case'a': {
				if (x < 10) return 1;
				if (x == 740 && y == 300) return 1;
				if (y == 510 && x == 850 && !secondTask) return 1;
				if (y == 510 && x == 300) return 1;
				if (y != 300 && y != 100 && y != 510 && y != 710 && !(x <= 900 && x >= 840 && y <= 710 && y >= 650) && !(x <= 760 && x >= 700 && y >= 640 && y <= 700) && !(x >= 750 && x <= 830)) return 1;
				if (x <= 900 && x >= 840 && y <= 710 && y >= 650) {
					x -= 10;
					y -= 10;
				}
				else if (x <= 760 && x >= 700 && y >= 640 && y <= 700) {
					x -= 10;
					y += 10;
				}
				else {
					x = x - 10;
					loadimage(&img_bd1, _T("E:\\Dawn\\image\\left.jpg"));
					loadimage(&img_bd2, _T("E:\\Dawn\\image\\left2.jpg"));
				}

			}break;
			case'w': if ((x == 1280 && y <= 710 && y >= 520) || (x == 320 && y <= 520 && y >= 310) || ((x == 70 || x == 60) && y <= 300 && y >= 110))
			{
				y = y - 10;
				loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
				loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
			} break;
			case's': if ((x == 1280 && y <= 700 && y >= 510) || (x == 320 && y <= 500 && y >= 300) || ((x == 70 || x == 60) && y <= 290 && y >= 100))
			{
				y = y + 10;
				loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
				loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
			} break;
			case'd': {
				if (x == 510 && y == 300) return 1;
				if (x == 220 && y == 510) return 1;
				if (x == 190 && y == 710 && !firstTask) return 1;
				if (x > 1360) return 1;
				if (y != 300 && y != 100 && y != 510 && y != 710 && !(x >= 690 && x <= 750 && y <= 710 && y >= 650) && !(x >= 830 && x <= 890 && y <= 700 && y >= 640) && !(x >= 750 && x <= 830)) return 1;
				if (x >= 690 && x <= 750 && y <= 710 && y >= 650) {//第一层斜上坡 
					x = x + 10;
					y = y - 10;
				}
				else if (x >= 830 && x <= 890 && y <= 700 && y >= 640) {
					x = x + 10;
					y = y + 10;
				}
				else {
					x = x + 10;
					loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));
					loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));
				}
			} break;
			case'e': {
				if (x == 1280 && y == 510) x = 150;
				else if (x == 150 && y == 510) x = 1280;
				else if (x == 920 && y == 300) {
					x = 1300;
					y = 100;
				}
				else if (x == 1300 && y == 100) {
					x = 920;
					y = 300;
				}
			}break;
		}
		return 1;
	}
	bool updatewithinput() {
		updatewithoutinput();
		char m;
		m = _getch();
		if (m == 'e' && y == 710 && x >= 160 && x <= 200) {
			loadimage(&img_query, _T("E:\\Dawn\\image\\theFirst\\Query1.jpg"));
			putimage(350, 200, &img_query);
			FlushBatchDraw();
			firstTask = 1;
			m = _getch();
			while (m != 'e') m = _getch();
			return 1;
		}
		if (m == 'e' && y == 510 && x >= 940 && x <= 1010) {
			loadimage(&img_query, _T("E:\\Dawn\\image\\theFirst\\Query2.jpg"));
			putimage(350, 200, &img_query);
			FlushBatchDraw();
			secondTask = 1;
			m = _getch();
			while (m != 'e') m = _getch();
			return 1;
		}
		if (m == 'e' && y == 100 && x >= 850 && x <= 890) {
			loadimage(&img_query, _T("E:\\Dawn\\image\\theFirst\\Query3.jpg"));
			putimage(350, 200, &img_query);
			FlushBatchDraw();
			thirdTask = 1;
			m = _getch();
			while (m != 'e') m = _getch();
			return 1;
		}
		if (m == 'e' && y == 300 && x >= 1230 && x <= 1270) {
			loadimage(&img_query, _T("E:\\Dawn\\image\\theFirst\\Query4.jpg"));
			putimage(350, 200, &img_query);
			FlushBatchDraw();
			fourthTask = 1;
			m = _getch();
			while (m != 'e') m = _getch();
			return 1;
		}
		if (m == 'e' && x == 150 && y == 510 && firstTask & secondTask & thirdTask & fourthTask) {
			loadimage(&img_query, _T("E:\\Dawn\\image\\theFirst\\pass.jpg"));
			putimage(350, 200, &img_query);
			FlushBatchDraw();
			thirdTask = 1;
			m = _getch();
			while (m != 'e') m = _getch();
			return 0;
		}
		return move(m);
	}

public:
	theFirst() {

	}
	void start() {
		startup();
		while (1) {
			show();
			if (!updatewithinput()) break;
		}
		return;
	}
};

