#include "Animation.h"

Animation::Animation(std::vector<glm::vec3>& PointList){
	this->m_PointList = PointList;
}

Animation::Animation(Animation_Prefabs pf,glm::vec3 pos){
	switch (pf)
	{
	case Circle:
		
		


		
		
		
		
		
		
		break;

	default:
		break;
	}
}


Animation::Animation(const Animation& other)
{
}



Animation::~Animation()
{
}

