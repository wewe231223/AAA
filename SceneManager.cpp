#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::SceneManager(const SceneManager& other)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Read(const char* path){
	std::ifstream file(path);

	


	if (file.is_open()) {
		std::cout << "Sucessfully Open Scene : " << path << std::endl;
	}
	else {
		std::cerr << "SceneManager Error : Can't open File\nFileName : " << path << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string head{};

	while (file.eof()) {
		file >> head;

		if (head[0] == '#') {
			std::getline(file, head);
			continue;
		}

		if (head[0] == '$') {






		}



	}



}
