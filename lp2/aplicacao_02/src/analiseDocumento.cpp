#include "../include/analiseDocumento.hpp"

AnaliseDocumento::AnaliseDocumento() { }

AnaliseDocumento::~AnaliseDocumento() { }
    
void AnaliseDocumento::realizarAnalise(std::string nomeArquivo, std::vector<std::string> colunas, char delim) {
    std::vector<std::string> linhas;
    Arquivo::ler(linhas, nomeArquivo);
    std::vector<std::string> resultado;

    for(size_t i = 0; i < linhas.size(); i++) {
        std::vector<std::string> valores;
        Arquivo::split(valores, linhas[i], delim);

        for(size_t t = 0; t < valores.size(); t++) {
            for(size_t j = 0; j < colunas.size(); j++) {
                const char* col = colunas[j].c_str();
                if((int) t+1 == atoi(col)) {
                    resultado.push_back(valores[t]);            
                }
            }
        }
        resultado.push_back("\n");
    }

    Arquivo::exportarArquivo(resultado, nomeArquivo, delim);
}