#pragma once

#include "IFabricaIndividuos.h"

class FabricaIndividuosTableroConReinas : public IFabricaIndividuos
{
public:
	FabricaIndividuosTableroConReinas();
	virtual ~FabricaIndividuosTableroConReinas();

	virtual Individuo* fabricarNuevo();
};

