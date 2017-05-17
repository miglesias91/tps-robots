
#include <iostream>
#include <vector>

#include "Individuo.h"
#include "Poblacion.h"

void main(char** argv, int argc)
{
	Individuo::tamanio = 12;

	Poblacion tableros_con_reinas(12);

	tableros_con_reinas.inicializar();

	tableros_con_reinas.evolucionar(100);

	std::getchar();
}