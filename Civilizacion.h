#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <vector>
#include <string>

#include "Habitante.h"
#include "Aldeano.h"
#include "Guerrero.h"
#include "Jinete.h"
#include "Arquero.h"
#include "Caballero.h"

using namespace std;

class Civilizacion
{
	public:
		Civilizacion(string);
		~Civilizacion();
		
		string getNombre();
		int getMadera();
		int getOro();
		int getAlimento();
		int getNumeroHabitantes();
		int getNumeroCasas();
		int getNumeroCuarteles();
		int getNumeroEstablos();
		
		void obtenerRecursos();
		void restarMadera(int);
		void restarOro(int);
		void restarAlimento(int);
		
		void aumentarCasas(int);
		void aumentarCuarteles(int);
		void aumentarEstablos(int);
		void aumentarHabitantes(int);
		
		vector<Habitante*> getHabitantes();
		
	protected:
		string nombre;
		int cantidadMadera = 0, cantidadOro = 0, cantidadAlimento = 0, numeroHabitantes = 0, numeroCasas = 0, numeroCuarteles = 0, numeroEstablos = 0;
		vector<Habitante*> habitantes;
};

#endif
