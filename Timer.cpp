#include "Timer.h"

Timer::Timer()
{
}

Timer::Timer(const Timer& other)
{
}

Timer::~Timer()
{
}

bool Timer::Init()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&(this->m_frequency));
	if (m_frequency == 0) {
		// This System not provide High Performance Timer 
		std::cerr << "Timer Failure : This System does not provide high performance timer" << std::endl;
		exit(EXIT_FAILURE);
		return false;
	}


	this->m_ticksPerMs = static_cast<float>(this->m_frequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&(this->m_startTime));

	return true;
}

void Timer::Update(){
	
	if (this->m_TimeScale == 0.f) { return;  }
	
	INT64 currTime = 0;



	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	float dt = static_cast<float>(currTime - this->m_startTime);
	this->m_deltaTime = (dt / this->m_ticksPerMs) * this->m_TimeScale;
	this->m_startTime = currTime;
	
	

	this->m_Frame += 1;
	this->m_FpsTime += this->m_deltaTime;
	std::cout << this->m_deltaTime << std::endl;

	if (m_FpsTime >= 1.f) {
		this->m_Fps = this->m_Frame;
		this->m_Frame = 0;
		this->m_FpsTime = 0;
	}
	


}

float Timer::GetDeltaTime()
{
	return this->m_deltaTime;
}

int Timer::GetFps() {
	return this->m_Fps;
}

void Timer::SetTimeScale(float Scale) {
	this->m_TimeScale = Scale;
}