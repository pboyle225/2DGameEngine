#pragma once
#include <iostream>
#include "irrKlang.h"


using namespace irrklang;

	static class SoundEngine
	{
	public:
		
		static ISoundEngine* soundEngine;
		static void init();
		
		SoundEngine();
		~SoundEngine();

	private:

	};