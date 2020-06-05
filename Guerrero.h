#ifndef GUERRERO_H
#define GUERRERO_H

#include "Habitante.h"

class Guerrero : public Habitante
{
	public:
		Guerrero();
		~Guerrero();
		
		void Atacar();
		int getValorAtaque();
	protected:
		int valorAtaque;
		
};

#endif
