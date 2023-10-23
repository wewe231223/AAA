#include "Model.h"






ModelList* ModelList::ModelListInstance = nullptr;

ModelList* ModelList::GetInstance(){

	if (ModelListInstance == nullptr) {
		ModelListInstance = new ModelList();



	}






	return ModelListInstance;
}

void ModelList::NewModel(const std::shared_ptr<Mesh> mesh, glm::vec3 pos, Rotation rot,GLfloat sc,GLboolean cull,GLboolean fill){
	this->List.push_back(
		std::make_shared<Model>(
			mesh->GetVao(),
			mesh->GetVertexCount(),
			pos,
			rot,
			sc,
			cull,
			fill
		)
	);
}

void ModelList::render(ShaderID sid){

	for (const auto& i : this->List) {
		i->render(sid);
	}


}

void ModelList::update(DeltaTime dt){

	for (auto& i : this->List) {
		i->update(dt);
	}


}

void Model::render(ShaderID sid){
	m_Cull ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
	m_Cull ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
	m_Fill ? glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);




	GLuint TransitionLocation = glGetUniformLocation(sid, "transform");

	glm::mat4 Transition{ 1.f };


	Transition = glm::translate(Transition, this->m_Position);
	Transition = glm::scale(Transition, glm::vec3(this->m_Scale, this->m_Scale, this->m_Scale));
	Transition = glm::rotate(Transition, glm::radians(this->m_Rotation.x), glm::vec3(1.f, 0.f, 0.f));
	Transition = glm::rotate(Transition, glm::radians(this->m_Rotation.y), glm::vec3(0.f, 1.f, 0.f));
	Transition = glm::rotate(Transition, glm::radians(this->m_Rotation.z), glm::vec3(0.f, 0.f, 1.f));

	glUniformMatrix4fv(TransitionLocation, 1, GL_FALSE, glm::value_ptr(Transition));



	glBindVertexArray(this->m_Vao);
	glUseProgram(sid);
	glDrawElements(GL_TRIANGLES, this->m_VertexCount, GL_UNSIGNED_INT, 0);







}

void Model::update(DeltaTime dt)
{
}
