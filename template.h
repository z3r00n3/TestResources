#pragma once

// Link to GDK libraries
#include "AGK.h"

#define DEVICE_WIDTH 1024
#define DEVICE_HEIGHT 768
#define DEVICE_POS_X 32
#define DEVICE_POS_Y 32
#define FULLSCREEN false

// used to make a more unique folder for the write path
#define COMPANY_NAME "My Company"

// Global values for the app
class app
{
private:
	int red, yellow, green, blue, lightBlue;
	float xP, yP, xR, yR, xHeld, yHeld;
	int spriteHit, lastSpriteHit;
	bool hiddenText;

public:

	// constructor
	app();

	// main app functions - mike to experiment with a derived class for this..
	void Begin();
	int Loop();
	void End();
};

extern app App;

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif