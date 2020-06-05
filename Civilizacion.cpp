#include "Civilizacion.h"

Civilizacion::Civilizacion(string nombre)
{
	this->nombre = nombre;
	this->numeroCasas += 2;
	
	this->cantidadMadera = 50;
	this->cantidadOro = 50;
	this->cantidadAlimento = 50;
	
	habitantes.push_back(new Aldeano());
	habitantes.push_back(new Aldeano());
	habitantes.push_back(new Aldeano());
	habitantes.push_back(new Aldeano());
	habitantes.push_back(new Aldeano());
	habitantes.push_back(new Jinete());
	
	this->numeroHabitantes += 6;
}

Civilizacion::~Civilizacion()
{
	for (int i = 0; i < habitantes.size(); i++){
		delete habitantes[i];
	}
}


string Civilizacion::getNombre(){
	return this->nombre;
}

int Civilizacion::getMadera(){
	return this->cantidadMadera;
}
int Civilizacion::getOro(){
	return this->cantidadOro;
}
int Civilizacion::getAlimento(){
	return this->cantidadAlimento;
}

int Civilizacion::getNumeroHabitantes(){
	return this->numeroHabitantes;
}

int Civilizacion::getNumeroCasas(){
	return this->numeroCasas;
}
int Civilizacion::getNumeroCuarteles(){
	return this->numeroCuarteles;
}
int Civilizacion::getNumeroEstablos(){
	return this->numeroEstablos;
}

vector<Habitante*> Civilizacion::getHabitantes(){
	return this->habitantes;
}

void Civilizacion::obtenerRecursos(){
	this->cantidadAlimento += 5;
	this->cantidadMadera += 4;
	this->cantidadOro += 3;
}


void Civilizacion::restarMadera(int cantidad){
	this->cantidadMadera -= cantidad;
}
void Civilizacion::restarOro(int cantidad){
	this->cantidadOro -= cantidad;
}
void Civilizacion::restarAlimento(int cantidad){
	this->cantidadAlimento -= cantidad;
}

void Civilizacion::aumentarCasas(int cantidad){
	this->numeroCasas += cantidad;
}
void Civilizacion::aumentarCuarteles(int cantidad){
	this->numeroCuarteles += cantidad;
}
void Civilizacion::aumentarEstablos(int cantidad){
	this->numeroEstablos += cantidad;
}
void Civilizacion::aumentarHabitantes(int cantidad){
	this->numeroHabitantes += cantidad;
}

