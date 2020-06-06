#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Civilizacion.h"
#include "Habitante.h"
#include "Aldeano.h"
#include "Guerrero.h"
#include "Jinete.h"
#include "Arquero.h"
#include "Caballero.h"

using namespace std;

vector <Civilizacion*> civilizaciones;
vector <Habitante*> pendientes; // Vector que nos ayudara a manejar las horas de los habitantes pendientes de crear.
int u; // Variable que nos ayudara a manejar la civilizacion que se selecciono del vector para jugar.

bool civilizacionCreada(string);
void escogerCivilizacion();
void menuJugar();
void Resumen();
void Guerra();

int main() {
	cout << "BIENVENIDO a AGE OF EMPIRES!" << endl << endl;
	
	int opcion;
	
	while (true){
		cout << "1. Crear Civilizacion" << endl
		<< "2. Jugar" << endl
		<< "3. Salir" << endl
		<< "Ingrese opcion: "; cin >> opcion;
		cout << endl;
		
		switch (opcion){
			case 1:{
				string nombre;
				cout << "Ingrese nombre de la civilizacion: "; cin >> nombre;
				cout << endl;
				
				if (civilizacionCreada(nombre)){
					cout << "Esta civilizacion ya esta creada..." << endl;
				} else {
					civilizaciones.push_back(new Civilizacion(nombre));
					cout << "Civilizacion creada con exito!" << endl;
				}
				
				break;
			}
			case 2:{
				if (civilizaciones.size() == 0){
					cout << "No hay civilizaciones creadas para jugar..." << endl;
				} else {
					escogerCivilizacion();
					menuJugar();
					
				}
				break;
			}
			case 3:{
				return 0;
			}
			default: {
				cout << "Opcion Incorrecta!" << endl;
				break;
			}
		}
		
		cout << endl;
	}
	
	
	//Limpiar Memoria
	for (int i = 0; i < civilizaciones.size(); i++){
		delete civilizaciones[i];
	}
}


bool civilizacionCreada(string nombre){
	for (int i = 0; i < civilizaciones.size(); i++){
		if (nombre == civilizaciones[i]->getNombre()){
			return true;
		}
	}
	
	return false;
}

void escogerCivilizacion(){
	int opcion;
	
	for (int i = 0; i < civilizaciones.size(); i++){
		cout << (i+1) << ". " << civilizaciones[i]->getNombre() << endl;
	}
	cout << "Escoga civilizacion: "; cin >> opcion; opcion--;
	
	while (opcion < 0 || opcion >= civilizaciones.size()){
		cout << endl << "Civilizacion no encontrada, intente de nuevo" << endl
		<< "Escoga civilizacion: "; cin >> opcion; opcion--;
	}
	
	cout << endl;
	
	u = opcion; // Guardamos la posicion de la civilizacion con la que se jugara.
}

void menuJugar(){
	int opcion;
	while (true){
		int capacidadMaxima = civilizaciones[u]->getNumeroCasas() * 5;
		
		cout << "1. Crear Aldeano" << endl
		<< "2. Crear Jinete" << endl
		<< "3. Crear Arquero" << endl
		<< "4. Crear Caballero" << endl
		<< "5. Construir Casa" << endl
		<< "6. Construir Cuartel" << endl
		<< "7. Construir Establo" << endl
		<< "8. Ir a guerra" << endl
		<< "9. Siguiente Hora" << endl
		<< "0. Salir" << endl
		<< "Ingrese opcion: "; cin >> opcion;
		cout << endl;
		
		switch (opcion){
			case 1:{
				if (civilizaciones[u]->getNumeroHabitantes() <= capacidadMaxima){
					
					if (civilizaciones[u]->getAlimento() >= 25){
						pendientes.push_back(new Aldeano());
						cout << "Se esta creando un aldeano..." << endl;
						civilizaciones[u]->restarAlimento(25);
					} else {
						cout << "No hay suficientes recursos para crear un Aldeano..." << endl;
					}
						
				} else {
					cout << "Ya ha alcanzado la maxima capacidad de habitantes..." << endl;
				}
				
				break;
			}
			case 2:{
				
				if (civilizaciones[u]->getNumeroEstablos() >= 1){
					if (civilizaciones[u]->getNumeroHabitantes() <= capacidadMaxima){
						
						if(civilizaciones[u]->getAlimento() >= 75 && civilizaciones[u]->getOro() >= 20 && civilizaciones[u]->getMadera() >= 5){
							pendientes.push_back(new Jinete());
							cout << "Se esta creando un jinete..." << endl;
							civilizaciones[u]->restarAlimento(75);
							civilizaciones[u]->restarOro(20);
							civilizaciones[u]->restarMadera(5);
							
						} else {
							cout << "No hay suficientes recursos para crear un Jinete..." << endl;
						}
						
							
					} else {
						cout << "Ya ha alcanzado la maxima capacidad de habitantes..." << endl;
					}
					
				} else {
					cout << "Necesita almenos 1 Establo para crear Jinetes..." << endl;
				}
				
					
				break;
			}
			case 3:{
				
				if (civilizaciones[u]->getNumeroCuarteles() >= 1){
					if (civilizaciones[u]->getNumeroHabitantes() <= capacidadMaxima){
						
						if(civilizaciones[u]->getAlimento() >= 50 && civilizaciones[u]->getOro() >= 10 && civilizaciones[u]->getMadera() >= 10){
							pendientes.push_back(new Arquero());
							cout << "Se esta creando un Arquero..." << endl;
							civilizaciones[u]->restarAlimento(50);
							civilizaciones[u]->restarOro(10);
							civilizaciones[u]->restarMadera(10);
							
						} else {
							cout << "No hay suficientes recursos para crear un Arquero..." << endl;
						}
						
							
					} else {
						cout << "Ya ha alcanzado la maxima capacidad de habitantes..." << endl;
					}
				} else {
					cout << "Necesita almenos 1 Cuartel para crear Arqueros..." << endl;
				}
									
				break;
			}
			case 4:{
				
				if (civilizaciones[u]->getNumeroCuarteles() >= 1){
					if (civilizaciones[u]->getNumeroHabitantes() <= capacidadMaxima){
						
						if(civilizaciones[u]->getAlimento() >= 50 && civilizaciones[u]->getOro() >= 15 && civilizaciones[u]->getMadera() >= 5){
							pendientes.push_back(new Caballero());
							cout << "Se esta creando un Caballero..." << endl;
							civilizaciones[u]->restarAlimento(50);
							civilizaciones[u]->restarOro(15);
							civilizaciones[u]->restarMadera(5);
							
						} else {
							cout << "No hay suficientes recursos para crear un Caballero..." << endl;
						}
						
							
					} else {
						cout << "Ya ha alcanzado la maxima capacidad de habitantes..." << endl;
					}
				} else {
					cout << "Necesita almenos 1 Cuartel para crear Caballeros..." << endl;
				}
					
				break;
			}
			case 5:{
				if (civilizaciones[u]->getMadera() >= 50){
					civilizaciones[u]->aumentarCasas(1);
					civilizaciones[u]->restarMadera(50);
					cout << "Se ha creado una Casa!" << endl;
				} else {
					cout << "No tiene suficientes recursos para crear una Casa..." << endl;
				}
				break;
			}
			case 6:{
				if (civilizaciones[u]->getMadera() >= 200 && civilizaciones[u]->getOro() >= 50){
					civilizaciones[u]->aumentarCuarteles(1);
					civilizaciones[u]->restarMadera(200);
					civilizaciones[u]->restarOro(50);
					cout << "Se ha creado un Cuartel!" << endl;
				} else {
					cout << "No tiene suficientes recursos para crear un Cuartel..." << endl;
				}
				break;
			}
			case 7:{
				if (civilizaciones[u]->getMadera() >= 150 && civilizaciones[u]->getOro() >= 50){
					civilizaciones[u]->aumentarEstablos(1);
					civilizaciones[u]->restarMadera(150);
					civilizaciones[u]->restarOro(50);
					cout << "Se ha creado un Establo!" << endl;
				} else {
					cout << "No tiene suficientes recursos para crear un Establo..." << endl;
				}
				break;
			}
			case 8:{
				Guerra();
				break;
			}
			case 9:{
				for (int i = 0; i < pendientes.size(); i++){
					Aldeano* ptrAldeano = dynamic_cast<Aldeano*>(pendientes[i]);
					if (ptrAldeano == 0){
						
						Jinete* ptrJinete = dynamic_cast<Jinete*>(pendientes[i]);
						
						if (ptrJinete == 0){
							
							Arquero* ptrArquero = dynamic_cast<Arquero*>(pendientes[i]);
							
							if (ptrArquero == 0){
								
								Caballero* ptrCaballero = dynamic_cast<Caballero*>(pendientes[i]);
								
								if (ptrCaballero != 0){
									
									pendientes[i]->aumentarHoras();
									if (pendientes[i]->getHoras() == 4){
										civilizaciones[u]->agregarCaballero();
										cout << "Se ha añadido un Caballero!" << endl;
										civilizaciones[u]->aumentarHabitantes(1);
										//delete pendientes[i];
										pendientes.erase(pendientes.begin() + i);
									}
									
									
								}
								
							} else {
								pendientes[i]->aumentarHoras();
								if (pendientes[i]->getHoras() == 4){
									civilizaciones[u]->agregarArquero();
									cout << "Se ha agregado un Arquero!" << endl;
									civilizaciones[u]->aumentarHabitantes(1);
									//delete pendientes[i];
									//pendientes.erase(pendientes.begin() + i);
								}
								
								
							}
							
						} else {
							pendientes[i]->aumentarHoras();
							if (pendientes[i]->getHoras() == 6){
								civilizaciones[u]->agregarJinete();
								cout << "Se ha agregado un Jinete!" << endl;
								civilizaciones[u]->aumentarHabitantes(1);

								//delete pendientes[i];
								//pendientes.erase(pendientes.begin() + i);
							}
							
							
						}
						
					} else {
						pendientes[i]->aumentarHoras();
						if (pendientes[i]->getHoras() == 1){
							civilizaciones[u]->agregarAldeano();
							cout << "Se ha agregado un aldeano!" << endl;
							civilizaciones[u]->aumentarHabitantes(1);
							//delete pendientes[i];
							//pendientes.erase(pendientes.begin() + i);
						}
					}
					
					
					
				
				}
				
				
				for (int i = 0; i < civilizaciones[u]->getHabitantes().size(); i++){
					Aldeano* ptr = dynamic_cast<Aldeano*>(civilizaciones[u]->getHabitantes()[i]);
					if (ptr != 0){
						civilizaciones[u]->obtenerRecursos();
					}
					
					 	
				}
				
				
				Resumen();
				
				break;
			}
			case 0:{
				for (int i = 0; i < pendientes.size(); i++){
					delete pendientes[i];
				}
				break;
			}
		}
		
		if (opcion == 0){
			break;
		} else {
			cout << endl;
		}
	}
}

void Resumen(){
	cout << endl << "Numero de Habitantes: " << civilizaciones[u]->getNumeroHabitantes() << endl
	<< "Capacidad Maxima de Habitantes: " << civilizaciones[u]->getNumeroCasas() * 5 << endl
	<< "Cantidad de Madera: " << civilizaciones[u]->getMadera() << endl
	<< "Cantidad de Oro: " << civilizaciones[u]->getOro() << endl
	<< "Cantidad de Alimento: " << civilizaciones[u]->getAlimento() << endl;
}

void Guerra(){
	if (civilizaciones.size() == 1){
		cout << "Solo esta tu civilizacion creada, no hay con quien pelear..." << endl;
	} else {
		int opcion;
		for (int i = 0; i < civilizaciones.size(); i++){
			cout << (i+1) << ". " << civilizaciones[i]->getNombre() << endl;
		}
		cout << "Ingrese opcion: "; cin >> opcion; opcion--;
		cout << endl;
		
		if (opcion == u){
			cout << "No te podes atacar a vos mismo..." << endl;
		} else {
			srand((int) time(0));
			
			for (int i = 0; i < civilizaciones[u]->getHabitantes().size(); i++){
				int random = rand() % civilizaciones[opcion]->getHabitantes().size();
				
				Aldeano* aldeano = dynamic_cast<Aldeano*>(civilizaciones[u]->getHabitantes()[i]);
				
				if (aldeano != 0){
					Guerrero* guerrero = dynamic_cast<Guerrero*>(civilizaciones[u]->getHabitantes()[i]);
					guerrero->Atacar(civilizaciones[opcion]->getHabitantes()[random]);
					
				}
				
					
			}
			
			
		}
		
	}
}

