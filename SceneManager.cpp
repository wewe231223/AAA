#include "SceneManager.h"

SceneManager::SceneManager(){

	this->m_MeshManager = std::make_unique<MeshManager>();


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

	while (!file.eof()) {
		file >> head;


		// 파일의 안정성을 위해 파일의 끝을 X로 표시함 
		if (head[0] == 'x') {
			break;
		}

		if (head[0] == '#') {
			std::getline(file, head);
			continue;

		}
		else if (head[0] == 'r') {
			std::string MeshPath{};
			std::string MeshName{};
			file >> MeshPath >> MeshName;
			this->m_MeshManager->NewMesh(MeshPath.c_str(),MeshName.c_str());

		}
	
		else if (head[0] == '$') {
			std::string ModelName{};
			glm::vec3 ModelPos{};
			Rotation ModelRot{};

			GLfloat ModelScale{};


			GLboolean ModelFill{};
			GLboolean ModelCull{};

			char fb{};
			char cb{};


			file >> ModelName >> ModelPos.x >> ModelPos.y >> ModelPos.z >> ModelRot.x >> ModelRot.y >> ModelRot.z >> ModelScale >> fb >> cb;
			

			std::cout << fb << " " << cb << std::endl;
			if (fb == 't') {
				ModelFill = true;
			}
			else {
				ModelFill = false;
			}

			if (cb == 't') {
				ModelCull = true;
			}
			else {
				ModelCull = false;
			}
			
			
			ModelList::GetInstance()->NewModel(this->m_MeshManager->GetMesh(ModelName),ModelPos,ModelRot,ModelScale,ModelCull,ModelFill);
		} 



	}



}
