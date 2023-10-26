#pragma once
#include "pch.h"


constexpr auto Animation_None		= 0b0000'0000;
constexpr auto Animation_Revolution = 0b0000'0001;
constexpr auto Animation_Linear		= 0b0000'0010;
constexpr auto Animation_Rotation	= 0b0000'0100;



class Animation{
public:
	// Point need to Absolute from Original Position
	Animation(std::vector<glm::vec3>& PointList);
	Animation(GLfloat radius,glm::vec3 axis);



	~Animation();

	Animation(const Animation& other);

	Animation& operator=(const Animation& other) = delete;

private:
	BINARY Animationflag = Animation_None;
private:
	// Revolution Animation	

	glm::vec3* mptr_Center = nullptr;
	GLfloat rad = 0.f;

	glm::vec3 m_Axis{};

private:


	
	// Linear Animation
	std::unique_ptr<std::vector<glm::vec3>> mptr_PointList = nullptr;
	std::unique_ptr<GLfloat> mptr_t = nullptr;


public:

	void update(DeltaTime dt,glm::vec3& pos);


};

