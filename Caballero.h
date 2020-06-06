#ifndef CABALLERO_H
#define CABALLERO_H

#include "Guerrero.h"

class Caballero : public Guerrero
{
	public:
		Caballero();
		~Caballero();
		
		void Atacar(Habitante*);
	protected:
};

#endif
