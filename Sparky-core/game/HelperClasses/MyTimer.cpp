#include "MyTimer.h"

MyTimer::MyTimer()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	m_Frequency = frequency.QuadPart / 1000.0;

	QueryPerformanceCounter(&m_Start);
}

void MyTimer::reset()
{
	QueryPerformanceCounter(&m_Start);
}

//returns seconds
double MyTimer::elapsed()
{
	LARGE_INTEGER current;

	QueryPerformanceCounter(&current);
	unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
	return (double)((cycles / m_Frequency) / 1000.0);
}