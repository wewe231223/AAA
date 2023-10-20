#pragma once
#include "pch.h"
#include "Definition.h"
#include "Shader.h"

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




public:

	static Engine* GetInstance(int* ,char**);
	static Engine* GetInstance();

	void Run();

	ShaderID GetShader() { return this->m_Shader->GetShaderID(); }



};

