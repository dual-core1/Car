#ifndef __IRRLICHT_H_INCLUDED__
#include <irrlicht.h>
#endif
#ifndef VALUES
#include "Values.h"
#endif
#ifndef WORLD
#include "World.h"
#endif

#include <iostream>
using std::cout;
using std::cin;

using namespace irr;
using namespace video;
using namespace scene;
using namespace core;
using namespace io;

void fail(int cond);

int main()
{
	bool result;

    // INITIATE ENGINE
	device = createDevice(EDT_DIRECT3D9, dimension2d<u32>(1024, 768), 32U, 1); // Why 1024x768? So I can run this on my ThinkPad T60!
	if (!device) fail(0);

	driver = device->getVideoDriver();
	if (!driver) fail(1);

	scenemgr = device->getSceneManager();
	if (!scenemgr) fail(2);

	device->setWindowCaption(L"Simulation");

	// LOAD WORLD
	result = LoadTextures();
	if (!result) fail(3);

	result = LoadWorld();
	if (!result) fail(4);
	
	// MAIN LOOP (for now, this is where it is)
	while (device->run() && driver)
	{
		driver->beginScene(1, 1, SColor(255, 174, 248, 255));
		scenemgr->drawAll();
		driver->endScene();
	}

	device->drop();
	return 0;
}

void fail(int cond)
{
	switch (cond)
	{
	case 0:
		cout << "ERROR: Failed to create Direct3D 9 device.\n";
		break;
	case 1:
		cout << "ERROR: Failed to get video driver.\n";
		break;
	case 2:
		cout << "ERROR: Failed to get scene manager.\n";
		break;
	case 3:
		cout << "ERROR: Couldn't load textures.";
		break;
	case 4:
		cout << "ERROR: Couldn't load world.\n";
		break;
	}
}
