
// piano.cpp: 定义控制台应用程序的入口点。
//键盘上的A(65) S(83) D(68) F(70) G(71) H(72) J(74)分别代表DO RE MI FA SOL LA SI（中央c)
//R(82) T(84) Y(89) U(85) I(73) O(79) P(80)分别代表高音区的DO RE MI FA SOL LA SI
//数字1 2 3 4 5 6 7 8 9 0代表黑键
#include "stdafx.h"
#include<graphics.h>
#include<mmsystem.h>
#include<windows.h>
#include<ege.h>
#include<iostream>
#pragma comment(lib,"winmm.lib")
using namespace std;


DWORD proc(LPVOID lpThreadParameter) {
	char buff[256] = { 0 };
	sprintf_s(buff, "open sounds\\%s alias m", (char*)lpThreadParameter);
	mciSendString(buff, 0, 0, 0);//打开
	mciSendString("play m", 0, 0, 0);//播放
	api_sleep(1000);//声音持续时间
 mciSendString("close m", 0, 0, 0);//关闭 让它自动关闭

	return 0;

}

PIMAGE white1;
PIMAGE white2;
PIMAGE white3;
PIMAGE black;
PIMAGE grey1;
PIMAGE grey2;
PIMAGE grey3;
PIMAGE grey4;

void init()
{

	white1 = newimage();
	white2 = newimage();
	white3 = newimage();
	black = newimage();
	grey1 = newimage();;
	grey2 = newimage();
	grey3 = newimage();
	grey4 = newimage();


	getimage(white1, "pics\\white-1.png");
	getimage(white2, "pics\\white-2.png");
	getimage(white3, "pics\\white-3.png");
	getimage(black, "pics\\black.png");
	getimage(grey1, "pics\\grey-1.png");
	getimage(grey2, "pics\\grey-2.png");
	getimage(grey3, "pics\\grey-3.png");
	getimage(grey4, "pics\\grey-4.png");

	putimage_withalpha(NULL, white1, 0, 0);
	putimage_withalpha(NULL, white2, 80, 0);
	putimage_withalpha(NULL, white3, 160, 0);
	putimage_withalpha(NULL, white1, 240, 0);
	putimage_withalpha(NULL, white2, 320, 0);
	putimage_withalpha(NULL, white2, 400, 0);
	putimage_withalpha(NULL, white3, 480, 0);
	putimage_withalpha(NULL, white1, 560, 0);
	putimage_withalpha(NULL, white2, 640, 0);
	putimage_withalpha(NULL, white3, 720, 0);
	putimage_withalpha(NULL, white1, 800, 0);
	putimage_withalpha(NULL, white2, 880, 0);
	putimage_withalpha(NULL, white2, 960, 0);
	putimage_withalpha(NULL, white3, 1040, 0);
	putimage_withalpha(NULL, black, 55, 0);
	putimage_withalpha(NULL, black, 135, 0);
	putimage_withalpha(NULL, black, 295, 0);
	putimage_withalpha(NULL, black, 375, 0);
	putimage_withalpha(NULL, black, 455, 0);
	putimage_withalpha(NULL, black, 615, 0);
	putimage_withalpha(NULL, black, 695, 0);
	putimage_withalpha(NULL, black, 855, 0);
	putimage_withalpha(NULL, black, 935, 0);
	putimage_withalpha(NULL, black, 1015, 0);
	//getch();
	delimage(white1);
	delimage(white2);
	delimage(white3);
	delimage(black);
	delimage(grey1);
	delimage(grey2);
	delimage(grey3);
	delimage(grey4);


}

VOID(timeProc(HWND hWnd, UINT uInt, UINT_PTR ptr, DWORD dWord)) {
	SendMessage(hWnd, WM_KEYDOWN, 'a', NULL);
}
int main()
{
	char c;
	DWORD id; 
	while (1) {
		cin >> c;//获取按键值并返回
		//cout << c << endl;
		initgraph(1120, 500, SHOWCONSOLE);
		HWND hWnd = FindWindow(NULL, NULL);
		init();
		SetTimer(hWnd, 8880, 500, (TIMERPROC)timeProc);
		switch (c) {
		case 'a'://中央c
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "a.wav", NULL, &id);
			break;
		case 's'://re
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "s.wav", NULL, &id);
			break;
		case 'd'://mi
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "d.wav", NULL, &id);
			break;
		case 'f'://fa
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "f.wav", NULL, &id);
			break;
		case 'g'://so
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "g.wav", NULL, &id);
			break;
		case 'h'://la
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "h.wav", NULL, &id);
			break;
		case 'j'://ti
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "j.wav", NULL, &id);
			break;
		case 'r'://高音区 do
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "r.wav", NULL, &id);
			break;
		case 't':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "t.wav", NULL, &id);
			break;
		case 'y':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "y.wav", NULL, &id);
			break;
		case 'u':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "u.wav", NULL, &id);
			break;
		case 'i':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "i.wav", NULL, &id);
			break;
		case 'o':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "o.wav", NULL, &id);
			break;
		case 'p':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "p.wav", NULL, &id);
			break;
		case '1'://黑键
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "1.wav", NULL, &id);
			break;
		case '2':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "2.wav", NULL, &id);
			break;
		case '3':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "3.wav", NULL, &id);
			break;
		case '4':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "4.wav", NULL, &id);
			break;
		case '5':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "5.wav", NULL, &id);
			break;
		case '6':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "6.wav", NULL, &id);
			break;
		case '7':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "7.wav", NULL, &id);
			break;
		case '8':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "8.wav", NULL, &id);
			break;
		case '9':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "9.wav", NULL, &id);
			break;
		case '0':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "0.wav", NULL, &id);
			break;
		default:
			break;
		}

	}

	return 0;
}