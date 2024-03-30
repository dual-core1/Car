#ifndef INPUTEVENTRECEIEVER
#include "InputEventReceiver.h"
#endif

bool InputEventReceiver::OnEvent(const SEvent &event)
{
	if (event.EventType == EET_KEY_INPUT_EVENT)
	{
		if (event.KeyInput.Key == KEY_UP)
			KeyboardState.Up = true;

		if (event.KeyInput.Key == KEY_DOWN)
			KeyboardState.Down = true;

		if (event.KeyInput.Key == KEY_LEFT)
			KeyboardState.Left = true;

		if (event.KeyInput.Key == KEY_RIGHT)
			KeyboardState.Right = true;

		if (event.KeyInput.Key == KEY_ESCAPE)
			KeyboardState.Escape = true;

		if (event.KeyInput.Key == KEY_SPACE)
			KeyboardState.Space = true;
	}

	return false;
}

void InputEventReceiver::reset()
{
	KeyboardState.Down = false;
	KeyboardState.Escape = false;
	KeyboardState.Left = false;
	KeyboardState.Right = false;
	KeyboardState.Space = false;
	KeyboardState.Up = false;
}

const InputEventReceiver::SKeyboardState &InputEventReceiver::GetKeyboardState()
{
	return KeyboardState;
}
