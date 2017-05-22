#include "Individuo.h"

#include <algorithm>
#include <iostream>

unsigned int Individuo::tamanio = 0;

Individuo::Individuo() : fitness(0)
{
	if (tamanio == 0)
	{
		std::cout << "EL TAMANIO DE LOS INDIVIDUOS NUNCA FUE SETEADO. PARA SETEAR EL TAMANIO IGUAL A UN NUMERO 'X', LLAMAR DESDE EL MAIN LA SIGUIENTE LINEA: " << std::endl;
		std::cout << "Individuo::tamanio = X;" << std::endl;
		throw -1;
	}
}

Individuo::~Individuo()
{
}

unsigned int Individuo::getFitness()
{
	return this->fitness;
}

bool Individuo::compararFitness(Individuo* individuo1, Individuo* individuo2)
{
	if (individuo1->getFitness() < individuo2->getFitness())
	{
		return true;
	}
	return false;
}