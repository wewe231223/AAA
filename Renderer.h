#pragma once
#include "pch.h"
#include "Camera.h"
#include "Coord.h"


class Renderer{
	
public:
	Renderer(ShaderID sid);
	Renderer(const Renderer& other);
	~Renderer();




private:
	
	std::unique_ptr<Camera> m_Camera{};
	std::unique_ptr<Coord> m_Coord{};


public:

	void update(GLfloat dt);
	void render(ShaderID sid);

};

