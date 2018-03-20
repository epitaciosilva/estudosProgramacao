class Sapo {
	private: 
		int identificador;
		int distancia;
		int pulos;
	
	public: 
		Sapo();
		Sapo(int identificador, int distancia);
		~Sapo();

		int getIdentificador();
		int getDistancia();
		int getPulos();
		void setIdentificador(int identificador);
		void setDistancia(int distancia);
		void setPulos(int pul);
		
		static int distanciaTotal;
		int pular();
};