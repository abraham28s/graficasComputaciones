#include "ShaderProgram.h"
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "InputFile.h"
#include <iostream>

using namespace std;
using namespace glm;

ShaderProgram::ShaderProgram() {
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram() {
	DeleteProgram();
}

void ShaderProgram::CreateProgram() {
	// Regresa el identificador de este manager
	// Creamos el identificador para el manager de los shaders
	_programHandle = glCreateProgram();

}

void ShaderProgram::AttachShader(string path, GLenum type) {
	// Create and add the shaders to a list
	unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(move(shader));
}

void ShaderProgram::LinkProgram() {
	/*for (int i = 0; i < _attachedShaders.size(); i++) {
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
	}
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();*/
	for (size_t i = 0; i < _attachedShaders.size(); i++)
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());

	glLinkProgram(_programHandle);

	// Get status
	GLint linkSuccess = 0;
	glGetProgramiv(_programHandle, GL_LINK_STATUS, &linkSuccess);
	if (linkSuccess == GL_FALSE)
	{
		// Get link log length
		GLint logLength = 0;
		glGetProgramiv(_programHandle, GL_INFO_LOG_LENGTH, &logLength);

		if (logLength > 0)
		{
			// Allocate memory for link log
			std::vector<GLchar> linkLog(logLength);

			// Get link log
			glGetProgramInfoLog(_programHandle, logLength, &logLength, &linkLog[0]);

			// Print link log
			for (size_t i = 0; i < linkLog.size(); i++)
				cout << linkLog[i];
			cout << std::endl;
		}
		cout << "Shaders could not be linked." << endl;

		// Delete and detach shaders; delte program handle
		DeleteProgram();

		return;
	}
	std::cout << "Build succeeded... " << std::endl;

	DeleteAndDetachShaders();
}

void ShaderProgram::Activate() {
	// Activamos el vertexShader y el fragmentShader utilizando el manager
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate() {
	// Desactivamos el manager shaderProgram
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, string name) {
	// Asociamos un buffer con �ndice 0 (posiciones) a la variable VertexPosition
	glBindAttribLocation(_programHandle, locationIndex, (const GLchar*)name.c_str());
}

void ShaderProgram::SetUniformf(string name, float value) {
	//para configurar un uniform, tenemos que 
	//decirle a openGL que vamos a utilizar 
	//shader program(manage)

	GLint  uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::SetUniformi(string name, int value)
{
	GLint  uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform1i(uniformLocation, value);
}

void ShaderProgram::SetUniformf(string name, float x, float y) {
	GLint  uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform2f(uniformLocation, x, y);
}

void ShaderProgram::SetUniformf(string name, float x, float y, float z) {
	GLint  uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform3f(uniformLocation, x, y, z);
}

void ShaderProgram::SetUniformf(string name, float x, float y, float z, float w) {
	GLint  uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform4f(uniformLocation, x, y, z, w);
}

void ShaderProgram::SetUniformMatrix(string name, mat4 matrix) {
	GLuint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, value_ptr(matrix));
}

void ShaderProgram::SetUniformMatrix3(string name, mat3 matrix)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, value_ptr(matrix));
}

//void ShaderProgram::SetUniformVector(string name, vec3 vector)
//{
//	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
//	glUniform3fv(uniformLocation, 1, glm::value_ptr(vector));
//}

void ShaderProgram::DeleteAndDetachShaders() {
	for (int i = 0; i < _attachedShaders.size(); i++) {
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());
		glDeleteShader(_attachedShaders[i]->GetHandle());
	}
	_attachedShaders.clear();
}

void ShaderProgram::DeleteProgram() {
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}

void ShaderProgram::SetUniformVector(string name, vec3 vector)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3fv(uniformLocation, 1, glm::value_ptr(vector));
}