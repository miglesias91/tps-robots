#pragma once

#include <vector>

#include "Fitness.h"

class Individuo
{
public:
	Individuo();
	virtual ~Individuo();

	// metodos a redefinir por un individuo especifico.
	virtual void inicializar() = 0;

	// evalua las caracteristicas del individuo y calcula su fitness.
	virtual unsigned int evaluar() = 0;

	// muta las caracteristicas del invidiuo aleatoriamente.
	virtual void mutarAleatoriamente() = 0;

	// combina caracteristicas de los dos individuos. "caracteristicas_a_cruzar" determina la cantidad de caracteristicas que se combinaran.
	virtual void cruzarCon(Individuo* individuo_a_cruzar, unsigned int caracteristicas_a_cruzar) = 0;

	// devuelve un clon del individuo.
	virtual Individuo* clonar() = 0;

	virtual std::vector<unsigned int> getCaracteristicas() = 0;

	// metodos comunes a todos los individuos.
	virtual unsigned int getFitness();

	// funcion compararcion de fitness
	static bool compararFitness(Individuo* individuo1, Individuo* individuo2);

	// tamanio de las caracteristica del individuo.
	static unsigned int tamanio;

protected:

	// aptitud del individuo. Mientras mas bajo fitness, mejor.
	unsigned int fitness;
};

