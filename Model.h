#pragma once
#include "pch.h"
#include "Mesh.h"


class Model{
public:
	VertexArrayObject m_Vao{};
	VertexPositionBufferObject m_Vpbo{};
	VertexColorBufferObject m_Vcbo{};
	GLuint m_VertexCount{};

	glm::vec3 m_Position{};
	
	Rotation m_Rotation{};

	GLfloat m_Scale{};

	GLboolean m_Cull{};
	GLboolean m_Fill{};

	std::shared_ptr<Model> m_Parent = nullptr;

	glm::mat4 m_Transition{ 1.f };

public:

	Model(VertexArrayObject Vao, GLuint VertexCount, glm::vec3 pos, Rotation rot,GLfloat Scale ,GLboolean cull, GLboolean fill)
		: m_Vao(Vao), m_VertexCount(VertexCount), m_Position(pos), m_Rotation(rot),m_Scale(Scale), m_Cull(cull), m_Fill(fill) {}


	// Initialize with Parent
	Model(VertexArrayObject Vao,GLuint VertexCount,glm::vec3 relpos,Rotation rot,GLfloat Scale,GLboolean cull,GLboolean fill,const std::shared_ptr<Model> parent)
		: m_Vao(Vao), m_VertexCount(VertexCount), m_Position(relpos), m_Rotation(rot), m_Scale(Scale), m_Cull(cull), m_Fill(fill), m_Parent(parent) {}

	void render(ShaderID sid);
	void update(DeltaTime dt);



	//getter
	glm::mat4 GetMat() const { return this->m_Transition; }
	const std::shared_ptr<Model> GetParent() const { return this->m_Parent; }
};


class ModelList {
private:
	ModelList() = default;
	ModelList(const ModelList& other) = delete;


	~ModelList() = delete;
	ModelList& operator=(const ModelList& other) = delete;


private:

	static ModelList* ModelListInstance;

	std::vector<std::shared_ptr<Model>> List{};


public:

	static ModelList* GetInstance();
	void NewModel(const std::shared_ptr<Mesh> mesh, glm::vec3 pos, Rotation rot,GLfloat sc,GLboolean cull,GLboolean fill);
	void NewModel(const std::shared_ptr<Mesh> mesh, glm::vec3 pos, Rotation rot, GLfloat sc, GLboolean cull, GLboolean fill,const std::shared_ptr<Model> parent);
	
	void render(ShaderID sid);
	void update(DeltaTime dt);

	
	// getter
	const std::shared_ptr<Model> GetLastModel() { return this->List.back(); }


};