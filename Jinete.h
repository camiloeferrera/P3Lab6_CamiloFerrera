#ifndef JINETE_H
#define JINETE_H

#include "Guerrero.h"

class Jinete : public Guerrero
{
	public:
		Jinete();
		~Jinete();
		
		void Atacar(Habitante*);
	protected:
};

#endif
