#pragma once

#include <vector>

#include "Fitness.h"

class Individuo
{
public:
	Individuo();
	virtual ~Individuo();

	void inicializar();

	unsigned int evaluar();

	unsigned int getFitness();

	static unsigned int tamanio;

private:

	// devuelve un vector con la forma: {0, 1, 2, 3, .... , tamanio-1, tamanio}, ordenaro aleatoriamente.
	std::vector<unsigned int> caracteristicasAUbicar();

	std::vector<unsigned int>::iterator avanzarIterador(std::vector<unsigned int>::iterator& iterador, unsigned int posiciones_a_avanzar);

	unsigned int fitness;

	// la posicion (columna, fila) de cada reina esta definida segun:
	// columa = numero de index en 'posiciones_reinas'.
	// fila = valor para ese numero de index.
	// ej: posiciones_reinas = {2, 3, 1, 4}
	//		. posicion_reina_1 = (columna = 1, fila = 2)
	//		. posicion_reina_2 = (columna = 2, fila = 3)
	//		. posicion_reina_3 = (columna = 3, fila = 1)
	//		. posicion_reina_4 = (columna = 4, fila = 4)
	std::vector<unsigned int> posiciones_reinas;
};

