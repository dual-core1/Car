#ifndef VALUES
#include "Values.h"
#endif

// world
extern ICameraSceneNode *camera = NULL;
extern ISceneNode *world = NULL;

// simulation
extern float speedLim = 7.0;
extern float currSpeedX = 0.0;
extern float currSpeedY = 0.0;
extern float currSpeedZ = 0.0;
extern float accelRate = 0.5;
extern float decelRate = 0.02;
extern float brakeRate = 2;
extern int gear = 1; // 1 = drive, 0 = reverse
extern int ticksGearChange = 0;
extern bool accel = false;
extern bool rev = false;
extern bool idle = true;

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
extern InputEventReceiver *receiver = new InputEventReceiver();