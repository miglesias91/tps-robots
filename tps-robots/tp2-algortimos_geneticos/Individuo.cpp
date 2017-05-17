
#include<algorithm>
#include <iostream>

#include "Individuo.h"

unsigned int Individuo::tamanio = 0;

Individuo::Individuo() : fitness(0)
{
	if (tamanio == 0)
	{
		std::cout << "EL TAMANIO DE LOS INDIVIDUOS NUNCA FUE SETEADO. PARA SETEAR EL TAMANIO IGUAL A 10, LLAMAR DESDE EL MAIN LA SIGUIENTE LINEA: " << std::endl;
		std::cout << "Individuo::tamanio = 10;" << std::endl;
		throw - 1;
	}

	this->inicializar();
}

Individuo::~Individuo()
{
}

void Individuo::inicializar()
{
	unsigned int index_aleatorio = 0;
	unsigned int cantidad_caracteristicas_restantes_a_ubicar = tamanio;
	unsigned int caracteristica_a_ubicar = 0;

	// obtengo un vector con caracteristicas creadas al azar y desordenadas.
	std::vector<unsigned int> caracteristicas = this->caracteristicasAUbicar();

	for (int i = 0; i < tamanio; i++)
	{
		// recupero una caracteristicas al azar y la agrego a las del individuo.
		index_aleatorio = std::rand() % cantidad_caracteristicas_restantes_a_ubicar;

		this->posiciones_reinas.push_back(caracteristicas.at(index_aleatorio));

		// borro la caracteristica ya ubicada.
		std::vector<unsigned int>::iterator it_a_ubicar = caracteristicas.begin();

		this->avanzarIterador(it_a_ubicar, index_aleatorio);

		caracteristicas.erase(it_a_ubicar);

		// resto 1 a la cantidad de caracteristicas a ubicar.
		cantidad_caracteristicas_restantes_a_ubicar--;
	}
}

unsigned int Individuo::evaluar()
{
	return 0;
}

unsigned int Individuo::getFitness()
{
	return this->fitness;
}

std::vector<unsigned int> Individuo::caracteristicasAUbicar()
{
	std::vector<unsigned int> caracteristicas_a_ubicar;
	for (int i = 0; i < tamanio; i++)
	{
		caracteristicas_a_ubicar.push_back(i);
	}

	std::random_shuffle(caracteristicas_a_ubicar.begin(), caracteristicas_a_ubicar.end());

	return caracteristicas_a_ubicar;
}

std::vector<unsigned int>::iterator Individuo::avanzarIterador(std::vector<unsigned int>::iterator& iterador, unsigned int posiciones_a_avanzar)
{
	for (int i = 0; i < posiciones_a_avanzar; i++)
	{
		iterador++;
	}
	return iterador;
}