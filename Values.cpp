#ifndef VALUES
#include "Values.h"
#endif

// world
extern ICameraSceneNode *camera = NULL;
extern ISceneNode *world = NULL;
extern ISceneNode *vehicle = NULL;

// graphics
extern ITexture *tex[3] = { NULL, NULL, NULL };

// graphics engine
extern IrrlichtDevice *device = NULL;
extern IVideoDriver *driver = NULL;
extern ISceneManager *scenemgr = NULL;