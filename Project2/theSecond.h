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
class theSecond {
private:
	IMAGE img_bk;//背景图片 
	IMAGE img_bd1, img_bd2;//人物图片
	IMAGE img_board_1, img_board_2;
	IMAGE img_inquiry;
	IMAGE img_blood;
	IMAGE img_q_1, img_q_2, img_q_3, img_q_4;
	const int width = 1400;
	const int high = 900;

	//楼层坐标
	const int firstFloor = 710;
	const int secondFloor = 510;
	const int thirdFloor = 300;
	//传送门坐标
	const int inDoor_x = 180;
	const int inDoor_y = firstFloor;
	const int outDoor_X = 1290;
	const int outDoor_y = thirdFloor;
	const int firstDoor_x = 1200;
	const int firstDoor_y = firstFloor;
	const int secondDoor_x = 160;
	const int secondDoor_y = secondFloor;
	//问题框坐标
	const int inquiry_1_x = 660;
	const int inquiry_1_y = firstFloor;
	const int inquiry_2_x = 800;
	const int inquiry_2_y = secondFloor;
	const int inquiry_3_x = 1330;
	const int inquiry_3_y = secondFloor;
	const int inquiry_4_x = 120;
	const int inquiry_4_y = thirdFloor;
	//梯子坐标
	const int first_ladder_x = 865;
	const int first_ladder_y = firstFloor;
	const int second_ladder_x = 1235;
	const int second_ladder_y = secondFloor;
	//按钮、水池坐标
	const int button_x = 790;
	const int button_y = thirdFloor;
	const int poor_lx = 880;
	const int poor_rx = 1160;
	const int poor_y = thirdFloor;
	//链子、地刺坐标
	const int chain_x = 230;
	const int chain_y = secondFloor;
	const int thorn_left_lx = 440;
	const int thorn_left_rx = 720;
	const int thorn_left_y = secondFloor;
	const int thorn_right_lx = 900;
	const int thorn_right_rx = 1190;
	const int thorn_right_y = secondFloor;
	//边界
	const int LEFT = 10;
	const int RIGHT = width - 20;
	const int LOW = 10;
	const int HIGHT = high - 10;
	//步幅
	const int step = 10;
	//计数器
	int cnt = 0;

	int position_X, position_Y;//人物坐标

	void startUp() {
		initgraph(width, high);
		loadimage(&img_bk, _T("E:\\Dawn\\image\\theSecond\\bg.jpg"));//导入背景图片
		loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));
		loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));

		//loadimage(&img_board_1, _T("E:\\Dawn\\image\\board_1.jpg"));
		//loadimage(&img_board_2, _T("E:\\Dawn\\image\\board_11.jpg"));

		loadimage(&img_q_1, _T("E:\\Dawn\\image\\theSecond\\q_1.jpg"));
		loadimage(&img_q_2, _T("E:\\Dawn\\image\\theSecond\\q_2.jpg"));
		loadimage(&img_q_3, _T("E:\\Dawn\\image\\theSecond\\q_3.jpg"));
		loadimage(&img_q_4, _T("E:\\Dawn\\image\\theSecond\\q_4.jpg"));

		position_X = inDoor_x;
		position_Y = inDoor_y;//初始人物坐标

		BeginBatchDraw();
		//BOOL sndPlaySound(LPCSTR lpszSound, UINT fuSound);
		//sndPlaySound("E:\\Dawn\\music\\theSecond.wav", SND_LOOP);

		//BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
		//PlaySound(_T("E:\\Dawn\\music\\theSecond.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	bool button_is_touched = 0;
	bool q_1 = 0, q_2 = 0, q_3 = 0, q_4 = 0;
	void show() {
		putimage(0, 0, &img_bk); //背景图片初始化
		putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
		putimage(position_X, position_Y, &img_bd1, SRCINVERT);

		if (button_is_touched) {
			putimage(poor_lx, poor_y - 100, &img_board_2, NOTSRCERASE);
			putimage(poor_lx, poor_y - 100, &img_board_1, SRCINVERT);
		}
		if (q_1) putimage(76, 46, &img_q_1);
		if (q_2) putimage(96, 46, &img_q_2);
		if (q_3) putimage(126, 46, &img_q_3);
		if (q_4) putimage(146, 46, &img_q_4);

		cnt = q_1 + q_2 + q_3 + q_4;

		FlushBatchDraw();

	}

	void died() {
		if (position_Y == secondFloor && (position_X == thorn_left_lx || position_X == thorn_right_lx)) {
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
		if (position_Y == secondFloor && (position_X == thorn_left_rx || position_X == thorn_right_rx)) {
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
		if (!button_is_touched && position_X == poor_lx && position_Y == poor_y) {
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
		if (!button_is_touched && position_X == poor_rx && position_Y == poor_y) {
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
	}

	bool updateWithInput() {
		died();
		char m;
		m = _getch();
		switch (m) {
		case 'a': {
			if (position_X - step < LEFT || position_Y != firstFloor && position_Y != secondFloor && position_Y != thirdFloor);
			else if (position_Y == secondFloor) {
				if (position_X - step < thorn_left_rx && position_X >= thorn_left_rx || position_X - step < thorn_right_rx && position_X >= thorn_right_rx) break;
				position_X -= 10;
			}
			else if (position_Y == thirdFloor) {
				if (position_X >= poor_rx && position_X - step <= poor_rx && !button_is_touched) break;
				position_X -= 10;
			}
			else position_X -= 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\left.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\left2.jpg"));
		} break;
		case 'w': {
			if (abs(position_X - first_ladder_x) <= 10 && position_Y <= firstFloor && position_Y > secondFloor
				|| abs(position_X - second_ladder_x) <= 10 && position_Y <= secondFloor && position_Y > thirdFloor
				|| position_X == chain_x && position_Y <= secondFloor && position_Y > thirdFloor)
				position_Y = position_Y - 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
		}break;
		case 's': {
			if (abs(position_X - first_ladder_x) <= 10 && position_Y < firstFloor && position_Y >= secondFloor
				|| abs(position_X - second_ladder_x) <= 10 && position_Y < secondFloor && position_Y >= thirdFloor
				|| position_X == chain_x && position_Y < secondFloor && position_Y >= thirdFloor)
				position_Y = position_Y + 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
		}break;
		case 'd': {
			if (position_X + step >= RIGHT - 10 || position_Y != firstFloor && position_Y != secondFloor && position_Y != thirdFloor);
			else if (position_Y == secondFloor) {
				if (position_X + step > thorn_left_lx && position_X <= thorn_left_lx || position_X + step > thorn_right_lx && position_X <= thorn_right_lx) break;
				position_X += 10;
			}
			else if (position_Y == thirdFloor) {
				if (position_X <= poor_lx && position_X + step > poor_lx && !button_is_touched) break;
				position_X += 10;
			}
			else position_X += 10;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));
		}break;
		case 'e': {
			if (abs(position_X - inquiry_1_x) <= 20 && position_Y == inquiry_1_y) {
				q_1 = 1;
				putimage(76, 46, &img_q_1);
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theSecond\\inquiry_1.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - inquiry_2_x) <= 20 && position_Y == inquiry_2_y) {
				q_2 = 1;
				putimage(96, 46, &img_q_2);
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theSecond\\inquiry_2.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - inquiry_3_x) <= 20 && position_Y == inquiry_3_y) {
				q_4 = 1;
				putimage(146, 46, &img_q_4);
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theSecond\\inquiry_4.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - inquiry_4_x) <= 20 && position_Y == inquiry_4_y) {
				q_3 = 1;
				putimage(126, 46, &img_q_3);
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theSecond\\inquiry_3.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}if (abs(position_X - outDoor_X) <= 20 && position_Y == outDoor_y) {
				if (cnt != 4) break;
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theSecond\\pass.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 0;
			}
			if (position_X == button_x && position_Y == button_y) {
				button_is_touched = 1;
				loadimage(&img_board_1, _T("E:\\Dawn\\image\\theSecond\\board_5.jpg"));
				loadimage(&img_board_2, _T("E:\\Dawn\\image\\theSecond\\board_55.jpg"));
				putimage(poor_lx, poor_y - 100, &img_board_2, NOTSRCERASE);
				putimage(poor_lx, poor_y - 100, &img_board_1, SRCINVERT);
				FlushBatchDraw();
				Sleep(50);
				loadimage(&img_board_1, _T("E:\\Dawn\\image\\theSecond\\board_4.jpg"));
				loadimage(&img_board_2, _T("E:\\Dawn\\image\\theSecond\\board_44.jpg"));
				putimage(poor_lx, poor_y - 100, &img_board_2, NOTSRCERASE);
				putimage(poor_lx, poor_y - 100, &img_board_1, SRCINVERT);
				FlushBatchDraw();
				Sleep(50);
				loadimage(&img_board_1, _T("E:\\Dawn\\image\\theSecond\\board_3.jpg"));
				loadimage(&img_board_2, _T("E:\\Dawn\\image\\theSecond\\board_33.jpg"));
				putimage(poor_lx, poor_y - 100, &img_board_2, NOTSRCERASE);
				putimage(poor_lx, poor_y - 100, &img_board_1, SRCINVERT);
				FlushBatchDraw();
				Sleep(50);
				loadimage(&img_board_1, _T("E:\\Dawn\\image\\theSecond\\board_2.jpg"));
				loadimage(&img_board_2, _T("E:\\Dawn\\image\\theSecond\\board_22.jpg"));
				putimage(poor_lx, poor_y - 100, &img_board_2, NOTSRCERASE);
				putimage(poor_lx, poor_y - 100, &img_board_1, SRCINVERT);
				FlushBatchDraw();
				Sleep(50);
				loadimage(&img_board_1, _T("E:\\Dawn\\image\\theSecond\\board_1.jpg"));
				loadimage(&img_board_2, _T("E:\\Dawn\\image\\theSecond\\board_11.jpg"));
			}
			if (abs(position_X - secondDoor_x) <= 20 && position_Y == secondDoor_y) {
				position_X = firstDoor_x;
				position_Y = firstDoor_y;
			}
			else if (abs(position_X - firstDoor_x) <= 20 && position_Y == firstDoor_y) {
				position_X = secondDoor_x;
				position_Y = secondDoor_y;
			}
		}break;
		}
		return 1;
	}
public:
	theSecond() {

	}
	void start() {
		startUp();
		while (1) {
			show();
			if (!updateWithInput()) break;
		}
		return;
	}
};