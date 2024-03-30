#ifndef ENGINE
#define ENGINE
#ifndef __IRRLICHT_H_INCLUDED__
#include <irrlicht.h>
#endif
#ifndef VALUES
#include "Values.h"
#endif
#ifndef INPUTEVENTRECEIEVER
#include "InputEventReceiver.h"
#endif

#include <iostream>
using std::cout;
using std::cin;

using namespace irr;
using namespace video;
using namespace scene;
using namespace core;
using namespace io;

void InitEngine();
void fail(const char *message);

#endif