#include "Shader.h"

Shader::Shader(const char* VertexShaderPath, const char* FragmentShaderPath){

	std::ifstream VertexFileptr = std::ifstream(VertexShaderPath, std::ios::in);
	std::ifstream FragmentFileptr = std::ifstream(FragmentShaderPath, std::ios::in);

	std::stringstream Vertexstream = std::stringstream{};
	std::stringstream Fragmentstream = std::stringstream{};


	std::string s1{ " " };
	std::string s2{ " " };
	if (VertexFileptr.is_open()) {
		Vertexstream << VertexFileptr.rdbuf();
		s1 = Vertexstream.str();
	}
	else {
		std::cerr << "ERROR : FAILED TO OPEN FILE " << std::endl;
		exit(EXIT_FAILURE);
	}


	if (FragmentFileptr.is_open()) {
		Fragmentstream << FragmentFileptr.rdbuf();
		s2 = Fragmentstream.str();
	}
	else {
		std::cerr << "ERROR : FAILED TO OPEN FILE " << std::endl;
		exit(EXIT_FAILURE);
	}


	const GLchar* VertexShaderSource = s1.c_str();
	const GLchar* FragmentShaderSource = s2.c_str();



	this->m_VertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->m_VertexID, 1, &VertexShaderSource, NULL);
	glCompileShader(this->m_VertexID);

	GLint result{};
	GLchar errorlog[512]{};

	glGetShaderiv(this->m_VertexID, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(this->m_VertexID, 512, NULL, errorlog);
		std::cerr << "ERROR : VERTEX SHADER COMPILE ERROR" << std::endl;
		std::cerr << errorlog << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cerr << "VERTEX SHADER SUCESSFULLY COMPILED!" << std::endl;
	}




	this->m_FragID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->m_FragID, 1, &FragmentShaderSource, NULL);
	glCompileShader(this->m_FragID);

	ZeroMemory(errorlog, 512);

	glGetShaderiv(this->m_FragID, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(this->m_FragID, 512, NULL, errorlog);
		std::cerr << "ERROR : FRAGMENT SHADER COMPILE ERROR" << std::endl;
		std::cerr << errorlog << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cerr << "FRAGMENT SHADER SUCESSFULLY COMPILED!" << std::endl;
	}

	this->m_ShaderID = glCreateProgram();
	glAttachShader(this->m_ShaderID, this->m_VertexID);
	glAttachShader(this->m_ShaderID, this->m_FragID);

	glLinkProgram(this->m_ShaderID);

	glDeleteShader(this->m_VertexID);
	glDeleteShader(this->m_FragID);


	ZeroMemory(errorlog, 512);
	glGetProgramiv(this->m_ShaderID, GL_LINK_STATUS, &result);

	if (!result) {
		glGetProgramInfoLog(this->m_ShaderID, 512, NULL, errorlog);
		std::cerr << "ERROR : SHADER LINK FAILED" << std::endl;
		std::cerr << errorlog << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cerr << "SHADERS SUCESSFULLY CREATED" << std::endl;
	}

	glUseProgram(this->m_ShaderID);



}
