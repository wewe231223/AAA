#pragma once
#include "pch.h"
#include "Definition.h"
#include "Shader.h"
#include "Timer.h"
#include "MeshManager.h"
#include "Renderer.h"
#include "SceneManager.h"


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
	std::unique_ptr<Renderer> m_Renderer{};
	std::unique_ptr<SceneManager> m_SceneManager{};

private:

	

public:

	static Engine* GetInstance(int* ,char**);
	static Engine* GetInstance();

	void Run();
	void update();
	void render();

	void VsyncUpdate(bool onoff);


	const ShaderID GetShader() { return this->m_Shader->GetShaderID(); }
	

	void SetCoordRenderMode(CoordRender_Flag f) { this->m_Renderer->SetCoordRenderMode(f); }



};

