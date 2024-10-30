#ifndef _LEARN_GDI_PLUS_H_
#define _LEARN_GDI_PLUS_H_

#include "resource.h"
#include <Windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")


VOID OnPaint(HDC hdc);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


#endif