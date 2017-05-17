#include "LectorDeTexto.h"

LectorDeTexto::LectorDeTexto(std::string path) : texto_entrada(path)
{
}

LectorDeTexto::~LectorDeTexto()
{
}

std::string LectorDeTexto::leerSiguienteLinea()
{
	std::string linea;
	std::getline(this->texto_entrada, linea);

	return linea;
}

bool LectorDeTexto::fin()
{
	if (this->texto_entrada.eof())
	{
		return true;
	}
	return false;
}

