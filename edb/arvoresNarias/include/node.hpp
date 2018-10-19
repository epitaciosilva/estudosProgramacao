#ifndef _NODE_HPP_
#define _NODE_HPP_

template <typename T>
class Node {
	public: 
		T valor;
		std::vector<Node<T>> filhos;
		
		Node() {

		}

		Node(T valor) {
			this->valor = valor;	
		}

		void addFilho(T valor) {
			this->filhos.push_back(valor);
		}
};

#endif