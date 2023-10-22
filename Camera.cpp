#include "Camera.h"
constexpr auto Coefficient_Camera_Rotate = 80.f;
constexpr auto Coefficient_Camera_Movement = 50.f;


Camera::Camera(ShaderID sid){

	this->m_ShaderID = sid;
	this->m_PerspectiveLocation = glGetUniformLocation(this->m_ShaderID, "perspective");
	this->m_CameraLocation = glGetUniformLocation(this->m_ShaderID, "lookat");
}

Camera::Camera(const Camera& other)
{
}

Camera::~Camera()
{
}

void Camera::update(GLfloat dt){

	glm::vec3 CamerMove{0.f,0.f,0.f};


	if (GetAsyncKeyState('A') & 0x08000) {
		CamerMove.x += dt * Coefficient_Camera_Movement;
	}

	if (GetAsyncKeyState('D') & 0x08000) {
		CamerMove.x -= dt * Coefficient_Camera_Movement;
	}


	if (GetAsyncKeyState('W') & 0x08000) {
		CamerMove.z += dt * Coefficient_Camera_Movement;
	}

	if (GetAsyncKeyState('S') & 0x08000) {
		CamerMove.z -= dt * Coefficient_Camera_Movement;
	}


	if (GetAsyncKeyState('E') & 0x08000) {
		CamerMove.y += dt * Coefficient_Camera_Movement;
	}

	if (GetAsyncKeyState('Q') & 0x08000) {
		CamerMove.y -= dt * Coefficient_Camera_Movement;
	}

	glm::vec3 RotateFactor = glm::vec3{};


	if (GetAsyncKeyState(VK_LEFT)) {
		RotateFactor.x += dt * Coefficient_Camera_Rotate;
	}

	
	if (GetAsyncKeyState(VK_RIGHT)) {
		RotateFactor.x -= dt * Coefficient_Camera_Rotate;
	}


	if (GetAsyncKeyState(VK_DOWN)) {
		RotateFactor.y -= dt * Coefficient_Camera_Rotate;
	}


	if (GetAsyncKeyState(VK_UP)) {
		RotateFactor.y += dt * Coefficient_Camera_Rotate;
	}


	this->EYE += -1.f * (this->Basis_x * CamerMove.x);
	this->EYE += -1.f * (this->Basis_z * CamerMove.z);
	this->EYE += -1.f * (Axis::Y * CamerMove.y);


	if (glm::IsValue(RotateFactor)) {
		glm::mat4 Mat_Camera_Rotate{ 1.f };


		Mat_Camera_Rotate = glm::rotate(Mat_Camera_Rotate, glm::radians(RotateFactor.x), this->Basis_y);
		Mat_Camera_Rotate = glm::rotate(Mat_Camera_Rotate, glm::radians(RotateFactor.y), this->Basis_x);


		this->AT = glm::normalize(glm::vec3(Mat_Camera_Rotate * glm::vec4(this->AT, 1.f)));

		this->Basis_z = glm::normalize(-this->AT);
		this->Basis_x = glm::normalize(glm::cross(this->UP, this->Basis_z));
		this->Basis_y = glm::normalize(glm::cross(this->Basis_z, this->Basis_x));
	}
}

void Camera::Render(ShaderID shaderid){



	this->Aspect = static_cast<float>(glutGet(GLUT_WINDOW_WIDTH)) / static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));
	glUniformMatrix4fv(this->m_PerspectiveLocation, 1, GL_FALSE, glm::value_ptr(glm::perspective(glm::radians(this->FovY), this->Aspect, this->NearZ, this->FarZ)));
	glUniformMatrix4fv(this->m_CameraLocation, 1, GL_FALSE, glm::value_ptr(glm::lookAt(this->EYE, this->AT + this->EYE, this->UP)));
}



