#include "InputFile.h"
#include <fstream>
#include <iostream>

bool InputFile::Read(std::string filename) {

	std::ifstream archivo;
	archivo.open(filename,
		std::ios::in);
	if (!archivo)
	{
		_contents = "";
		return false;
	}
	_contents = "";
	std::string linea;
	while (std::getline(archivo, linea))
		_contents += linea + "\n";
	archivo.close();
	return true;
}

std::string InputFile::GetContents() {
	return _contents;
}