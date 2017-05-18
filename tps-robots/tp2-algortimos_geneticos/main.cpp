
#include <iostream>
#include <vector>

#include "Individuo.h"
#include "Poblacion.h"

void main(char** argv, int argc)
{
	Individuo::tamanio = 12; // tamanio del tablero (12x12)

	Poblacion tableros_con_reinas(10); // tamanio de la poblacion inicial = 10

	tableros_con_reinas.inicializar();

	tableros_con_reinas.evolucionar(100);

	std::getchar();
}