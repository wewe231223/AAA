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

void ModelList::NewModel(const std::shared_ptr<Mesh> mesh, glm::vec3 pos, Rotation rot, GLfloat sc, GLboolean cull, GLboolean fill, const std::shared_ptr<Model> parent){
	this->List.push_back(
		std::make_shared<Model>(
			mesh->GetVao(),
			mesh->GetVertexCount(),
			pos,
			rot,
			sc,
			cull,
			fill,
			parent
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
	glUniformMatrix4fv(TransitionLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4{1.f}));



	this->m_Transition = glm::mat4{ 1.f };

	this->m_Transition = glm::translate(this->m_Transition, this->m_Position);
	this->m_Transition = glm::rotate(this->m_Transition, glm::radians(this->m_Rotation.x), glm::vec3(1.f, 0.f, 0.f));
	this->m_Transition = glm::rotate(this->m_Transition, glm::radians(this->m_Rotation.y), glm::vec3(0.f, 1.f, 0.f));
	this->m_Transition = glm::rotate(this->m_Transition, glm::radians(this->m_Rotation.z), glm::vec3(0.f, 0.f, 1.f));
	this->m_Transition = glm::scale(this->m_Transition, glm::vec3(this->m_Scale, this->m_Scale, this->m_Scale));

	if (this->m_Parent != nullptr) {
		this->m_Transition = this->m_Parent->GetMat() * this->m_Transition;
	}


	glUniformMatrix4fv(TransitionLocation, 1, GL_FALSE, glm::value_ptr(this->m_Transition));



	glBindVertexArray(this->m_Vao);
	glUseProgram(sid);
	glDrawElements(GL_TRIANGLES, this->m_VertexCount, GL_UNSIGNED_INT, 0);
	
	for (auto& i : this->m_ComponentList) {
		i->render(sid);
	}






}

void Model::update(DeltaTime dt){

	if (m_Animation != nullptr) {
		m_Animation->update(dt,this->m_Position);
	}


	if (GetAsyncKeyState(VK_SHIFT) & 0x08000) {

		if (GetAsyncKeyState(VK_RIGHT) & 0x08000) {
			this->m_Rotation.x += this->m_DeltaRotation.x * dt;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x08000) {
			this->m_Rotation.x -= this->m_DeltaRotation.x * dt;
		}

		if (GetAsyncKeyState(VK_UP) & 0x08000) {
			this->m_Rotation.z += this->m_DeltaRotation.z * dt;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x08000) {
			this->m_Rotation.z -= this->m_DeltaRotation.z * dt;
		}


		if (GetAsyncKeyState('A') & 0x08000) {

			this->m_Position.x -= this->m_DeltaPosition.x * dt;

		}

		if (GetAsyncKeyState('D') & 0x08000) {
			this->m_Position.x += this->m_DeltaPosition.x * dt;

		}


		if (GetAsyncKeyState('S') & 0x08000) {
			this->m_Position.z += this->m_DeltaPosition.z * dt;
		}


		if (GetAsyncKeyState('W') & 0x08000) {
			this->m_Position.z -= this->m_DeltaPosition.z * dt;
		}



	}
	



}

void Model::SetAnim(GLfloat radius,glm::vec3 axis){
	this->m_Animation = std::make_unique<Animation>(radius,axis);
}

void Model::SetComponent(std::shared_ptr<Component> c){
	this->m_ComponentList.push_back(c);
}

void Model::SetInput(glm::vec3 m, Rotation r){
	this->m_DeltaPosition = m;
	this->m_DeltaRotation = r;
}




Circle::Circle(){

	glGenVertexArrays(1, &(this->m_Vao));
	glBindVertexArray(this->m_Vao);

	glGenBuffers(1, &(this->m_Vpbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_Vpbo);


	std::vector<glm::vec3> Points{};
	std::vector<Color3F> Color{};

	for (auto i = 0; i < 360; ++i) {

		GLfloat theta = (float)i;

		glm::vec3 p( std::cosf( glm::radians(theta) ),0.f, std::sinf(glm::radians(theta)));

		Color.push_back(Color3F{ 1.f,0.f,0.f });
		Points.push_back(p);
	}


	glBufferData(GL_ARRAY_BUFFER, Points.size() * sizeof(glm::vec3), &(Points[0]), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)(0));
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &(this->m_Vcbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_Vcbo);
	glBufferData(GL_ARRAY_BUFFER, Color.size() * sizeof(Color3F), &(Color[0]), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)(0));
	glEnableVertexAttribArray(1);

}

// 더 필요한 정보 : 부모의 기준에서의 상대 좌표, 회전 축, 회전 각도 
Circle::Circle(std::shared_ptr<Model> Parent,glm::vec3 relpos,GLfloat rad ,glm::vec3 rot, GLfloat angle){

	this->m_Parent = Parent;
	
	glGenVertexArrays(1, &(this->m_Vao));
	glBindVertexArray(this->m_Vao);

	glGenBuffers(1, &(this->m_Vpbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_Vpbo);


	std::vector<glm::vec3> Points{};
	std::vector<Color3F> Color{};

	glm::mat4 rotation = glm::rotate(glm::mat4(1.f), glm::radians(angle), rot);

	for (auto i = 0; i < 360; ++i) {

		GLfloat theta = (float)i;

		glm::vec3 p(std::cosf(relpos.x + glm::radians(theta)) * rad, relpos.y, relpos.z + std::sinf(glm::radians(theta))* rad );
		p = rotation * glm::vec4(p,1.f);


		Color.push_back(Color3F{ 1.f,0.f,0.f });
		Points.push_back(p);
	}


	glBufferData(GL_ARRAY_BUFFER, Points.size() * sizeof(glm::vec3), &(Points[0]), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)(0));
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &(this->m_Vcbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_Vcbo);
	glBufferData(GL_ARRAY_BUFFER, Color.size() * sizeof(Color3F), &(Color[0]), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)(0));
	glEnableVertexAttribArray(1);


}

void Circle::render(ShaderID sid){

	GLuint TransformLocation = glGetUniformLocation(sid, "transform");



	glUniformMatrix4fv(TransformLocation, 1, GL_FALSE, glm::value_ptr(this->m_Parent->GetMat()));

	



	glBindVertexArray(this->m_Vao);
	glDrawArrays(GL_LINE_STRIP, 0, 360);
}

