#ifndef HABITANTE_H
#define HABITANTE_H

class Habitante
{
	public:
		Habitante();
		virtual ~Habitante();
		
		int getValorVida();
		void setValorVida(double);
		
		int getHoras();
		
		void aumentarHoras();
		
	protected:
		double valorVida = 100;
		int contadorHoras = 0;
};

#endif
