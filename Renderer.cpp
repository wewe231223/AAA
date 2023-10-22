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

void Renderer::update(GLfloat dt){
	this->m_Camera->update(dt);




}

void Renderer::render(ShaderID sid){
	this->m_Camera->Render(sid);
	this->m_Coord->render(sid);

	ModelList::GetInstance()->render(sid);


}


