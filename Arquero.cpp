#include "Arquero.h"

Arquero::Arquero()
{
	this->valorAtaque = 20;
}
Arquero::~Arquero()
{
}

void Arquero::Atacar(Habitante* habitante){
	habitante->setValorVida(habitante->getValorVida() - (this->valorAtaque + 0.085*this->valorVida));
}
