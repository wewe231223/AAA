#pragma once
#include "pch.h"

class Camera{
public:
	Camera();
	Camera(const Camera& other);

	~Camera();

private:

	glm::vec3 EYE{10.f,10.f,10.f};
	glm::vec3 AT{1.f,1.f,0.f};
	glm::vec3 UP = Axis::Y;
	
	GLfloat FovY = 60.f;

	GLfloat NearZ = 0.1f;
	GLfloat FarZ = 1000.f;
	GLfloat Aspect = DEFAULT_WINDOW_WIDTHF / DEFAULT_WINDOW_HEIGHTF;

	glm::vec3 Basis_x = Axis::X;
	glm::vec3 Basis_y = Axis::Y;
	glm::vec3 Basis_z = Axis::Z;


public:

	void update(GLfloat dt);

	void Render(ShaderID shaderid);

};

