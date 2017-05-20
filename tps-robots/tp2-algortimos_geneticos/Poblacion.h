#pragma once

#include <vector>

#include "Individuo.h"

class Poblacion
{
public:
	Poblacion(unsigned int tamanio);
	virtual ~Poblacion();

	void inicializar();

	void evolucionar(unsigned int generaciones);

private:

	// evalua los individuos. calcula el fitness de cada uno.
	void evaluar();

	// selecciona los 2 individuos mas aptos. los mantiene en la poblacion (lista de individuos) y elimina a los menos aptos.
	void seleccionar();

	// reproduce los 2 invividuos mas aptos.
	void reproducir();

	// cruza las caracteristicas de los padres entre los individuos de la poblacion.
	void cruzar();

	// muta los individuos de la poblaciones. cambia alguna caracteristica segun el metodo elegido.
	void mutar();

	// crea un vector con indices de 1 al "tamanio", ordenados al azar.
	std::vector<unsigned int> Poblacion::crearIndicesAleatorios();

	unsigned int tamanio;

	std::vector<Individuo*> individuos;
};

