#include "Animation.h"

Animation::Animation(std::vector<glm::vec3>& PointList){
	this->mptr_PointList = std::make_unique<std::vector<glm::vec3>>(PointList);
}

Animation::Animation(GLfloat radius, glm::vec3 Axis) {
	//this->mptr_Center = CenterNormal;
	this->rad = radius;
	this->m_Axis = Axis;
	

	this->Animationflag = this->Animationflag | Animation_Revolution;
}



Animation::Animation(const Animation& other)
{
}

void Animation::update(DeltaTime dt,glm::vec3& pos){
	if (this->Animationflag & Animation_Revolution) {

		pos = glm::rotate(glm::mat4{ 1.f }, glm::radians(dt * 100.f), this->m_Axis) * glm::vec4(pos,1.f);

		

		
	}




}



Animation::~Animation(){

}

