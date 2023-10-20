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


		EngineInstance->m_Shader = std::make_unique<Shader>(DEFAULT_VERTEX_SHADER_PATH, DEFAULT_FRAGMENT_SHADER_PATH);





	}


	return EngineInstance;
}

Engine* Engine::GetInstance(){
	if (EngineInstance == nullptr) {
		exit(EXIT_FAILURE);
	}
	return EngineInstance;
}

void Engine::Run(){

	glutMainLoop();

}
