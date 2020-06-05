#include <iostream>
#include <vector>

#include "Civilizacion.h"
#include "Habitante.h"
#include "Aldeano.h"
#include "Guerrero.h"
#include "Jinete.h"
#include "Arquero.h"
#include "Caballero.h"

using namespace std;

vector <Civilizacion*> civilizaciones;

int main() {
	int opcion;
	
	while (true){
		cout << "1. Crear Civilizacion" << endl
		<< "2. Jugar" << endl
		<< "3. Salir" << endl
		<< "Ingrese opcion: "; cin >> opcion;
		cout << endl;
		
		switch (opcion){
			case 1:{
				
				break;
			}
			case 2:{
				
				break;
			}
			case 3:{
				return 0;
			}
			default_{
				cout << "Opcion Incorrecta!" << endl;
				break;
			}
		}
		
		cout << endl;
	}
}
