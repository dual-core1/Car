#ifndef VALUES
#define VALUES
#ifndef __IRRLICHT_H_INCLUDED__
#include <irrlicht.h>
#endif
#ifndef INPUTEVENTRECEIVER
#include "InputEventReceiver.h"
#endif

using namespace irr;
using namespace video;
using namespace scene;

// world
extern ICameraSceneNode *camera;
extern ISceneNode *world;

// simulation
extern float speedLim;
extern float currSpeedX;
extern float currSpeedY;
extern float currSpeedZ;
extern float accelRate;
extern float decelRate;
extern float brakeRate;
extern int gear;
extern int ticksGearChange;
extern bool accel;
extern bool rev;
extern bool idle;


// vehicles
extern ISceneNode *vehicle;
extern ISceneNode *wheels[4];
extern IAnimatedMesh *wheelMesh;
extern float vX;
extern float vY;
extern float vZ;
extern float vYaw;
extern float wX[4];
extern float wY[4];
extern float wZ[4];
extern float wYaw[4];

// graphics
extern ITexture *tex[13];

// sounds
/*
extern Mix_Chunk* sAccel;
extern Mix_Chunk* sDecel;
extern Mix_Chunk* sIdle;
extern Mix_Chunk* sRev;
*/
// engine
extern IrrlichtDevice *device;
extern IVideoDriver *driver;
extern ISceneManager *scenemgr;
extern InputEventReceiver *receiver;
#endif