#include "Mesh.h"
#include "Random.h"

Mesh::Mesh(std::string path){


	const GLchar* Filepath = path.c_str();

	this->File.open(Filepath);

	if (!this->File) {
		std::cerr << "OBJ FILE ERROR!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cerr << path.c_str() << " is Sucessfully Opened! " << std::endl;
	}



	std::vector<glm::vec3>().swap(this->Verties);
	std::vector<glm::vec2>().swap(this->UV);
	std::vector<glm::vec3>().swap(this->Normal);


	std::vector<GLuint>().swap(this->VertexIndices);
	std::vector<GLuint>().swap(this->UvIndices);
	std::vector<GLuint>().swap(this->NormalIndices);


	std::string head{};

	while (!this->File.eof()) {
		this->File >> head;
		if (head[0] == '#') {
			getline(this->File, head);
			continue;
		}



		if (head[0] == 'v' && head[1] == 't') {
			glm::vec2 uv{};
			float dummy;
			this->File >> uv.x >> uv.y >> dummy;
			this->UV.push_back(uv);
		}
		else if (head[0] == 'v' && head[1] == 'n') {
			glm::vec3 Normal{};

			this->File >> Normal.x >> Normal.y >> Normal.z;
			this->Normal.push_back(Normal);

		}
		else if (head[0] == 'v' && head.size() == 1) {
			glm::vec3 Vertex_{};

			this->File >> Vertex_.x >> Vertex_.y >> Vertex_.z;
			this->Verties.push_back(Vertex_);
		}
		else if (head[0] == 'f') {

			std::string Line[3]{};

			GLuint VertexIndex[3]{};
			GLuint UVIndec[3]{};
			GLuint NormalIndex[3]{};

			this->File >> Line[0] >> Line[1] >> Line[2];



			for (auto i = 0; i < 3; ++i) {
				std::istringstream iss(Line[i]);
				std::string token{};
				GLuint Data[3]{};
				int dataindex = 0;
				if (Line[i].find("//") != std::string::npos) {
					// 있으면
					std::getline(iss, token, '/');
					this->VertexIndices.push_back(static_cast<GLuint>(stoi(token) - 1));


					std::getline(iss, token, '/');
					std::getline(iss, token, '/');


					this->NormalIndices.push_back(static_cast<GLuint>(stoi(token) - 1));
				}
				else {
					//없으면 
					std::getline(iss, token, '/');
					this->VertexIndices.push_back(static_cast<GLuint>(stoi(token) - 1));


					std::getline(iss, token, '/');
					this->UvIndices.push_back(static_cast<GLuint>(stoi(token) - 1));


					std::getline(iss, token, '/');
					this->NormalIndices.push_back(static_cast<GLuint>(stoi(token) - 1));



				}




			}
		}


	}

	this->File.close();

	this->Verties.shrink_to_fit();
	this->UV.shrink_to_fit();
	this->Normal.shrink_to_fit();
	this->VertexIndices.shrink_to_fit();
	this->NormalIndices.shrink_to_fit();
	this->UvIndices.shrink_to_fit();



	size_t Vertexnum = this->Verties.size();

	Color3F* VertexColor = new Color3F[Vertexnum];



	for (auto i = 0; i < Vertexnum; ++i) {
		VertexColor[i].r = Random::Randfloat(0.f, 1.f);
		VertexColor[i].g = Random::Randfloat(0.f, 1.f);
		VertexColor[i].b = Random::Randfloat(0.f, 1.f);
	}


	this->m_VertexCount = static_cast<GLuint>(this->VertexIndices.size());





	glGenVertexArrays(1, &(this->m_VAO));
	glBindVertexArray(this->m_VAO);


	glGenBuffers(1, &(this->m_VPBO));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_VPBO);
	glBufferData(GL_ARRAY_BUFFER, this->Verties.size() * sizeof(glm::vec3), &(this->Verties[0]), GL_STATIC_DRAW);

	glGenBuffers(1, &(this->m_EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->VertexIndices.size() * sizeof(GLuint), &(this->VertexIndices[0]), GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);






	glGenBuffers(1, &(this->m_VCBO));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_VCBO);


	glBufferData(GL_ARRAY_BUFFER, this->Verties.size() * sizeof(Color3F), VertexColor, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

}
