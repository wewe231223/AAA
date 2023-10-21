#pragma once
#include "pch.h"

class Mesh {
public:
	Mesh(std::string path);
	~Mesh() {};

private:


	std::vector<glm::vec3> Verties{};
	std::vector<glm::vec2> UV{};
	std::vector<glm::vec3> Normal{};

	std::vector<GLuint> VertexIndices{};
	std::vector<GLuint> UvIndices{};
	std::vector<GLuint> NormalIndices{};


	std::fstream File{};

	VertexArrayObject m_VAO{};
	VertexPositionBufferObject m_VPBO{};
	VertexColorBufferObject m_VCBO{};
	VertexElementObject m_EBO{};

public:



};
