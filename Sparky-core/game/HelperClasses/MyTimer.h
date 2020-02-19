#pragma once
#include <Windows.h>

class MyTimer
{
public:
	MyTimer();

	void reset();

	//returns seconds
	double elapsed();
private:
	LARGE_INTEGER m_Start;
	double m_Frequency;
};
