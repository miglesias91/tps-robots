
#include <algorithm>
#include <iostream>
#include <vector>

#include "Individuo.h"
#include "Poblacion.h"

void main(char** argv, int argc)
{
	Individuo::tamanio = 12; // tamanio del tablero (12x12)

	Poblacion tableros_con_reinas(10); // tamanio de la poblacion inicial = 10

	tableros_con_reinas.inicializar();

	tableros_con_reinas.evolucionar(3);

	std::vector<Individuo*>  individuos_evolucionados = tableros_con_reinas.getIndividuos();

	// ordeno de menor a mayor segun su fitness.
	std::sort(individuos_evolucionados.begin(), individuos_evolucionados.end(), Individuo::compararFitness);

	int idx = 0;
	for (std::vector<Individuo*>::iterator it = individuos_evolucionados.begin(); it != individuos_evolucionados.end(); it++)
	{
		idx++;
		std::cout << "Indiviuo " << idx << ": " << (*it)->getFitness() << std::endl;
	}

	std::getchar();
}