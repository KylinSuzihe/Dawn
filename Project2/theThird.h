#pragma once
#include <iostream> 
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
class theThird {
private:
	IMAGE img_bk;//背景图片 
	IMAGE img_bd1, img_bd2;//人物图片
	IMAGE img_blood;
	IMAGE img_inquiry;
	IMAGE img_wood, img_wood2;
	IMAGE img_ladder, img_ladder2;
	IMAGE img_key, img_key2, img_nokey;
	const int width = 1400;
	const int high = 900;

	//楼层坐标
	const int firstFloor = 720;
	const int secondFloor = 510;
	const int thirdFloor = 310;
	//出入口坐标
	const int inDoor_x = 1260;
	const int inDoor_y = thirdFloor;
	const int firstDoor_x = 200;
	const int firstDoor_y = firstFloor;
	//问题框坐标
	const int inquiry_4_x = 305;
	const int inquiry_4_y = firstFloor;
	const int inquiry_3_x = 935;
	const int inquiry_3_y = firstFloor;
	const int inquiry_2_x = 685;
	const int inquiry_2_y = secondFloor;
	const int inquiry_1_x = 615;
	const int inquiry_1_y = thirdFloor;
	//梯子坐标
	const int first_ladder_x = 455;
	const int first_ladder_y = firstFloor;
	const int second_ladder_x = 455;
	const int second_ladder_y = secondFloor;
	const int ladder_x = 795;
	const int ladder_y = secondFloor;
	//按钮、水池坐标
	const int button_x3 = 870;
	const int button_y3 = thirdFloor;
	const int button_x2 = 385;
	const int button_y2 = secondFloor;
	const int button_x1 = 385;
	const int button_y1 = firstFloor;
	const int poor_lx = 700;
	const int poor_rx = 980;
	const int poor_y = firstFloor;
	//链子、地刺坐标
	const int chain_x = 1150;
	const int chain_y = secondFloor;
	const int thorn_x = 70;
	const int thorn_y = thirdFloor;
	const int thorn_x1 = 1300;
	const int thorn_y1 = firstFloor;
	//钥匙、钥匙提示坐标
	const int key_x0 = 805;
	const int key_y0 = 400;
	const int key_x = second_ladder_x;
	const int key_y = second_ladder_y - 130;
	//隧道坐标
	const int hole_x = 100;
	const int hole_uy = thirdFloor;
	const int hole_dy = secondFloor;
	//边界
	const int LEFT = 10;
	const int RIGHT = width - 20;
	const int LOW = 10;
	const int HIGHT = high - 10;
	//步幅
	const int step = 10;

	int position_X, position_Y;//人物坐标

	void startUp() {
		initgraph(width, high);
		loadimage(&img_bk, _T("E:\\Dawn\\image\\theThird\\bg1.jpg"));//导入背景图片


		loadimage(&img_wood, _T("E:\\Dawn\\image\\theThird\\wood.jpg"));
		loadimage(&img_wood2, _T("E:\\Dawn\\image\\theThird\\wood2.jpg"));
		loadimage(&img_ladder, _T("E:\\Dawn\\image\\theThird\\ladder.jpg"));
		loadimage(&img_ladder2, _T("E:\\Dawn\\image\\theThird\\ladder2.jpg"));
		loadimage(&img_key, _T("E:\\Dawn\\image\\theThird\\key.jpg"));
		loadimage(&img_key2, _T("E:\\Dawn\\image\\theThird\\key2.jpg"));
		loadimage(&img_bd1, _T("E:\\Dawn\\image\\left.jpg"));
		loadimage(&img_bd2, _T("E:\\Dawn\\image\\left2.jpg"));
		loadimage(&img_nokey, _T("E:\\Dawn\\image\\theThird\\nokey.jpg"));

		position_X = inDoor_x;
		position_Y = inDoor_y;//初始人物坐标

		BeginBatchDraw();

		//sndPlaySound(_T("E:\\music\\theSecond.wav"), SND_LOOP);
	}
	bool button1_is_touched = 0;
	bool button2_is_touched = 0;
	bool button3_is_touched = 0;
	bool key0_is_touched = 0;
	bool key_is_touched = 0;
	bool q_1 = 0, q_2 = 0, q_3 = 0, q_4 = 0;

	void show() {
		putimage(0, 0, &img_bk); //背景图片初始化

		if (button3_is_touched) {
			putimage(665, 755, &img_wood2, NOTSRCERASE);
			putimage(665, 755, &img_wood, SRCINVERT);
		}
		if (button2_is_touched) {
			putimage(second_ladder_x, second_ladder_y - 145, &img_ladder2, NOTSRCERASE);
			putimage(second_ladder_x, second_ladder_y - 145, &img_ladder, SRCINVERT);
		}
		if (button1_is_touched) {
			putimage(first_ladder_x, first_ladder_y - 145, &img_ladder2, NOTSRCERASE);
			putimage(first_ladder_x, first_ladder_y - 145, &img_ladder, SRCINVERT);
		}
		if (key0_is_touched) {
			putimage(second_ladder_x, second_ladder_y - 130, &img_key2, NOTSRCERASE);
			putimage(second_ladder_x, second_ladder_y - 130, &img_key, SRCINVERT);
		}
		if (key_is_touched) {
			putimage(419, 350, &img_nokey);
			FlushBatchDraw();
		}
		putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
		putimage(position_X, position_Y, &img_bd1, SRCINVERT);
		FlushBatchDraw();

	}

	void died() {
		if (position_Y == thirdFloor && (position_X == thorn_x)) {
			loadimage(&img_blood, _T("E:\\Dawn\\image\\left_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}
		if (position_Y == firstFloor && (position_X == thorn_x1)) {
			loadimage(&img_blood, _T("E:\\Dawn\\image\\right_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}
		if (!button3_is_touched && position_X == poor_rx && position_Y == poor_y) {
			loadimage(&img_blood, _T("E:\\Dawn\\image\\left_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}
		if (!button3_is_touched && position_X == poor_lx && position_Y == poor_y) {
			loadimage(&img_blood, _T("E:\\Dawn\\image\\right_blood.jpg"));
			for (int i = 1; i <= 4; ++i) {
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_blood, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
				putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
				putimage(position_X, position_Y, &img_bd1, SRCINVERT);
				FlushBatchDraw();
				Sleep(100);
			}
		}
	}

	bool updateWithInput() {
		died();
		char m;
		m = _getch();
		switch (m) {
		case 'a': {
			if (position_X - step < LEFT || position_Y != firstFloor && position_Y != secondFloor && position_Y != thirdFloor);
			else if (position_Y == thirdFloor) {
				if (position_X - step < thorn_x && position_X >= thorn_x) break;
				position_X -= 10;
			}
			else if (position_Y == firstFloor) {
				if (position_X >= poor_rx && position_X - step < poor_rx && !button3_is_touched) break;
				position_X -= 10;
			}
			else position_X -= 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\left.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\left2.jpg"));
		} break;
		case 'w': {
			if ((abs(position_X - first_ladder_x) <= 15 && position_Y <= firstFloor && position_Y >= secondFloor && button1_is_touched == 1)
				|| (abs(position_X - second_ladder_x) <= 15 && position_Y <= secondFloor && position_Y > thirdFloor + 90 && button2_is_touched == 1)
				|| (abs(position_X - ladder_x) <= 15 && position_Y <= secondFloor && position_Y > thirdFloor + 100))
				position_Y = position_Y - 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
		}break;
		case 's': {
			if (abs(position_X - first_ladder_x) <= 15 && position_Y < firstFloor && position_Y >= secondFloor - 30 && button1_is_touched == 1
				|| abs(position_X - second_ladder_x) <= 15 && position_Y < secondFloor && position_Y >= thirdFloor - 90 && button2_is_touched == 1
				|| abs(position_X - hole_x) <= 10 && position_Y < secondFloor && position_Y >= thirdFloor
				|| abs(position_X - ladder_x) <= 15 && position_Y < secondFloor && position_Y > thirdFloor - 100
				|| abs(position_X - chain_x) <= 10 && position_Y < firstFloor && position_Y >= secondFloor)
				position_Y = position_Y + 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
		}break;
		case 'd': {
			if (position_Y == firstFloor && (position_X == thorn_x1)) return 1;
			if (position_X + step >= RIGHT || position_Y != firstFloor && position_Y != secondFloor && position_Y != thirdFloor) return 1;
			else if (position_Y == thirdFloor) {
				if (position_X + step > thorn_x1 && position_X <= thorn_x1) break;
				position_X += 10;
			}
			else if (position_Y == firstFloor) {
				if (position_X <= poor_lx && position_X + step > poor_lx && !button3_is_touched) break;
				position_X += 10;
			}
			else position_X += 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));
		}break;
		case 'e': {
			if (abs(position_X - inquiry_1_x) <= 20 && position_Y == inquiry_1_y) {
				q_1 = 1;
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theThird\\one.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - inquiry_2_x) <= 20 && position_Y == inquiry_2_y) {
				q_2 = 1;
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theThird\\two.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - inquiry_3_x) <= 20 && position_Y == inquiry_3_y) {
				q_3 = 1;
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theThird\\three.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - inquiry_4_x) <= 20 && position_Y == inquiry_4_y) {
				q_4 = 1;
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theThird\\four.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - firstDoor_x) <= 30 && position_Y == firstFloor
				&& key_is_touched == 1 && q_1 == 1 && q_2 == 1 && q_3 == 1 && q_4 == 1) {
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theThird\\five.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 0;
			}
			if (abs(position_X - firstDoor_x) <= 30 && position_Y == firstFloor
				&& (key_is_touched == 0 || q_1 == 0 || q_2 == 0 || q_3 == 0 || q_4 == 0)) {
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theThird\\six.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - button_x3) <= 15 && position_Y == button_y3) button3_is_touched = 1;
			if (abs(position_X - button_x2) <= 15 && position_Y == button_y2) button2_is_touched = 1;
			if (abs(position_X - button_x1) <= 15 && position_Y == button_y1) button1_is_touched = 1;
			if (abs(position_X - key_x0) <= 15 && abs(position_Y - key_y0) <= 20) key0_is_touched = 1;
			if (abs(position_X - key_x) <= 15 && abs(position_Y - key_y) <= 20 && key0_is_touched == 1) key_is_touched = 1;

		}break;
		}
		return 1;
	}
	void gameOver() {
		EndBatchDraw();
		closegraph();
	}
public:
	theThird() {
	}
	void start() {
		startUp();
		while (1) {
			show();
			if (!updateWithInput()) break;
		}
		//gameOver();
		return;
	}
};

