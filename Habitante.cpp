#include "Habitante.h"

Habitante::Habitante()
{
}
Habitante::~Habitante()
{
}

int Habitante::getValorVida(){
	return this->valorVida;
}
int Habitante::getHoras(){
	return this->contadorHoras;
}
void Habitante::setValorVida(int valorVida){
	this->valorVida = valorVida;
}

void Habitante::aumentarHoras(){
	this->contadorHoras++;
}
