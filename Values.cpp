#ifndef VALUES
#include "Values.h"
#endif

// world
extern ICameraSceneNode *camera = NULL;
extern ISceneNode *world = NULL;

// vehicles
extern ISceneNode *vehicle = NULL;
extern ISceneNode *wheels[4] = { NULL, NULL, NULL, NULL };
extern IAnimatedMesh *wheelMesh = NULL;
extern float vX = 0.0;
extern float vY = 10.0;
extern float vZ = 0.0;
extern float vYaw = 180.0;
extern float wX[4] = { 5.8, -5.8, 5.8, -5.8 };
extern float wY[4] = { -6.0, -6.0, -6.0, -6.0 };
extern float wZ[4] = { -8.6, -8.6, 8.6, 8.6 };
extern float wYaw[4] = { 0.0, 180.0, 0.0, 180.0 };

// graphics
extern ITexture *tex[13] = { NULL, NULL, NULL };

// sounds
/*extern Mix_Chunk* sAccel = NULL;
extern Mix_Chunk* sDecel = NULL;
extern Mix_Chunk* sIdle = NULL;
extern Mix_Chunk* sRev = NULL;*/

// engine
extern IrrlichtDevice *device = NULL;
extern IVideoDriver *driver = NULL;
extern ISceneManager *scenemgr = NULL;