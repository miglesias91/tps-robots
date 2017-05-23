#include "FabricaIndividuosTableroConReinas.h"

#include "IndividuoTableroConReinas.h"

FabricaIndividuosTableroConReinas::FabricaIndividuosTableroConReinas()
{
}

FabricaIndividuosTableroConReinas::~FabricaIndividuosTableroConReinas()
{
}

Individuo* FabricaIndividuosTableroConReinas::fabricarNuevo()
{
	return new IndividuoTableroConReinas();
}
