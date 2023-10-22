#include "Coord.h"
#include "Random.h"

Coord::Coord(){


	Color3F Color1 = { Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f) };
	Color3F Color2 = { Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f) };
	Color3F Color3 = { Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f) };
	Color3F Color4 = { Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f),Random::Randfloat(0.f,0.5f) };


	const GLfloat Color[3 * 3 * 2] = {
		Color1.r,Color1.g,Color1.b,
		Color2.r,Color2.g,Color2.b,
		Color3.r,Color3.g,Color3.b,

		Color1.r,Color1.g,Color1.b,
		Color4.r,Color4.g,Color4.b,
		Color2.r,Color2.g,Color2.b

	};


	glGenVertexArrays(1, &(this->XZ_Vao));
	glBindVertexArray(this->XZ_Vao);

	glGenBuffers(1, &(this->XZ_Vpbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->XZ_Vpbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * 6 * sizeof(GLfloat), Vertex, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &(this->XZ_Vcbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->XZ_Vcbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * 6 * sizeof(GLfloat), Color, GL_STATIC_DRAW);



	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	const GLfloat LineColor[18] = {
	0.f,1.f,0.f,
	0.f,1.f,0.f,

	1.f,0.f,0.f,
	1.f,0.f,0.f,

	0.f,0.f,1.f,
	0.f,0.f,1.f

	};

	glGenVertexArrays(1, &(this->Line_Vao));
	glBindVertexArray(this->Line_Vao);

	glGenBuffers(1, &(this->Line_Vpbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->Line_Vpbo);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), this->Line, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);


	glGenBuffers(1, &(this->Line_Vcbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->Line_Vcbo);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), LineColor, GL_STATIC_DRAW);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}

Coord::Coord(const Coord& other)
{
}

Coord::~Coord()
{
}

void Coord::render(ShaderID shaderid){


	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	GLuint TransitionLocation = glGetUniformLocation(shaderid, "transform");
	glUniformMatrix4fv(TransitionLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.f)));

	switch (this->renderflag)
	{
	case RenderAll:

		glBindVertexArray(this->XZ_Vao);
		glDrawArrays(GL_TRIANGLES, 0, 18);

		glBindVertexArray(this->Line_Vao);
		glDrawArrays(GL_LINES, 0, 18);


		break;
	case RenderLineOnly:
		break;
	case RenderXZOnly:
		break;
	default:
		break;
	}
	
}
