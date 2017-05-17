#include "RegistroSalidaPerceptronMultiLayer.h"

#include <algorithm>
#include <sstream>
#include <vector>

RegistroSalidaPerceptronMultiLayer::RegistroSalidaPerceptronMultiLayer(std::string registro) : fallado(false)
{
	this->leerValoresOutputPrediccion( registro );
	this->leerValoresOutputDeseado( registro );
}

RegistroSalidaPerceptronMultiLayer::~RegistroSalidaPerceptronMultiLayer()
{
}

bool RegistroSalidaPerceptronMultiLayer::prediccionExitosa()
{
	unsigned int digito_deseado = this->posicionFloatMaximo(this->valores_deseados);

	unsigned int digito_predicho = this->posicionFloatMaximo(this->valores_predichos);

	if ( digito_predicho == digito_deseado )
	{
		return true;
	}

	return false;
}

void RegistroSalidaPerceptronMultiLayer::leerValoresOutputPrediccion(std::string registro_texto)
{
	std::size_t posicion_Output = registro_texto.find("Output: ");
	std::size_t posicion_Desired = registro_texto.find("Desired");

	if ( std::string::npos == posicion_Output )
	{
		// si no lo encuentro, lo salteo.
		this->fallado = true;
		return;
	}

	std::string output = registro_texto.substr( posicion_Output, posicion_Desired - posicion_Output );
	output.replace( 0, std::string("Output: ").size(), std::string(""));

	// reemplazo ',' por '.'
	std::replace( output.begin(), output.end(), ',', '.');

	// elimino los espacios
	std::string::iterator end_pos = std::remove(output.begin(), output.end(), ' ');
	output.erase(end_pos, output.end());

	// divido los valores y los pongo en un array.
    std::stringstream ss;
    ss.str(output);

    std::string item;
    this->valores_predichos;
    while (getline(ss, item, ';'))
    {
        this->valores_predichos.push_back( std::stod(item) );
    }
}

void RegistroSalidaPerceptronMultiLayer::leerValoresOutputDeseado(std::string registro_texto)
{
	std::size_t posicion_Desired = registro_texto.find("Desired output: ");
	std::size_t posicion_Error = registro_texto.find("Error");
	
	if ( std::string::npos == posicion_Desired )
	{
		// si no lo encuentro, lo salteo.
		this->fallado = true;
		return;
	}

	std::string output_deseado = registro_texto.substr( posicion_Desired, posicion_Error - posicion_Desired );
	output_deseado.replace( 0, std::string("Desired output: ").size(), std::string(""));

	// reemplazo ',' por '.'
	std::replace( output_deseado.begin(), output_deseado.end(), ',', '.');

	// elimino los espacios
	std::string::iterator end_pos = std::remove(output_deseado.begin(), output_deseado.end(), ' ');
	output_deseado.erase(end_pos, output_deseado.end());

	// divido los valores y los pongo en un array.
    std::stringstream ss;
    ss.str(output_deseado);

    std::string item;
    this->valores_deseados;
    while (getline(ss, item, ';'))
    {
        this->valores_deseados.push_back( std::stod(item) );
    }
}

unsigned int RegistroSalidaPerceptronMultiLayer::posicionFloatMaximo( std::vector<float> vector_de_floats )
{
	float valor_maximo_deseado = *(std::max_element(vector_de_floats.begin(), vector_de_floats.end()));

	std::vector<float>::iterator posicion_maximo = std::find( vector_de_floats.begin(), vector_de_floats.end(), valor_maximo_deseado);

	return std::distance( vector_de_floats.begin(), posicion_maximo);
}

bool RegistroSalidaPerceptronMultiLayer::estaFallado()
{
	return this->fallado;
}