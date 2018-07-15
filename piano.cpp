// ConsoleApplication8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include<graphics.h>
#include<mmsystem.h>
#include<string>
#pragma comment(lib,"winmm.lib")

IMAGE pic[14];
IMAGE grey;

void init()
{
	//加载图片
	char add[256];
	int i = 0;
	for (; i < 14; i++)
	{
		memset(add, 0, 256);
		sprintf_s(add, "pics\\%d.jpg", i + 1);
		loadimage(&pic[i], add);
	}
	loadimage(&grey, "pics\\grey.jpg");

	//贴图
	for (i = 0; i < 14; i++)
	{
		putimage(i * 80, 0, &pic[i]);
	}
}

DWORD proc(LPVOID lpThreadParameter) 
{
	char buff[256] = { 0 };
	sprintf_s(buff, "open sounds\\%s alias m", (char*)lpThreadParameter);
	char* str = (char*)lpThreadParameter;
	int a = strlen(str);
	int index;
	if (a == 5)
	{
		index = ((char*)lpThreadParameter)[0] - '0';
	}
	else if (a == 6)
	{
		index = 10 + ((char*)lpThreadParameter)[1] - '0';
	}

	putimage((index - 1) * 80, 0, &grey);

	mciSendString(buff, 0, 0, 0);//打开
	mciSendString("play m", 0, 0, 0);//播放
	Sleep(300);//声音持续时间
	//mciSendString("close m", 0, 0, 0);//关闭 让它自动关闭
	putimage((index - 1) * 80, 0, &pic[index - 1]);
	return 0;

}

/*自动播放
char music[] = { 'a','s','d','f','g','h','j','r','t','y','u','i','o','p' };
VOID(timeProc(HWND hWnd, UINT uInt, UINT_PTR ptr, DWORD dWord)) {
	int x = strlen(music);
	for (int i = 0; i < x; i++) {
		switch (music[i]) {
		case 'a':SendMessage(hWnd, WM_KEYDOWN, 97, NULL); break;
		case 's':SendMessage(hWnd, WM_KEYDOWN, 115, NULL); break;
		case 'd':SendMessage(hWnd, WM_KEYDOWN, 100, NULL); break;
		case 'f':SendMessage(hWnd, WM_KEYDOWN, 102, NULL); break;
		case 'g':SendMessage(hWnd, WM_KEYDOWN, 103, NULL); break;
		case 'h':SendMessage(hWnd, WM_KEYDOWN, 104, NULL); break;
		case 'j':SendMessage(hWnd, WM_KEYDOWN, 106, NULL); break;
		case 'r':SendMessage(hWnd, WM_KEYDOWN, 114, NULL); break;
		case 't':SendMessage(hWnd, WM_KEYDOWN, 116, NULL); break;
		case 'y':SendMessage(hWnd, WM_KEYDOWN, 121, NULL); break;
		case 'u':SendMessage(hWnd, WM_KEYDOWN, 117, NULL); break;
		case 'i':SendMessage(hWnd, WM_KEYDOWN, 105, NULL); break;
		case 'o':SendMessage(hWnd, WM_KEYDOWN, 111, NULL); break;
		case 'p':SendMessage(hWnd, WM_KEYDOWN, 112, NULL); break;
		default:
			break;
		}
	}
}*/

int main()
{
	int c;
	DWORD id;
	HWND hWnd = initgraph(1120, 500, SHOWCONSOLE);
	init();
	/*自动播放 
	SetTimer(hWnd, 8880, 500, (TIMERPROC)timeProc);*/
	while (1)
	{
		c = _getch();
		printf("%d\n", c);
		switch (c)
		{
		case 'a'://中央c
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "1.wav", NULL, &id);
			break;
		case 's'://re
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "2.wav", NULL, &id);
			break;
		case 'd'://mi
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "3.wav", NULL, &id);
			break;
		case 'f'://fa
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "4.wav", NULL, &id);
			break;
		case 'g'://so
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "5.wav", NULL, &id);
			break;
		case 'h'://la
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "6.wav", NULL, &id);
			break;
		case 'j'://ti
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "7.wav", NULL, &id);
			break;
		case 'r'://高音区 do
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "8.wav", NULL, &id);
			break;
		case 't':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "9.wav", NULL, &id);
			break;
		case 'y':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "10.wav", NULL, &id);
			break;
		case 'u':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "11.wav", NULL, &id);
			break;
		case 'i':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "12.wav", NULL, &id);
			break;
		case 'o':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "13.wav", NULL, &id);
			break;
		case 'p':
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc, "14.wav", NULL, &id);
			break;
		default:
			break;
		}
	}
    return 0;
}

