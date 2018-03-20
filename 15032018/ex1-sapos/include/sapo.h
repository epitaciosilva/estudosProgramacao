class Sapo {
	private: 
		int identificador;
		int impulsoMaximo;
		int distanciaPercorrida;
		int pulos;
	
	public: 
		Sapo();
		Sapo(int identificador, int impulsoMaximo);
		~Sapo();

		int getIdentificador();
		int getImpulsoMaximo();
		int getDistanciaPercorrida();
		int getPulos();
		void setIdentificador(int identificador);
		void setImpulsoMaximo(int impulso);
		void setPulos(int pul);
		
		static int distanciaTotal;
		static int getDistanciaTotal();
		void pular();
};