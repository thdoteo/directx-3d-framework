#include "window.h"
#include "fcolor.h"
#include "entity.h"

#include "cuboid.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	Window window = Window(L"3D framework Demo", 640, 600, new FloatColor(0xb5d1ff));

	Cuboid *quad1 = new Cuboid(0.0f, 0.0f, 0.0f, new FloatColor(0x75aaff));
	Cuboid *quad2 = new Cuboid(2.0f, 0.0f, 0.0f, new FloatColor(0x000000));
	window.addEntity(quad1);
	window.addEntity(quad2);

	return window.Start(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}