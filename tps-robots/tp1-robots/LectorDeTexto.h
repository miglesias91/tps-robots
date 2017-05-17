#pragma once

#include <string>
#include <fstream>

class LectorDeTexto
{
public:
	LectorDeTexto(std::string path);
	virtual ~LectorDeTexto();

	std::string leerSiguienteLinea();

	bool fin();

private:

	std::ifstream texto_entrada;
};

