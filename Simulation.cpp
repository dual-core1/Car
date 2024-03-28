#ifndef SIMULATION
#include "Simulation.h"
#endif

void Simulate()
{
	// move the car
	vehicle->setPosition(core::vector3df(vehicle->getPosition().X, vehicle->getPosition().Y,
		vehicle->getPosition().Z + 5));

	camera->setTarget(vehicle->getPosition());
}