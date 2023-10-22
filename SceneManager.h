#pragma once
#include "pch.h"
#include "MeshManager.h"
#include "Model.h"

class SceneManager{
public:
	SceneManager();
	SceneManager(const SceneManager& other);

	~SceneManager();


private:

	std::unique_ptr<MeshManager> m_MeshManager;


public:


	void Read(const char* path);


};

