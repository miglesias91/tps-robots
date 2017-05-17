
#include <iostream>

#include "LectorDeTexto.h"
#include "RegistroSalidaPerceptronMultiLayer.h"

void main(char** argv, int argc)
{
	std::cout << "HOLIVANDERS" << std::endl;

	LectorDeTexto lector(std::string("C:/Users/Usuario/Dropbox/facultad/7570 - robots/tps/resultado mlp 24abril.txt"));

	unsigned int exitos = 0;
	unsigned int total = 0;
	while (false == lector.fin())
	{
		std::string linea = lector.leerSiguienteLinea();

		RegistroSalidaPerceptronMultiLayer registro(linea);

		if ( registro.estaFallado() )
		{
			continue;
		}

		if ( registro.prediccionExitosa() )
		{
			exitos++;
		}

		total++;
	}

	std::cout << "exitos: " << exitos << std::endl;
	std::cout << "total: " << total << std::endl;
	std::cout << "% exito: " << exitos *100 / total << std::endl;

	std::getchar();
}