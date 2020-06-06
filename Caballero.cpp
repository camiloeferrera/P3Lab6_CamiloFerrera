#include "Caballero.h"

Caballero::Caballero()
{
	this->valorAtaque = 10;
}
Caballero::~Caballero()
{
}

void Caballero::Atacar(Habitante* habitante){
	habitante->setValorVida(habitante->getValorVida() - (this->valorAtaque + 0.095*this->valorVida));
}
