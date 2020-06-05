#ifndef HABITANTE_H
#define HABITANTE_H

class Habitante
{
	public:
		Habitante();
		virtual ~Habitante();
		
		int getValorVida();
		void setValorVida(int);
		
		int getHoras();
		
		void aumentarHoras();
		
	protected:
		int valorVida = 100;
		int contadorHoras = 0;
};

#endif
