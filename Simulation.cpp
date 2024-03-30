#ifndef SIMULATION
#include "Simulation.h"
#endif

void Simulate()
{
	// gear change?
	if (ticksGearChange >= 60)
	{
		if (gear == 1)
			gear = 0;
		else if (gear == 0)
			gear = 1;

		ticksGearChange = 0;
	}

	// get key input
	if (receiver->GetKeyboardState().Up)
	{
		if (gear == 1)
		{
			currSpeedZ = currSpeedZ - accelRate * cos(ToRadians(vehicle->getRotation().Y));
			currSpeedX = currSpeedX - accelRate * sin(ToRadians(vehicle->getRotation().Y));
		}
		else
		{
			if (currSpeedZ + currSpeedX <= 0.02)
				ticksGearChange++;
			else
			{
				currSpeedZ = currSpeedZ + brakeRate * cos(ToRadians(vehicle->getRotation().Y));
				currSpeedX = currSpeedX + brakeRate * sin(ToRadians(vehicle->getRotation().Y));


				// clamp
				if (currSpeedZ < 0) currSpeedZ = 0;
				if (currSpeedX < 0) currSpeedX = 0;
			}
		}
	}

	if (receiver->GetKeyboardState().Down)
	{
		if (gear == 0)
		{
			currSpeedZ = currSpeedZ + accelRate * cos(ToRadians(vehicle->getRotation().Y));
			currSpeedX = currSpeedX + accelRate * sin(ToRadians(vehicle->getRotation().Y));
		}
		else
		{
			if (currSpeedZ + currSpeedX >= -0.02)
				ticksGearChange++;
			else
			{
				currSpeedZ = currSpeedZ - brakeRate * cos(ToRadians(vehicle->getRotation().Y));
				currSpeedX = currSpeedX - brakeRate * sin(ToRadians(vehicle->getRotation().Y));

				// clamp
				if (currSpeedZ > 0) currSpeedZ = 0;
				if (currSpeedX > 0) currSpeedX = 0;
			}
		}
	}

	if (receiver->GetKeyboardState().Left)
	{
		vehicle->setRotation(vector3df(vehicle->getRotation().X, vehicle->getRotation().Y - 10, vehicle->getRotation().Z));
	}

	if (receiver->GetKeyboardState().Right)
	{
		vehicle->setRotation(vector3df(vehicle->getRotation().X, vehicle->getRotation().Y + 10, vehicle->getRotation().Z));
	}

	if (!receiver->GetKeyboardState().Up && !receiver->GetKeyboardState().Down)
	{
		ticksGearChange = 0;
	}

	// clamp speed
	if (currSpeedX > speedLim)
		currSpeedX = speedLim;

	if (currSpeedX < -1 * speedLim)
		currSpeedX = -1 * speedLim;

	if (currSpeedZ > speedLim)
		currSpeedZ = speedLim;

	if (currSpeedZ < -1 * speedLim)
		currSpeedZ = -1 * speedLim;

	// decelerate
	if (currSpeedZ < 0)
		currSpeedZ += decelRate * cos(ToRadians(vehicle->getRotation().Y));
	else if (currSpeedZ > 0)
		currSpeedZ -= decelRate * cos(ToRadians(vehicle->getRotation().Y));

	if (currSpeedX < 0)
		currSpeedX += decelRate * sin(ToRadians(vehicle->getRotation().Y));
	else if (currSpeedX > 0)
		currSpeedX -= decelRate * sin(ToRadians(vehicle->getRotation().Y));


	// fix camera
	camera->setTarget(vehicle->getPosition());

	// reset keys
	receiver->reset();

	// let's go go go!
	vehicle->setPosition(vector3df(vehicle->getPosition().X + currSpeedX * sin(ToRadians(vehicle->getRotation().Y)),
		vehicle->getPosition().Y,
		vehicle->getPosition().Z + currSpeedZ * cos(ToRadians(vehicle->getRotation().Y))));
}