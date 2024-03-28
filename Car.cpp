#ifndef ENGINE
#include "Engine.h"
#endif
#ifndef VEHICLES
#include "Vehicles.h"
#endif
#ifndef WORLD
#include "World.h"
#endif
#ifndef SIMULATION
#include "Simulation.h"
#endif

int main(int argc, char** argv)
{
	int ticks = 0;
	int elapsed = 0;
	float delta = 0.0;
	bool result;


	InitEngine();	
	ITimer *timer = device->getTimer();

	LoadTextures();

	result = LoadWorld();
	if (!result) fail("ERROR: Couldn't load world.\n");

	result = LoadVehicle();
	if (!result) fail("ERROR: Couldn't load vehicle.\n");

	camera = scenemgr->addCameraSceneNode(vehicle, core::vector3df(0, 15, 50), vehicle->getPosition());
	
	// MAIN LOOP
	while (device->run() && driver)
	{
		timer->start();
		ticks = timer->getTime();
		do
		{
			timer->tick();
			elapsed = timer->getTime() - ticks;
		} while (elapsed < 1000.0 / 30);
		timer->stop();
		driver->beginScene(1, 1, SColor(255, 200, 200, 200));
		Simulate();
		scenemgr->drawAll();
		driver->endScene();
	}

	device->drop();
	return 0;
}
