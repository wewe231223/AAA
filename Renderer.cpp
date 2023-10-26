#include "Renderer.h"
#include "Model.h"


Renderer::Renderer(ShaderID sid){

	this->m_Camera = std::make_unique<Camera>(sid);
	this->m_Coord = std::make_unique<Coord>();

}

Renderer::Renderer(const Renderer& other)
{
}

Renderer::~Renderer()
{
}

void Renderer::update(DeltaTime dt,DeltaTime Anidt){
	this->m_Camera->update(dt);
	ModelList::GetInstance()->update(Anidt);
}

void Renderer::render(ShaderID sid){
	this->m_Camera->Render(sid);
	this->m_Coord->render(sid);

	ModelList::GetInstance()->render(sid);


}


