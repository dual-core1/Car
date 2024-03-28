#ifndef WORLD
#include "World.h"
#endif

void LoadTextures()
{
	tex[0] = driver->getTexture("../Models/City/texture1.bmp");
	tex[1] = driver->getTexture("../Models/City/texture2.bmp");
	tex[2] = driver->getTexture("../Models/City/texture3.bmp");
	tex[3] = driver->getTexture("../Models/Sedan/texture1.bmp");
	tex[4] = driver->getTexture("../Models/Sedan/texture2.bmp");
	tex[5] = driver->getTexture("../Models/Sedan/texture3.bmp");
	tex[6] = driver->getTexture("../Models/Sedan/texture4.bmp");
	tex[7] = driver->getTexture("../Models/Sedan/texture5.bmp");
	tex[8] = driver->getTexture("../Models/Sedan/texture6.bmp");
	tex[9] = driver->getTexture("../Models/Sedan/texture7.bmp");
	tex[10] = driver->getTexture("../Models/Sedan/texture8.bmp");
	tex[11] = driver->getTexture("../Models/Wheel1/texture1.bmp");
	tex[12] = driver->getTexture("../Models/Wheel1/texture2.bmp");
}

bool LoadWorld()
{
	world = scenemgr->addAnimatedMeshSceneNode(
		scenemgr->getMesh("../Models/City/city.3ds"));
	
	if (!world) return false;
	world->setMaterialFlag(EMF_LIGHTING, 0);
	
	return true;
}
