#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
 
// Keyhook.cpp : Defines the entry point for the console application.
// by B1ackAnge1
// Alt-F12 Exits app
// All you leechers have to do is parse the vkCode ;)
#include "stdafx.h"
using namespace std;

HHOOK hHook;

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam, LPARAM lParam)
{
	if(wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
	{
		PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;
                //Now just check pKey->vkCode etc for whatever you want
                //for instance, a basic printout of the value and a check for pgup
		cout << pKey->vkCode << " ";
		
		// cout << (char*) pKey->vkCode << " ";
		// ���� int���� �ƴ�, char ����� �ʿ��ϴٸ� ���� ������ ����ϼ���.
		// ().+����Ʈ,��Ʈ�� ��� Ư�� Ű ����� ���� Ű���� ���̺� �� �����ؼ� �ڵ��ϸ� �˴ϴ�.
		
		if(pKey->vkCode == VK_PRIOR){
			cout << endl << "Page Up!" << endl;
		}
			
	}
		CallNextHookEx(hHook,nCode,wParam,lParam);
		return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	RegisterHotKey(NULL,0xB1AC7B1A,MOD_ALT,VK_F12);
	HMODULE hInstance = GetModuleHandle(NULL);
	hHook = SetWindowsHookEx(WH_KEYBOARD_LL,KeyboardProc,hInstance,NULL);
	MSG msg;
	GetMessage(&msg,NULL,NULL,NULL);
	UnhookWindowsHookEx(hHook);
	return 0;
}


