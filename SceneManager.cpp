#include "SceneManager.h"
#include "Engine.h"


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

	std::shared_ptr<Model> parent = nullptr;
	


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


		// 파일의 안정성을 위해 파일의 끝을 EndFile 로 표시함 
		if (head._Equal("EndFile")) {
			break;
		}


		if (head._Equal("#")) {
			std::getline(file, head);
			continue;

		} 
		else if (head._Equal("Mesh")) {
			std::string MeshPath{};
			std::string MeshName{};
			file >> MeshPath >> MeshName;
			this->m_MeshManager->NewMesh(MeshPath.c_str(),MeshName.c_str());

		}
	
		else if (head._Equal("Model")) {
			std::string ModelName{};
			glm::vec3 ModelPos{};
			Rotation ModelRot{};

			GLfloat ModelScale{};


			GLboolean ModelFill{};
			GLboolean ModelCull{};

			char fb{};
			char cb{};


			file >> ModelName >> ModelPos.x >> ModelPos.y >> ModelPos.z >> ModelRot.x >> ModelRot.y >> ModelRot.z >> ModelScale >> fb >> cb;
			

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
			
			if (parent != nullptr) {
				ModelList::GetInstance()->NewModel(this->m_MeshManager->GetMesh(ModelName), ModelPos, ModelRot, ModelScale, ModelCull, ModelFill,parent);
			}
			else {
				ModelList::GetInstance()->NewModel(this->m_MeshManager->GetMesh(ModelName), ModelPos, ModelRot, ModelScale, ModelCull, ModelFill);
			}


			

			

		}
		else if (head._Equal("{")) {
			parent = ModelList::GetInstance()->GetLastModel();
		}
		else if (head._Equal("}")) {
			if (parent != nullptr) {
				parent = parent->GetParent();
			}
		}
		else if (head._Equal("Animation=")) {

			std::cout << "Animation!" << std::endl;


		}
		else if (head._Equal("Coord")) {
			char mode{};

			file >> mode;
			
			CoordRender_Flag m{};

			if (mode == 'a') {
				m = RenderAll;
			}
			else if (mode == 'l') {
				m = RenderLineOnly;
			}
			else if (mode == 's') {
				m = RenderXZOnly;
			}

			Engine::GetInstance()->SetCoordRenderMode(m);
		}



	}



}
