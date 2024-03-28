#ifndef ENGINE
#include "Engine.h"
#endif

void InitEngine()
{
	int res;

	cout << "Select resolution: [1] for lo-res, [2] for hi-res\n";
	cin >> res;

	if (res == 1)
	{
		device = createDevice(EDT_DIRECT3D9, dimension2d<u32>(1024, 768), 32U, 1);
	}
	else if (res == 2)
	{
		device = createDevice(EDT_DIRECT3D9, dimension2d<u32>(1280, 720), 32U, 1);
	}
	else
	{
		exit(0);
	}

	if (!device) fail("ERROR: Failed to create Direct3D 9 device.\n");

	driver = device->getVideoDriver();
	if (!driver) fail("ERROR: Failed to get video driver.\n");

	scenemgr = device->getSceneManager();
	if (!scenemgr) fail("ERROR: Failed to get scene manager.\n");

	device->setWindowCaption(L"Simulation");
}

void fail(const char* message)
{
	cout << message;
	exit(-1);
}