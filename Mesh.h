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

	GLuint m_VertexCount{};


	VertexArrayObject m_VAO{};
	VertexPositionBufferObject m_VPBO{};
	VertexColorBufferObject m_VCBO{};
	VertexElementObject m_EBO{};

public:

	VertexArrayObject GetVao() { return this->m_VAO; };
	GLuint GetVertexCount() { return this->m_VertexCount; };


};
