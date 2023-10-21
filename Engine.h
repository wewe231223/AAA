#pragma once
#include "pch.h"
#include "Definition.h"
#include "Shader.h"
#include "Timer.h"
#include "MeshManager.h"

class Engine{
private:

	Engine() = default;
	~Engine() = delete;
	Engine(const Engine& other) = delete;
	Engine& operator=(const Engine& other) = delete;

private:

	static Engine* EngineInstance;



private:


	std::unique_ptr<Shader> m_Shader{};
	std::unique_ptr<Timer> m_Timer{};
	std::unique_ptr<MeshManager> m_MeshManager{};


public:

	static Engine* GetInstance(int* ,char**);
	static Engine* GetInstance();

	void Run();
	void Update();

	void VsyncUpdate(bool onoff);

	ShaderID GetShader() { return this->m_Shader->GetShaderID(); }




};

