#include "MeshManager.h"

MeshManager::MeshManager(){


}

MeshManager::MeshManager(const MeshManager& other){



}

MeshManager::~MeshManager(){



}

void MeshManager::NewMesh(const char* MeshPath, const char* MeshName){


	this->MeshMap.insert(
		stdext::hash_map<std::string, std::shared_ptr<Mesh>>::value_type(
			std::string(MeshName),
			std::make_shared<Mesh>(std::string(MeshPath)
			)
		)
	);






}
