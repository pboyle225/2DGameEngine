#pragma once

//TODO: MAKE CROSS PLATTFORM
#include <Windows.h>


namespace engine {

	class Timer
	{
	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);

			m_Frequency = frequency.QuadPart / 1000.0;

			QueryPerformanceCounter(&m_Start);
		}

		void reset()
		{
			QueryPerformanceCounter(&m_Start);
		}

		//return seconds
		float elapsed()
		{
			LARGE_INTEGER current;

			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)((cycles / m_Frequency) / 1000.0f);
		}
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
	};
}
