#include "Timer.h"

using namespace engine;

Timer::Timer()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	m_Frequency = frequency.QuadPart / 1000.0;

	QueryPerformanceCounter(&m_Start);
}

void Timer::reset()
{
	QueryPerformanceCounter(&m_Start);
}

//returns seconds
double Timer::elapsed()
{
	LARGE_INTEGER current;

	QueryPerformanceCounter(&current);
	unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
	return (double)((cycles / m_Frequency) / 1000.0);
}