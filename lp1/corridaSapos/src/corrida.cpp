/**
* @author Epitácio Bessa
* @file corrida.cpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/src/corrida.cpp
* @since 29/05/18
* @date 07/06/18
* @brief Implementações dos métodos da classe corrida
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include "../include/corrida.hpp"
#include "../include/lerArquivo.hpp"

Corrida::Corrida() { }

Corrida::~Corrida() { }

/**
 * @brief Pega os sapos que estavam no arquivo e salvam no vetor
 * @param localArquivo é o local do arquivo que deverá ser lido
 */
void Corrida::inserirSapos(std::string localArquivo) {
    LerArquivo arquivoSapos;    
    this->sapos = arquivoSapos.lerSapos(localArquivo);
} 


/**
 * @brief Pega as pistas que estavam no arquivo e salvam no vetor
 * @param localArquivo é o local do arquivo que deverá ser lido
 */
void Corrida::inserirPistas(std::string localArquivo) {
    LerArquivo arquivoSapos;    
    this->pistas = arquivoSapos.lerPistas(localArquivo);
} 

/**
 * @brief Mostra todos os sapos presentes na corrida.
 */
void Corrida::imprimirSapos() {
    
    //Imprimir todos os sapos 
    std::cout << "\n------- SAPOS QUE PARTICIPARAO DA CORRIDA -------" << std::endl;
    for(size_t i = 0; i < this->sapos.size(); i++) {
        std::cout << "\n------ Sapo " << i+1 << " ------"<< std::endl;
        std::cout << "Descricao: " << this->sapos[i].getDescricao() << std::endl;
        std::cout << "Identificador: " << this->sapos[i].getIdentificador() << std::endl;
    }
}

/**
 * @brief Mostra as informações mais detalhadas de todos os sapos, como vitórias,
 * e total percorrido.
 */
void Corrida::imprimirEstatisticasSapos() { 
    for(size_t i = 0; i < this->sapos.size(); i++) {
        std::cout << "\n------ " << (i + 1) << "° Sapo ------" << std::endl;
        std::cout << this->sapos[i];
    }
}

/**
 * @brief Mostra todas as pistas disponíveis
 */
void Corrida::imprimirEstatisticasPistas() { 
    for(size_t i = 0; i < this->pistas.size(); i++) {
        std::cout << "\n------ " << (i + 1) << "°  Pista ------" << std::endl;
        std::cout << this->pistas[i];
    }
}
/**
 * @brief Mostra todos os sapos presentes na corrida.
 * @param nomePista é o nome da pista que deve acontecer a corrida
 * @return Retorna o index da pista do vetor de pistas.
 */
size_t Corrida::buscarCorrida(std::string nomePista) {
    for(size_t i = 0; i < this->pistas.size(); i++) {
        if(this->pistas[i].getDescricao() == nomePista) {
            return i;
        }
    }
    
    return (size_t)-1;
}

/**
 * @brief Inicia a corrida, fazendo com que os sapos pulem até o fim da corrida.
 * @param nomePista é o nome da pista que deve acontecer a corrida
 */
void Corrida::iniciarCorrida(std::string nomePista) {
    size_t indexPista = this->buscarCorrida(nomePista);
    
    if(indexPista == (size_t)-1) {
        std::cout << "\nPista nao encontrada!\n";
        return;
    }

    std::cout << "\n\n---------- CORRIDA INICIALIZADA -----------" << std::endl;
    for(size_t i = 0; i < this->sapos.size(); i++) {
        bool podePular = true;

        //Verificando se o sapo atual já terminou a corrida.
        for(size_t j = 0; j < this->classificacao.size(); j++) {
            if(this->sapos[i].getIdentificador() == this->classificacao[j]->getIdentificador()) {
                podePular = false;
            }
        }

        //Caso o sapo ainda não teha terminado, ele pode continuar pulando.
        if(podePular) {
            this->sapos[i].pular();
            
            if(this->sapos[i].getDistanciaPercorrida() >= this->pistas[indexPista].getDistancia()) {
                this->classificacao.push_back(&this->sapos[i]);
            }
        }

        //Quando todos concluem a corrida.
        if(this->sapos.size() == this->classificacao.size()) {
            break;
        } else if(i+1 >= this->sapos.size()) {
            //Continuando a corrida após o último do vetor pular sem que todos tenham terminado a corrida.
            //-1 porque ao final do laço é incrementado o i++.
            i = -1;
        }
    }

    this->imprimirRank(indexPista);
}

/**
 * @brief Salva o rank de cada corrida no arquivo 'rank.txt'
 * @param indexPista é o index do vetor na qual contém a pista em que foi realizada a corrida.
 */
void Corrida::imprimirRank(size_t indexPista) {
    //Imprime o rank da corrida 
    std::ofstream arquivo("./rank.txt", std::ostream::app);

    arquivo << "\n-------------- RANK na Pista " << this->pistas[indexPista].getDescricao() << " -------------\n";
    for(size_t i = 0; i < this->classificacao.size(); i++) {
        arquivo << "\n------ " << i+1 << "° lugar------"<< std::endl;
        arquivo << "Sapo: " << this->classificacao[i]->getDescricao() << std::endl;
        arquivo << "Identificador: " << this->classificacao[i]->getIdentificador() << std::endl;
        arquivo << "Quantidade de pulos: " << this->classificacao[i]->getQuantidadePulos() << std::endl;
        arquivo << "Distancia total percorrida: " << this->classificacao[i]->getDistanciaPercorrida() << std::endl;

        //Não tem critério de desempate, então,
        //caso dê empate a quantidade de pulos com o que está na posição 0 (1° colocado) 
        //também é considerado um vencedor.
        if(i == 0) {
            //Primeiro colocado.
            this->classificacao[i]->posCorrida(true, false);
        } else if(i > 0 && this->classificacao[i]->getQuantidadePulos() == this->classificacao[0]->getQuantidadePulos()) {
            //Caso o sapo esteja com a mesma quantidade de pulos do que está na posição 0
            //então este sapo também é um ganhador.  
            this->classificacao[i]->posCorrida(true, true);
        }else if(i+1 < this->classificacao.size() && this->classificacao[i]->getQuantidadePulos() == this->classificacao[i+1]->getQuantidadePulos()) { 
            //Caso o sapo que está na posição seguinte tenha a mesma quantidade de pulos então ouve um empate .
            this->classificacao[i]->posCorrida(false, true);
        } else if(this->classificacao[i]->getQuantidadePulos() == this->classificacao[i-1]->getQuantidadePulos()) {
            //Caso o sapo que está na posição anterior tenha a mesma quantidade de pulos então ouve um empate .
            this->classificacao[i]->posCorrida(false, true);
        } else {
            this->classificacao[i]->posCorrida(false, false);
        }
    }

    //Fechando arquivo
    arquivo.close();

    std::cout << "\nRank salvo no arquivo 'rank.txt'" << std::endl;

    //Limpando a classificação.
    this->classificacao.clear();
}

/**
 * @brief Salva os sapos que foram criados
 * @param localArquivo local do arquivo que as informações derão ser salvas.
 */
void Corrida::escreverSapo(Sapo sapo, std::string localArquivo) {
    this->sapos.push_back(sapo);
    LerArquivo arquivo;
    arquivo.escreverSapo(localArquivo, sapo);
}

/**
 * @brief Salva as pistas que foram criados
 * @param localArquivo local do arquivo que as informações derão ser salvas.
 */
void Corrida::escreverPista(Pista pista, std::string localArquivo) {
    LerArquivo arquivo;
    arquivo.escreverPista(localArquivo, pista);
    this->pistas.push_back(pista);
}