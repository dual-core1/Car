#ifndef SIMULATION
#include "Simulation.h"
#endif

void Simulate()
{
	// gear change?
	if (ticksGearChange >= 60)
	{
		if (gear == DRIVE)
			gear = REVERSE;
		else if (gear == REVERSE)
			gear = DRIVE;

		ticksGearChange = 0;
	}

	// calculate vectors
	forwardVector = vector3df(sin(ToRadians(vehicle->getRotation().Y)), 0, cos(ToRadians(vehicle->getRotation().Y)));
	movementVector = forwardVector * speed;
	newPosition = vehicle->getPosition() + movementVector;

	// get key input
	if (receiver->GetKeyboardState().Down)
	{
		if (gear == DRIVE)
		{
			speed += accelRate;
		}
		else if (gear == REVERSE)
		{
			if (speed > -0.02)
			{
				ticksGearChange++;
			}
			else
			{
				if (speed + brakeRate > 0)
					speed = 0;
				else
					speed += brakeRate;
			}
		}
	}

	if (receiver->GetKeyboardState().Up)
	{
		if (gear == REVERSE)
		{
			speed -= accelRate;
		}
		else if (gear == DRIVE)
		{
			if (speed < 0.02)
			{
				ticksGearChange++;
			}
			else
			{
				if (speed - brakeRate < 0)
					speed = 0;
				else
					speed -= brakeRate;
			}
		}
	}

	if (receiver->GetKeyboardState().Left)
	{
		vehicle->setRotation(
			vector3df(
				vehicle->getRotation().X,
				vehicle->getRotation().Y + 2 * speed,
				vehicle->getRotation().Z
			)
		);
	}

	if (receiver->GetKeyboardState().Right)
	{
		vehicle->setRotation(
			vector3df(
				vehicle->getRotation().X,
				vehicle->getRotation().Y - 2 * speed,
				vehicle->getRotation().Z
			)
		);
	}

	// decelerate
	if (!receiver->GetKeyboardState().Up && !receiver->GetKeyboardState().Down)
	{
		if (speed < 0)
		{
			if (speed + decelRate > 0)
				speed = 0;
			else
				speed += decelRate;
		}

		if (speed > 0)
		{
			if (speed - decelRate < 0)
				speed = 0;
			else
				speed -= decelRate;
		}
	}

	// clamp speed
	if (speed < -1 * speedLim) speed = -1 * speedLim;
	if (speed > speedLim) speed = speedLim;

	// fix camera
	camera->setTarget(vehicle->getPosition());

	// reset keys
	receiver->reset();

	// move
	vehicle->setPosition(newPosition);
}