#include "Poblacion.h"



Poblacion::Poblacion(unsigned int tamanio) : tamanio(tamanio)
{
}

Poblacion::~Poblacion()
{
}

void Poblacion::inicializar()
{
	for (int i = 0; i < this->tamanio; i++)
	{
		Individuo* nuevo_individuo = new Individuo(); // me devuelve el individuo ya inicializado aleatoriamente.
		this->individuos.push_back(nuevo_individuo);
	}
}

void Poblacion::evolucionar(unsigned int generaciones)
{
	for (int i = 0; i < generaciones; i++)
	{
		this->evaluar();

		this->seleccionar();

		this->reproducir();

		this->cruzar();

		this->mutar();
	}
}

void Poblacion::evaluar()
{

}

void Poblacion::seleccionar()
{

}

void Poblacion::reproducir()
{

}

void Poblacion::cruzar()
{

}

void Poblacion::mutar()
{

}