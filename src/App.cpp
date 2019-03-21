#include "window.h"
#include "fcolor.h"
#include "entity.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Window window = Window(L"3D framework Demo", 640, 600, new FloatColor(0xb5d1ff));

	return window.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}