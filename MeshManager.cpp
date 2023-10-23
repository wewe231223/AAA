#include "MeshManager.h"

MeshManager::MeshManager(){


}

MeshManager::MeshManager(const MeshManager& other){



}

MeshManager::~MeshManager(){



}

void MeshManager::NewMesh(const char* MeshPath, const char* MeshName){
	this->m_MeshMap.insert(std::make_pair(std::string(MeshName), std::make_shared<Mesh>(std::string(MeshPath))));
}

const std::shared_ptr<Mesh> MeshManager::GetMesh(std::string MeshName)
{
	auto iter = this->m_MeshMap.find(MeshName);

	if (iter == this->m_MeshMap.end()) {
		std::cerr << "MeshManager Error : " << MeshName << " does not found." << std::endl;
		exit(EXIT_FAILURE);
	}

	
	return iter->second;
}
