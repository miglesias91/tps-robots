#include "Poblacion.h"

#include <algorithm>

Poblacion::Poblacion(unsigned int tamanio) : tamanio(tamanio), existe_individuo_con_fitness_cero(false)
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
	for (unsigned int i = 0; (i < generaciones) ; i++)
	{
		this->evaluar();

		if (true == this->existe_individuo_con_fitness_cero)
		{// si hay alguno que tiene fitness == 0, entonces hay un individuo que lleguó a la solución optima. Termino la evolución.
			break;
		}

		this->seleccionar();

		this->reproducir();

		this->cruzar();

		this->mutar();
	}
}

std::vector<Individuo*> Poblacion::getIndividuos()
{
	return this->individuos;
}

void Poblacion::evaluar()
{
	for (std::vector<Individuo*>::iterator it = this->individuos.begin(); it != this->individuos.end(); it++)
	{
		if ( 0 == (*it)->evaluar())
		{
			this->existe_individuo_con_fitness_cero = true;
		}
	}
}

void Poblacion::seleccionar()
{
	// ordeno de menor a mayor segun su fitness.
	std::sort(this->individuos.begin(), this->individuos.end(), Individuo::compararFitness);

	// elimino los individuos menos los 2 primeros.
	std::vector<Individuo*>::iterator it = this->individuos.begin();

	std::advance(it, 2);

	this->individuos.erase(it, this->individuos.end());
}

void Poblacion::reproducir()
{
	unsigned int mitad_tamanio = tamanio / 2;

	// vuelvo a agrandar el tamanio de la poblacion (solamente agrando el tamanio del vector para que despues cuando llamo a 'fill_n' no me tire la exception "out_of_range").
	this->individuos.resize(tamanio);

	Individuo* mas_apto = this->individuos.at(0);
	Individuo* segundo_mas_apto = this->individuos.at(1);

	// lleno la primer mitad con el mas apto (el 1ero del vector).
	std::fill_n(this->individuos.begin(), mitad_tamanio, mas_apto);

	// lleno la segunda mitad con el segundo mas apto (el 2do del vector).
	std::fill_n(this->individuos.begin() + mitad_tamanio, mitad_tamanio, segundo_mas_apto);
}

void Poblacion::cruzar()
{
	// como el paso previo fue "reproducir", entonces se que la primer mitad del vector "individuos" tengo 5 copias del mas apto, y que en la 2da mitad del vector tengo 5 copias del 2do mas apto.
	// podria elegir cualquiera, en este caso elijo el 1er para el mas apto, y el ultimo para el segundo mas apto.

	// me hago una copia estable de los dos mas apto.
	Individuo* copia_mas_apto = new Individuo(*this->individuos.at(0));
	Individuo* copia_segundo_mas_apto = new Individuo(*this->individuos.at(tamanio-1));

	// en el siguiente for, voy a reemaplazar los padres, elimino la memoria que estan usando.
	delete this->individuos[0];
	delete this->individuos[tamanio-1];

	// seteo todos en NULL.
	for (int i = 0; i < tamanio; i++)
	{
		this->individuos[i] = NULL;
	}

	unsigned int cantidad_caracteristicas_restantes_a_cruzar = tamanio;
	unsigned int index_aleatorio = 0;
	std::vector<unsigned int> indices = this->crearIndicesAleatorios();
	for (unsigned int i = 0; i < tamanio; i++)
	{
		// hago una nueva copia para cruzarla.
		Individuo* nueva_cruza = new Individuo(*copia_mas_apto);

		// elijo un punto aleatorio para dividir la cantidad de caracteristicas que uso del mas apto y la cantidad que uso del segundo mas apto.
		index_aleatorio = std::rand() % cantidad_caracteristicas_restantes_a_cruzar;

		unsigned int index = indices.at(index_aleatorio);

		nueva_cruza->cruzarCon(copia_segundo_mas_apto, index);

		individuos[i] = nueva_cruza;

		// borro la caracteristica ya ubicada.
		std::vector<unsigned int>::iterator it_a_borrar = indices.begin();
		std::advance(it_a_borrar, index_aleatorio);
		indices.erase(it_a_borrar);
		cantidad_caracteristicas_restantes_a_cruzar--;
	}

	delete copia_mas_apto;
	delete copia_segundo_mas_apto;
}

void Poblacion::mutar()
{
	// hacer la mutation.
	for (std::vector<Individuo*>::iterator it = this->individuos.begin(); it != this->individuos.end(); it++)
	{
		(*it)->mutarAleatoriamente();
	}
}

std::vector<unsigned int> Poblacion::crearIndicesAleatorios()
{
	std::vector<unsigned int> indices;
	for (int i = 0; i < tamanio; i++)
	{
		indices.push_back(i);
	}

	std::random_shuffle(indices.begin(), indices.end());

	return indices;
}