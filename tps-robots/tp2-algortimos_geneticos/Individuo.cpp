#include "Individuo.h"

#include<algorithm>
#include <iostream>

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

		std::advance(it_a_ubicar, index_aleatorio);

		caracteristicas.erase(it_a_ubicar);

		// resto 1 a la cantidad de caracteristicas a ubicar.
		cantidad_caracteristicas_restantes_a_ubicar--;
	}
}

unsigned int Individuo::evaluar()
{
	// chequeo hay reinas que comparten diagonales (es decir, si se estan atacando).
	// para eso comparo todas las parejas.
	for (unsigned int i = 0; i < tamanio-1; i++)
	{
		for (unsigned int j = i+1; j < tamanio; j++)
		{
			int diferencia_columnas = j - i;
			int diferencia_filas = this->posiciones_reinas.at(j) - this->posiciones_reinas.at(i);

			// si la diferencia de filas es negativo, lo hago positivo.
			diferencia_filas *= diferencia_filas < 0 ? -1 : 1;

			if (diferencia_filas == diferencia_columnas)
			{// si el par de reinas estan atacandose, entonces incremento el fitness.
				this->fitness++;
			}
		}
	}
	return this->fitness;
}


void Individuo::mutarAleatoriamente()
{
	unsigned int mitad_de_tamanio = tamanio / 2;

	unsigned int cantidad_de_columnas_a_mutar = std::rand() % mitad_de_tamanio;

	// intercambio "n" columnas al azar, siendo "n" un numero aleatorio ("cantidad_de_columnas_a_mutar").
	for (int ciclo_mutacion = 0; ciclo_mutacion < cantidad_de_columnas_a_mutar; ciclo_mutacion++)
	{
		unsigned int index_aleatorio_1 = std::rand() % tamanio;
		unsigned int index_aleatorio_2 = std::rand() % tamanio;

		for (unsigned int i = 0; (index_aleatorio_1 == index_aleatorio_2) && i < 10; i++)
		{// me aseguro que no sean la misma columna.
			index_aleatorio_1 = std::rand() % tamanio;
			index_aleatorio_2 = std::rand() % tamanio;
		}

		// intercambio las columnas
		std::swap(this->posiciones_reinas[index_aleatorio_1], this->posiciones_reinas[index_aleatorio_2]);
	}
}

unsigned int Individuo::getFitness()
{
	return this->fitness;
}

std::vector<unsigned int> Individuo::getCaracteristicas()
{
	return this->posiciones_reinas;
}

void Individuo::setCaracteristicas(std::vector<unsigned int> caracteristicas)
{
	this->posiciones_reinas;
}

void Individuo::cruzarCon(Individuo* individuo_a_cruzar, unsigned int caracteristicas_a_cruzar)
{
	std::vector<unsigned int> posiciones_a_cruzar = individuo_a_cruzar->getCaracteristicas();

	for (int i = 0; i < caracteristicas_a_cruzar; i++)
	{
		unsigned int caracteristica_a_cruzar = posiciones_a_cruzar.at(i);
		std::vector<unsigned int>::iterator it = std::find(this->posiciones_reinas.begin(), this->posiciones_reinas.end(), caracteristica_a_cruzar);

		unsigned int index_a_swapear = std::distance(this->posiciones_reinas.begin(), it);

		std::swap(this->posiciones_reinas[index_a_swapear], this->posiciones_reinas[i]);
	}
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

bool Individuo::compararFitness(Individuo* individuo1, Individuo* individuo2)
{
	if (individuo1->getFitness() < individuo2->getFitness())
	{
		return true;
	}
	return false;
}