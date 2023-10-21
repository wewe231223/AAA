#pragma once
#include "pch.h"
class SceneManager{
public:
	SceneManager();
	SceneManager(const SceneManager& other);

	~SceneManager();



public:


	void Read(const char* path);


};

