#pragma once
#include "pch.h"

class Camera{
public:
	Camera(ShaderID sid);
	Camera(const Camera& other);

	~Camera();

private:

	glm::vec3 EYE{10.f,10.f,10.f};
	glm::vec3 AT{1.f,1.f,0.f};
	glm::vec3 UP = Axis::Y;
	
	GLfloat FovY = 60.f;

	GLfloat NearZ = 0.1f;
	GLfloat FarZ = 2000.f;
	GLfloat Aspect = DEFAULT_WINDOW_WIDTHF / DEFAULT_WINDOW_HEIGHTF;

	glm::vec3 Basis_x = glm::normalize(-this->AT);
	glm::vec3 Basis_y = glm::normalize(glm::cross(this->UP, this->Basis_z));
	glm::vec3 Basis_z = glm::normalize(glm::cross(this->Basis_z, this->Basis_x));

	ShaderID m_ShaderID{};
	
	GLuint m_PerspectiveLocation{};
	GLuint m_CameraLocation{};


public:

	void update(DeltaTime dt);

	void Render(ShaderID shaderid);

};

