#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector> 
#include <algorithm> 

template <typename T> 
class HashTable {
    public:
        std::vector<std::vector<T>> table;

        HashTable() {
            this->table.resize(5);
        }

        void adicionar(T valor) {
            int index = this->hash(valor) % this->sizeTable();
            this->table[index].push_back(valor);
        }

        bool busca(T valor) {
            int index = this->hash(valor) % this->sizeTable();
            // caso o valor encontrado seja diferente da última posição, então foi encontrado.
            return std::find(this->table[index].begin(), this->table[index].end(), valor) != this->table[index].end();
        }

        void imprimir() {
            for(auto& i : this->table) {
                for(auto j : i) {
                    std::cout << j <<   " ";
                }
                std::cout << '\n';
            }
        }
		
	private:
		int hash(valor) {
			// valor >> 1 retorna a divisão do 'valor' por 2, independente do tipo
			return valor >> 1;
		}
		
		int sizeTable() {
			if(this->table.size() == 0) {
				return 1;
			} 
			
			return (int)this->table.size();
		}
};

#endif