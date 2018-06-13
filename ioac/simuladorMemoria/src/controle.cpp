#include "../include/controle.hpp"

Controle::Controle() { }

Controle::~Controle() { }

void Controle::inicializarMemorias(std::string arquivoConfiguracoes) {
    std::vector<std::string> configuracoes = Arquivo::lerArquivo(arquivoConfiguracoes);
    
    std::string::size_type sz;  
    this->tamanhoBloco = std::stoi(configuracoes[0], &sz);
    this->linhasCache = std::stoi(configuracoes[1], &sz);
    this->blocosPrincipal = std::stoi(configuracoes[2], &sz);
    this->tipoMapeamento = std::stoi(configuracoes[3], &sz);
    this->numeroConjuntos = std::stoi(configuracoes[4], &sz);
    this->politicaSubstituicao = std::stoi(configuracoes[5], &sz);

    this->cache.inicializarMemoria(linhasCache, tamanhoBloco);
    this->principal.inicializarMemoria(blocosPrincipal, tamanhoBloco);
}
