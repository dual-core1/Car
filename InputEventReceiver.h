#ifndef INPUTEVENTRECEIVER
#define INPUTEVENTRECEIVER
#ifndef __IRRLICHT_H_INCLUDED__
#include <irrlicht.h>
#endif

using namespace irr;
using namespace video;
using namespace scene;
using namespace core;
using namespace io;

class InputEventReceiver :
	public IEventReceiver
{
public:
	struct SKeyboardState
	{
		bool Up;
		bool Down;
		bool Left;
		bool Right;
		bool Space;
		bool Escape;
		SKeyboardState() : Up(false), Down(false), Left(false),
		Right(false), Space(false), Escape(false) {}
	} KeyboardState;

	virtual bool OnEvent(const SEvent &event);
	void reset();
	const SKeyboardState &GetKeyboardState();
};

#endif
