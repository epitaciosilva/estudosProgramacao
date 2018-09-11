#include <iostream>
#include <stack>
#include <string>

bool verificarPar(char open, char close) {
	if(open == '(' && close == ')') {
		return true;
	} else if(open == '[' && close == ']') {
		return true;
	} else if(open == '{' && close == '}') {
		return true;
	}

	return false;
}

bool verificar(std::string texto) {
	std::stack<char> opens;
	int i = 0;
	while(i < (int)texto.length()) {
		if(texto[i] == '(' || texto[i] == '[' || texto[i] == '{') {
			opens.push(texto[i]);
		} else if(texto[i] == ')' || texto[i] == ']' || texto[i] == '}') {
			if(opens.empty() || !verificarPar(opens.top(), texto[i])) {
				return false;	
			} else {	
				opens.pop();
			}
		}
		i++;
	}

	return opens.empty();
}

int main() {
	std::string texto;
	std::cin >> texto;
	
	if(verificar(texto)) {
		std::cout << "Estão balanceados\n";
	} else {
		std::cout << "Não estão balanceados\n";
	}

	return 0;
}