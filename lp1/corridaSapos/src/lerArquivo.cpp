#include "../include/lerArquivo.hpp"

LerArquivo::LerArquivo() { }

LerArquivo::~LerArquivo() { }
 
//Lendo arquivos. 
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

std::vector<Pista> LerArquivo::lerPistas(std::string localArquivo) {
    //Lendo arquivo  
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