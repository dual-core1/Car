#ifndef VEHICLES
#include "Vehicles.h"
#endif

bool LoadVehicle()
{
	vehicle = scenemgr->addAnimatedMeshSceneNode(
		scenemgr->getMesh("../Models/Sedan/sedan.3ds"), 0, -1,
		core::vector3df(vX, vY, vZ), core::vector3df(0, vYaw, 0));

	if (!vehicle) return false;
	
	vehicle->setMaterialFlag(EMF_LIGHTING, 0);
	wheelMesh = scenemgr->getMesh("../Models/Wheel1/wheel1.3ds");

	if (!wheelMesh) return false;

	for (int i = 0; i < 4; i++)
	{
		wheels[i] = scenemgr->addAnimatedMeshSceneNode(
			wheelMesh, vehicle, -1, core::vector3df(wX[i], wY[i], wZ[i]),
			core::vector3df(0, wYaw[i], 0));

		wheels[i]->setMaterialFlag(EMF_LIGHTING, 0);
	}

	return true;
}
