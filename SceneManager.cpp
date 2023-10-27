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
		else if (head._Equal("<Animation>")) {
			std::string AnimHead{};

			file >> AnimHead;


			if (AnimHead._Equal("Revolution")) {
				GLfloat rad{};
				glm::vec3 Axis{ 0.f };
				file >> rad >> Axis.x >> Axis.y >> Axis.z;
				ModelList::GetInstance()->GetLastModel()->SetAnim(rad,Axis);
			}





		}
		else if (head._Equal("<Input>")) {

			glm::vec3 mov{ 0.f };
			Rotation rot{ 0.f };



			file >> mov.x >> mov.y >> mov.z >> rot.x >> rot.y >> rot.z;

			ModelList::GetInstance()->GetLastModel()->SetInput(mov, rot);



		}
		else if (head._Equal("<Component>")) {
			std::string FbHead{};

			file >> FbHead;

			if (FbHead._Equal("Circle")) {

				glm::vec3 relpos{ 0.f };
				glm::vec3 rot{ 0.f,1.f,0.f };
				GLfloat rad = 1.f;
				GLfloat angle = 0.f;

				file >> relpos.x >> relpos.y >> relpos.z >> rad >> rot.x >> rot.y >> rot.z >> angle;


				ModelList::GetInstance()->GetLastModel()->SetComponent(
					std::make_shared<Circle>(ModelList::GetInstance()->GetLastModel(), relpos, rad, rot, angle)
				);


			}




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
