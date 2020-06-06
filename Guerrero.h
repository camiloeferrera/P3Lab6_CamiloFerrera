#ifndef GUERRERO_H
#define GUERRERO_H

#include "Habitante.h"

class Guerrero : public Habitante
{
	public:
		Guerrero();
		~Guerrero();
		
	    virtual void Atacar(Habitante*) = 0;
		int getValorAtaque();
	protected:
		int valorAtaque;
		
};

#endif
