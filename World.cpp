#ifndef WORLD
#include "World.h"
#endif

bool LoadTextures()
{
	tex[0] = driver->getTexture("Models/City/texture1.bmp");
	tex[1] = driver->getTexture("Models/City/texture2.bmp");
	tex[2] = driver->getTexture("Models/City/texture3.bmp");

	return true;
}

bool LoadWorld()
{
	world = scenemgr->addAnimatedMeshSceneNode(
		scenemgr->getMesh("Models/City/city.3ds"));
	
	if (!world) return false;
	/*
	world->getMaterial(0).setTexture(0, tex[0]);

	
	for (int i = 0; i < 3; i++)
	{
		world->getMaterial(i).setTexture(0, tex[i]);
	}
	*/
	world->setMaterialFlag(EMF_LIGHTING, false);

	// create camera and set its position to 325, 20, -2
	camera = scenemgr->addCameraSceneNode(0, core::vector3df(325, 20, -2));

	return true;
}
