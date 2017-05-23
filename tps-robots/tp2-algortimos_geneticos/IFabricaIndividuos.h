#pragma once

#include "Individuo.h"

class IFabricaIndividuos
{
public:

	IFabricaIndividuos()
	{
	}

	virtual ~IFabricaIndividuos()
	{
	}

	// fabrica un individuo ya inicializado correctamente y listo para usar en una Poblacion.
	virtual Individuo* fabricarNuevo() = 0;
};

