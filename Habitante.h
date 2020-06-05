#ifndef HABITANTE_H
#define HABITANTE_H

class Habitante
{
	public:
		Habitante();
		~Habitante();
		
		int getValorVida();
		void setValorVida(int);
	protected:
		int valorVida = 100;
};

#endif
