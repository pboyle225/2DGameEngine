#pragma once
#include <Windows.h>

namespace engine {

	class Timer
	{
	public:
		Timer();

		void reset();

		//returns seconds
		double elapsed();
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
	};
}
