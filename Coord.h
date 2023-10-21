#pragma once
#include "pch.h"

constexpr auto CoordScale = 1000.f;

enum CoordRender_Flag {
	RenderAll,
	RenderLineOnly,
	RenderXZOnly
};


class Coord{
private:

	const GLfloat Vertex[3 * 3 * 2] = {
	-CoordScale,0.f,-CoordScale, // 1
	CoordScale,0.f,CoordScale,   // 2
	-CoordScale,0.f,CoordScale,  // 3

	-CoordScale,0.f,-CoordScale, // 1
	CoordScale,0.f,-CoordScale,  // 4
	CoordScale,0.f,CoordScale    // 2
	};



	const GLfloat Line[18] = {
	0.f,CoordScale,0.f,
	0.f,-CoordScale,0.f,


	CoordScale,0.1f,0.f,
	-CoordScale,0.1f,0.f,

	0.f,0.1f,CoordScale,
	0.f,0.1f,-CoordScale
	};


	VertexArrayObject XZ_Vao{};
	VertexPositionBufferObject XZ_Vpbo{};
	VertexColorBufferObject XZ_Vcbo{};


	VertexArrayObject Line_Vao{};
	VertexPositionBufferObject Line_Vpbo{};
	VertexColorBufferObject Line_Vcbo{};



	CoordRender_Flag renderflag = RenderAll;




public:

	Coord();
	Coord(const Coord& other);
	~Coord();

	void render(ShaderID shaderid);


};

