#pragma once
#include "pch.h"
#include "Mesh.h"

class MeshManager{
public:
	MeshManager();
	
	MeshManager(const MeshManager& other);

	
	~MeshManager();
	
private:

	
	stdext::hash_map<std::string, std::shared_ptr<Mesh> > MeshMap{};

public:


	void NewMesh(const char* MeshPath, const char* MeshName);


};

