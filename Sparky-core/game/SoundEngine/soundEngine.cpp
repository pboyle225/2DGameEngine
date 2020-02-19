#include "SoundEngine.h"

ISoundEngine * SoundEngine::soundEngine;

SoundEngine::SoundEngine()
{
}

SoundEngine::~SoundEngine()
{
	// After we are finished, we have to delete the irrKlang Device created earlier
	// with createIrrKlangDevice(). Use ::drop() to do that. In irrKlang, you should
	// delete all objects you created with a method or function that starts with 'create'.
	// (an exception is the play2D()- or play3D()-method, see the documentation or the
	// next example for an explanation)
	// The object is deleted simply by calling ->drop().

	soundEngine->drop(); // delete soundengine
}

void SoundEngine::init()
{
	//Audio stuff
	SoundEngine::soundEngine = createIrrKlangDevice();

	if (!soundEngine)
	{
		printf("Could not startup sound engine\n");
	}
}