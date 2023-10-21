#include "Engine.h"
Engine* Engine::EngineInstance = nullptr;



void __default__draw() {
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}


void __default__reshape(int w,int h) {
	glViewport(0, 0, w, h);
}



void __default__Idle() {
	if (Engine::GetInstance() != nullptr) {
		Engine::GetInstance()->Update();
		glutPostRedisplay();
	}
}

Engine* Engine::GetInstance(int* argcp,char** argv)
{

	if (EngineInstance == nullptr) {
		EngineInstance = new Engine();
		
		glutInit(argcp,argv);

		glutInitWindowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
		glutInitWindowPosition(DEFAULT_WINDOW_POSITION_X, DEFAULT_WINDOW_POSITION_Y);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

		glutCreateWindow(DEFAULT_WINDOW_TITLE);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			std::cerr << "GLEW INIT FALIED" << std::endl;
		}
		else {
			std::cout << "GLEW INIT!" << std::endl;
		}


		glutDisplayFunc(__default__draw);
		glutReshapeFunc(__default__reshape);
		glutIdleFunc(__default__Idle);

		EngineInstance->m_Shader = std::make_unique<Shader>(DEFAULT_VERTEX_SHADER_PATH, DEFAULT_FRAGMENT_SHADER_PATH);
		EngineInstance->m_Timer = std::make_unique<Timer>();
		EngineInstance->m_MeshManager = std::make_unique<MeshManager>();
		
		EngineInstance->m_Timer->Init();


		EngineInstance->VsyncUpdate(false);









	}


	return EngineInstance;
}

Engine* Engine::GetInstance(){
	if (EngineInstance == nullptr) {
		exit(EXIT_FAILURE);
	}
	return EngineInstance;
}


const std::string base("Fps : ");

void Engine::Update() {
	
	this->m_Timer->Update();

	std::string Fpsstr = base + std::to_string(this->m_Timer->GetFps());

	glutSetWindowTitle(Fpsstr.c_str());
}

void Engine::VsyncUpdate(bool onoff){

	if (onoff) {
		((BOOL(WINAPI*)(int))wglGetProcAddress("wglSwapIntervalEXT"))(1);
	}
	else {
		((BOOL(WINAPI*)(int))wglGetProcAddress("wglSwapIntervalEXT"))(0);
	}

}



void Engine::Run(){

	glutMainLoop();

}

