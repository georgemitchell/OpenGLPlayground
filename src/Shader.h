/*
 * Shader.h
 *
 *  Created on: Jun 24, 2015
 *      Author: george
 */

#ifndef SHADER_H_
#define SHADER_H_
#include <GL/glew.h>


//#include <OpenGL/gl3.h>
//#include <GLFW/glfw3.h>

class Shader
{
public:
  	// The program ID
	GLuint program_id;

	// Constructor reads and builds the shader
	Shader(const GLchar* vertexSourcePath, const GLchar* fragmentSourcePath);

	virtual ~Shader();

  	// Use the program
  	void Use();
};

#endif /* SHADER_H_ */
