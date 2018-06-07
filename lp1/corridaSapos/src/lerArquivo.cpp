/**
* @author Epitácio Bessa
* @file lerArquivo.cpp
* @sa https://github.com/epitaciosilva/cppClass/blob/corridaSapos/lp1/corridaSapos/src/lerArquivo.cpp
* @since 29/05/18
* @date 07/06/18
* @brief Implementações dos métodos da classe lerArquivo
*/

#include "../include/lerArquivo.hpp"

LerArquivo::LerArquivo() { }

LerArquivo::~LerArquivo() { }

/**
 * @brief Função que ler todas as linhas de um arquivo.
 * @param localArquivo é o local do arquivo que deverá ser lido
 */
void LerArquivo::lerArquivo(std::string localArquivo) {
    std::string line;
    std::ifstream arquivo(localArquivo);
    
    if(arquivo.is_open()) {
        //Essa função retorna todas as linhas individualmente do arquivo.
        while(getline(arquivo, line)) {
            this->linhas.push_back(line);
        }
    } else {
        //Caso aconteça algum erro na leitura do arquivo.
        std::cout << "Erro na leitura do arquivo" << std::endl;
        exit(1);
    }
    
    arquivo.close();
}


/**
 * @brief Função que extrai as informações das pistas
 * @param localArquivo é o local do arquivo que deverá ser lido
 */
std::vector<Pista> LerArquivo::lerPistas(std::string localArquivo) {
    this->lerArquivo(localArquivo);
    std::vector<Pista> pistas;
    size_t i = 0;

    //Extraindo informações de cada linha. 
    while(i < this->linhas.size()) {
        std::vector<std::string> atributos;
        std::string pedaco = "";
        
        for(auto caracter:this->linhas[i]) {
            if(caracter != '-' && caracter != '\n') {
                pedaco += caracter;
            }else if(pedaco != "") {
                atributos.push_back(pedaco);
                pedaco = "";
            }
        }

        if(pedaco != "") {
            atributos.push_back(pedaco);
        }

        //Transformar std::string para inteiro.
        std::string::size_type sz;  
        int distancia = std::stoi(atributos[1], &sz);
        
        //Alocando os atributos descritos no arquivo para um novo objeto Pista.
        Pista pista(atributos[0], distancia);
        pistas.push_back(pista);
        i++;
    }

    //Remove todos as linhas
    this->linhas.erase(this->linhas.begin()+this->linhas.size());

    return pistas;
}


/**
 * @brief Função que extrai as informações dos sapos
 * @param localArquivo é o local do arquivo que deverá ser lido
 */
std::vector<Sapo> LerArquivo::lerSapos(std::string localArquivo) {

    //Lendo arquivo  
    this->lerArquivo(localArquivo);

    std::vector<Sapo> sapos;
    size_t i = 0;

    while(i < this->linhas.size()) {
        std::vector<std::string> atributos;
        std::string pedaco = "";
        
        for(auto caracter:this->linhas[i]) {
            if(caracter != '-' && caracter != '\n') {
                pedaco += caracter;
            }else if(pedaco != "") {
                atributos.push_back(pedaco);
                pedaco = "";
            }
        }

        if(pedaco != "") {
            atributos.push_back(pedaco);
        }
        
        //Alocando os atributos descritos no arquivo para um novo objeto Sapo.
        Sapo sapo(atributos[0], atributos[1]);
        sapos.push_back(sapo);
        i++;
    }

    //Remove todos as linhas
    this->linhas.erase(this->linhas.begin()+this->linhas.size());

    return sapos;
}


/**
 * @brief Função que salva as informações dos sapos criados pelo usuário
 * @param localArquivo é o local do arquivo que deverá ser salvo
 * @param sapo são as informações que serão salvas no arquivo
 */
void LerArquivo::escreverSapo(std::string localArquivo, Sapo sapo) {
    //Abre o arquivo no mode de edição, para que as informações sejam inseridas no fim do arquivo.
    std::ofstream arquivo(localArquivo, std::fstream::app);
    
    std::string descricao = sapo.getDescricao() + "-" + sapo.getIdentificador();
    arquivo << descricao;   
    arquivo.close();
}


/**
 * @brief Função que salva as informações das pistas criadas pelo usuário
 * @param localArquivo é o local do arquivo que deverá ser salvo
 * @param pista são as informações que serão salvas no arquivo
 */
void LerArquivo::escreverPista(std::string localArquivo, Pista pista) {
    //Abre o arquivo no mode de edição, para que as informações sejam inseridas no fim do arquivo.
    std::ofstream arquivo(localArquivo, std::fstream::app);
    
    arquivo << "\n" << pista.getDescricao() << "-" << pista.getDistancia();
    arquivo.close();
}