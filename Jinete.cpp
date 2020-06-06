#include "Jinete.h"

Jinete::Jinete()
{
	this->valorAtaque = 30;
}
Jinete::~Jinete()
{
}

void Jinete::Atacar(Habitante* habitante){
	habitante->setValorVida(habitante->getValorVida() - (this->valorAtaque + 0.065*this->valorVida));
}
