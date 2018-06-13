#include <iostream>
#include <string>

#include "../include/controle.hpp"

int main(){
	Controle controle;
	controle.inicializarMemorias("./docs/config.txt");

	std::string opcao = " ";
	int endereco, conteudo;

	while(opcao != "exit"){
		std::cout << " --------- Gerenciador da Cache ---------- " << std::endl;
		std::cout << "1 - Ler cache, digite 'read' e depois o endereco " << std::endl;
		std::cout << "2 - Escrever cache, digite 'write' e depois o endereco + conteudo " << std::endl;
		std::cout << "3 - Mostrar memórias, digite 'show' " << std::endl;
		std::cout << "4 - Sair, digite 'exit' " << std::endl;
		std::cin >> opcao;

		if(opcao == "read"){
			std::cin >> endereco;
			controle.read(endereco);
		} else if(opcao == "write") {
			std::cin >> endereco >> conteudo;
			controle.write(endereco, conteudo);
		} else if(opcao == "show") {
			controle.show();
		} 
	}

	return 0;
}