#pragma once

#include <vector>

class RegistroSalidaPerceptronMultiLayer
{
public:
	RegistroSalidaPerceptronMultiLayer(std::string registro);
	virtual ~RegistroSalidaPerceptronMultiLayer();

	bool prediccionExitosa();

	bool estaFallado();

private:

	unsigned int posicionFloatMaximo( std::vector<float> vector_de_floats );

	void leerValoresOutputPrediccion(std::string registro_texto);
	void leerValoresOutputDeseado(std::string registro_texto);

	std::string registro_texto;
	std::vector<float> valores_predichos;
	std::vector<float> valores_deseados;

	bool fallado;
};

