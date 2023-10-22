#pragma once
#include "pch.h"
#include "Mesh.h"

class MeshManager{
public:
	MeshManager();
	
	MeshManager(const MeshManager& other);

	
	~MeshManager();
	
private:

	
	std::map<std::string, std::shared_ptr<Mesh>> m_MeshMap;


public:


	void NewMesh(const char* MeshPath, const char* MeshName);
	const std::shared_ptr<Mesh> GetMesh(std::string MeshName);


};

