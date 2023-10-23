#pragma once
#include "pch.h"

enum Animation_Prefabs {
	Circle
};


class Animation{
public:
	// Point need to Absolute from Original Position
	Animation(std::vector<glm::vec3>& PointList);

	Animation(Animation_Prefabs pf,glm::vec3 pos);
	~Animation();

	Animation(const Animation& other);

	Animation& operator=(const Animation& other) = delete;

private:
	std::vector<glm::vec3> m_PointList{};
	GLfloat t = 0.f;

public:



};

	