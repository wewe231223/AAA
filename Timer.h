#pragma once
#include "pch.h"


class Timer{
public: 
	Timer();
	Timer(const Timer& other);
	~Timer();

	bool Init();
	void Update();

	DeltaTime GetDeltaTime();
	DeltaTime GetAnimationDeltatime();
	int GetFps();
	
	void SetTimeScale(float);

private:

	INT64 m_frequency	= 0;
	INT64 m_startTime	= 0;

	float m_ticksPerMs	= 0.f;
	DeltaTime m_deltaTime	= 0.f;
	DeltaTime m_AnimationDeltaTime = 0.f;



	float m_FpsTime		= 0.f;
	int m_Frame			= 0;
	int m_Fps = 0;


	float m_TimeScale = 1.f;

};

