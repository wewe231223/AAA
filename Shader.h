#pragma once
#include "pch.h"

class Shader{
private:
	VertexShaderID m_VertexID{};
	FragmentShaderID m_FragID{};
	ShaderID m_ShaderID{};

public:
	Shader(const char* VertexShaderPath,const char* FragmentShaderPath);

	ShaderID GetShaderID() { return this->m_ShaderID; }



};

