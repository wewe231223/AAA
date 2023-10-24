#pragma once
#include "pch.h"

constexpr auto Animation_None		= 0b0000'0000;
constexpr auto Animation_Revolution = 0b0000'0001;
constexpr auto Animation_Linear		= 0b0000'0010;



class Animation{
public:
	// Point need to Absolute from Original Position
	Animation(std::vector<glm::vec3>& PointList);
	Animation(glm::vec3* CenterNormal,GLfloat radius);



	~Animation();

	Animation(const Animation& other);

	Animation& operator=(const Animation& other) = delete;

private:
	BINARY Animationflag = Animation_None;
private:
	// Revolution Animation	

	std::unique_ptr<glm::vec3*> mptr_Center = nullptr;
	std::unique_ptr<GLfloat> mptr_theta = nullptr;


private:



	// Linear Animation
	std::unique_ptr<std::vector<glm::vec3>> mptr_PointList = nullptr;
	std::unique_ptr<GLfloat> mptr_t = nullptr;


public:

	void update(DeltaTime dt);


};

