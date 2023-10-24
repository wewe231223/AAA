#include "Animation.h"

Animation::Animation(std::vector<glm::vec3>& PointList){
	this->mptr_PointList = std::make_unique<std::vector<glm::vec3>>(PointList);
}

Animation::Animation(glm::vec3* CenterNormal , GLfloat radius) {

	



}



Animation::Animation(const Animation& other)
{
}

void Animation::update(DeltaTime dt){
	if (this->Animationflag | Animation_Revolution) {

		

		
	}




}



Animation::~Animation(){

}

