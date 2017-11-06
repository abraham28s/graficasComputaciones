#pragma once

#include<IL/il.h>
#include <GL/glew.h>
#include <vector>
#include <GL/freeglut.h>
#include <string>

using namespace std;

class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	void LoadTexture(string path);
	void Bind();
	void Unbind();

private:
	GLuint _textureId;
};

