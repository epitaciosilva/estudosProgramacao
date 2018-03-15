class Sapo {
	private: 
		int identificador;
		int distancia;
		int pulos;
	
	public: 
		Sapo();
		Sapo(int identificador, int distancia, int pulos);
		int getIdentificador();
		int getDistancia();
		int getPulos();
		void setIdentificador(int idt);
		void setDistancia(int dtc);
		void setPulos(int pul);
		static int distanciaTotal;
		static int getDistanciaTotal();
}