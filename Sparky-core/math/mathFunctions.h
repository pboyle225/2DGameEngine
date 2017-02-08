#pragma once

#define _USE_MATH_DEFINES
#include <math.h>


namespace engine {
	namespace math {

		inline float toRaidians(float degrees)
		{
			return (float)(degrees * ((float)M_PI / 180.0f));
		}

	}
}