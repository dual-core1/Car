#ifndef VALUES
#define VALUES
#ifndef __IRRLICHT_H_INCLUDED__
#include <irrlicht.h>
#endif

using namespace irr;
using namespace video;
using namespace scene;

// world
extern ICameraSceneNode *camera;
extern ISceneNode *world;
extern ISceneNode *vehicle;

// graphics
extern ITexture *tex[3];

// graphics engine
extern IrrlichtDevice *device;
extern IVideoDriver *driver;
extern ISceneManager *scenemgr;
#endif