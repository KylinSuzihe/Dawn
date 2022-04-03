#pragma once
#include <iostream> 
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <mmsystem.h>
#include <stdio.h>
#include <windows.h>
#include "theFirst.h"
#include "theSecond.h"
#include "theThird.h"
#pragma comment(lib, "winmm.lib")
using namespace std;
theFirst the_first;
theSecond the_second;
theThird the_third;

const int width = 1400;
const int high = 900;

LRESULT CALLBACK CBTHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	HWND hwnd = (HWND)wParam;
	if (nCode == HCBT_ACTIVATE)
	{
		SetDlgItemText(hwnd, IDABORT, "白色毛衣");
		SetDlgItemText(hwnd, IDRETRY, "粉色T恤");
		SetDlgItemText(hwnd, IDIGNORE, "蓝色卫衣");
		SetDlgItemText(hwnd, IDCANCEL, "西装裤");
		SetDlgItemText(hwnd, IDOK, "牛仔裤");
		SetDlgItemText(hwnd, IDYES, "高跟鞋");
		SetDlgItemText(hwnd, IDNO, "厚底板鞋");
		//可根据自己需求修改其他按钮
	}
	return 0;
}
int MyMessageBox(HWND hwnd, TCHAR* szText, TCHAR* szCaption, UINT uType)
{
	int ret;
	HHOOK hHook = SetWindowsHookEx(WH_CBT, CBTHookProc, NULL, GetCurrentThreadId());
	ret = MessageBox(hwnd, szText, szCaption, uType);
	UnhookWindowsHookEx(hHook);
	return ret;
}

class theFourth {
private:
	IMAGE img_bk;//背景图片 
	IMAGE img_bd1, img_bd2;//人物图片
	IMAGE img_inquiry;
	IMAGE img_blood;

	//楼层坐标
	const int firstFloor = 705;
	const int secondFloor = 535;
	const int thirdFloor = 360;
	//传送门坐标
	const int firstDoor_x = 720;
	const int firstDoor_y = firstFloor;
	const int secondDoor_x = 145;
	const int secondDoor_y = secondFloor;
	const int thirdDoor_x = 475;
	const int thirdDoor_y = thirdFloor;
	const int outDoor_x = 1290;
	const int outDoor_y = thirdFloor;
	//问题框坐标
	const int inquiry_1_x = 270;
	const int inquiry_1_y = firstFloor;
	const int inquiry_2_x = 415;
	const int inquiry_2_y = firstFloor;
	const int inquiry_3_x = 560;
	const int inquiry_3_y = firstFloor;
	const int inquiry_4_x = 1270;
	const int inquiry_4_y = 845;
	const int inquiry_5_x = 1250;
	const int inquiry_5_y = 450;
	//梯子坐标
	const int first_ladder_x = 1325;
	const int first_ladder_y = firstFloor;
	//按钮坐标
	const int button_1_x = 1135;
	const int button_1_y = firstFloor;
	const int button_2_x = 990;
	const int button_2_y = secondFloor;
	const int button_4_x = 100;
	const int button_4_y = firstFloor;
	const int button_5_x = 270;
	const int button_5_y = firstFloor;
	const int button_6_x = 415;
	const int button_6_y = firstFloor;
	const int button_7_x = 560;
	const int button_7_y = firstFloor;
	//地刺坐标
	const int thorn_1_lx = 175;
	const int thorn_1_rx = 225;
	const int thorn_1_y = firstFloor;
	const int thorn_2_lx = 325;
	const int thorn_2_rx = 370;
	const int thorn_2_y = firstFloor;
	const int thorn_3_lx = 465;
	const int thorn_3_rx = 515;
	const int thorn_3_y = firstFloor;
	//边界
	const int LEFT = 10;
	const int RIGHT = width - 20;
	const int LOW = 10;
	const int HIGHT = high - 10;
	//步幅
	const int step = 5;

	int position_X, position_Y;//人物坐标

	void startUp() {
		initgraph(width, high);
		loadimage(&img_bk, _T("E:\\Dawn\\image\\theFourth\\bg.jpg"));//导入背景图片
		loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));//导入人物图片
		loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));

		position_X = 65;
		position_Y = firstFloor;//初始人物坐标

		BeginBatchDraw();

		//sndPlaySound(_T("E:\\Dawn\\music\\theSecond.wav"), SND_LOOP);
	}
	bool button_is_touched = 0;
	void show() {
		putimage(0, 0, &img_bk); //背景图片初始化
		putimage(position_X, position_Y, &img_bd2, NOTSRCERASE);
		putimage(position_X, position_Y, &img_bd1, SRCINVERT);

		FlushBatchDraw();
	}

	void died() {
		if (position_Y == firstFloor && (position_X == thorn_1_lx || position_X == thorn_2_lx || position_X == thorn_1_lx)) {
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
		if (position_Y == firstFloor && (position_X == thorn_1_rx || position_X == thorn_2_rx || position_X == thorn_3_rx)) {
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
		int a = 0, b = 0, c = 0, d = 0;
		char m;
		m = _getch();
		switch (m) {
		case 'a': {
			if (position_X - step < LEFT || position_Y != firstFloor && position_Y != secondFloor && position_Y != thirdFloor) return 1;
			else position_X -= 5;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\left.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\left2.jpg"));
		} break;
		case 'w': {
			if (abs(position_X - first_ladder_x) <= 10 && position_Y <= firstFloor && position_Y > secondFloor)
				position_Y = position_Y - 5;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
		}break;
		case 's': {
			if (abs(position_X - first_ladder_x) <= 10 && position_Y < firstFloor && position_Y >= secondFloor)
				position_Y = position_Y + 5;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\back.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\back2.jpg"));
		}break;
		case 'd': {
			if (position_X + step >= RIGHT || position_Y != firstFloor && position_Y != secondFloor && position_Y != thirdFloor) return 1;
			else position_X += 5;
			loadimage(&img_bd1, _T("E:\\Dawn\\image\\right.jpg"));
			loadimage(&img_bd2, _T("E:\\Dawn\\image\\right2.jpg"));
		}break;
		case 'e': {
			if (abs(position_X - button_1_x) <= 20 && position_Y == button_1_y) {
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theFourth\\inquiry_1.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - button_2_x) <= 20 && position_Y == button_2_y) {
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theFourth\\inquiry_2.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - button_4_x) <= 20 && position_Y == button_4_y) {
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theFourth\\inquiry_3.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 1;
			}
			if (abs(position_X - outDoor_x) <= 20 && position_Y == outDoor_y)
			{                    //结束游戏
				loadimage(&img_inquiry, _T("E:\\Dawn\\image\\theFourth\\pass.jpg"));
				putimage(350, 200, &img_inquiry);
				FlushBatchDraw();
				m = _getch();
				while (m != 'e') m = _getch();
				return 0;
			}
			else if (position_X == secondDoor_x && position_Y == secondDoor_y) {
				position_X = thirdDoor_x;
				position_Y = thirdDoor_y;
			}
			else if (position_X == thirdDoor_x && position_Y == thirdDoor_y) {
				position_X = secondDoor_x;
				position_Y = secondDoor_y;
			}
		}break;
		}
		if (position_X == firstDoor_x && position_Y == firstDoor_y && d == 0)
		{
			while (1)
			{
				if (MyMessageBox(NULL, "请根据之前的提示为妈妈选择一件合适的上衣吧！", "上衣", MB_ABORTRETRYIGNORE) == 3)
					break;
				else MessageBox(NULL, "提示：妈妈的朋友圈里有很多关于雪的诗句", "选择错误", MB_OKCANCEL);
			}
			while (1)
			{
				if (MyMessageBox(NULL, "请根据之前的提示为妈妈选择一件合适的裤子吧！", "下衣", MB_OKCANCEL) == 2)
					break;
				else MessageBox(NULL, "提示：妈妈曾说相比于牛仔，她更喜欢有坠感的面料", "选择错误", MB_OKCANCEL);
			}
			while (1)
			{
				if (MyMessageBox(NULL, "请根据之前的提示为妈妈选择一双合适的鞋子吧！", "鞋子", MB_YESNO) == 7)
					break;
				else MessageBox(NULL, "提示：妈妈曾说高跟鞋穿着太累，平底鞋又显得自己太矮", "选择错误", MB_OKCANCEL);
			}
			d = 1;
		}
		if (position_X == button_5_x && position_Y == button_5_y && a == 0)
		{	//调第一关
			the_first.start();
			a = 1;
		}
		if (position_X == button_6_x && position_Y == button_6_y && b == 0)
		{	//调第二关
			the_second.start();
			b = 1;
		}
		if (position_X == button_7_x && position_Y == button_7_y && c == 0)
		{	//调第三关
			the_third.start();
			c = 1;
		}
		return 1;
	}

public:
	theFourth() {
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