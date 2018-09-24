#ifndef _NODE_HPP_
#define _NODE_HPP_

template <typename T>
class Node {
	public:
		T valor;
		Node<T> *irmao;
		Node<T> *filho;
		Node<T> *pai;

		Node(T valor) { 
			this->valor = valor;
            this->filho = NULL;
            this->irmao = NULL;
			this->pai = NULL;
		}
		~Node(){}
};

#endif