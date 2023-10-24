#pragma once

constexpr auto DEFAULT_WINDOW_WIDTHF = 800.F;
constexpr auto DEFAULT_WINDOW_HEIGHTF = 800.F;

constexpr auto DEFAULT_WINDOW_WIDTH = 800;
constexpr auto DEFAULT_WINDOW_HEIGHT = 800;

constexpr auto DEFAULT_WINDOW_POSITION_X = 200;
constexpr auto DEFAULT_WINDOW_POSITION_Y = 200;

constexpr auto DEFAULT_WINDOW_TITLE = "Computer Graphics";

constexpr auto DEFAULT_VERTEX_SHADER_PATH = "3D_Vertex_Shader.glsl";
constexpr auto DEFAULT_FRAGMENT_SHADER_PATH = "3D_Fragment_Shader.glsl";




typedef unsigned int VertexShaderID;
typedef unsigned int FragmentShaderID;
typedef unsigned int ShaderID;
typedef unsigned int VertexArrayObject;
typedef unsigned int VertexPositionBufferObject;
typedef unsigned int VertexColorBufferObject;
typedef unsigned int VertexElementObject;


typedef int BINARY;


typedef float DeltaTime;



namespace Axis {
	constexpr glm::vec3 X = glm::vec3(1.f, 0.f, 0.f);
	constexpr glm::vec3 Y = glm::vec3(0.f, 1.f, 0.f);
	constexpr glm::vec3 Z = glm::vec3(0.f, 0.f, 1.f);

}


typedef struct _TAG_COLOR3F{
	float r;
	float g;
	float b;

}Color3F;


typedef struct _TAG_ROTATION {
	float x;
	float y;
	float z;

}Rotation;


namespace glm {
	inline bool IsValue(glm::vec3 vec) {
		if (vec.x != 0 || vec.y != 0 || vec.z != 0) {
			return true;
		}
		return false;
	}
}