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

		void addFilho(Node<T> *tmp) {
			tmp->pai = this;
			tmp->posicaoVetorDoPai = this->quantidadeFilhos();
			this->filhos.push_back(tmp);
		}
		
		void removerFilhos(int posicao = -1) {
			if(posicao == -1) {
				this->filhos.erase(this->filhos.begin(), this->filhos.begin() + this->quantidadeFilhos());
				return;
			}

			this->filhos.erase(this->filhos.begin() + posicao);
			for(int i = 0; i < this->quantidadeFilhos(); i++) {
				this->filhos[i]->posicaoVetorDoPai = i;
			}
		}

		int quantidadeFilhos() {
			return (int) this->filhos.size();
		}
};

#endif