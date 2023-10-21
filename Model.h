#pragma once
#include "pch.h"

class Model{
public:
	VertexArrayObject m_Vao{};
	VertexPositionBufferObject m_Vpbo{};
	VertexColorBufferObject m_Vcpo{};

	glm::vec3 m_Position{};
	
	Rotation m_Rotation{};

public:

	Model(glm::vec3 pos,Rotation rot);


};

