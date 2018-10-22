#ifndef _NODE_HPP_
#define _NODE_HPP_

template <typename T>
class Node {
	public: 
		T valor;
		std::vector<Node<T>*> filhos;
		Node<T> *pai;
		int posicaoVetorDoPai;

		Node() {
		}

		Node(T valor) {
			this->valor = valor;	
			pai = NULL;
		}

		void adicionarFilho(Node<T> *tmp) {
			tmp->pai = this;
			tmp->posicaoVetorDoPai = this->getQuantidadeFilhos();
			this->filhos.push_back(tmp);
		}
		
		void removerFilhos() {
			// remove todos
			this->filhos.erase(this->filhos.begin(), this->filhos.begin() + this->getQuantidadeFilhos());
		}

		void removerFilho(int posicao) {
			// remove o filho do vetor do pai
			this->filhos.erase(this->filhos.begin() + posicao);

			// atualizando posições no vetor do pai
			for(int i = 0; i < this->getQuantidadeFilhos(); i++) {
				this->filhos[i]->posicaoVetorDoPai = i;
			}
		}

		int getQuantidadeFilhos() {
			return (int) this->filhos.size();
		}
};

#endif