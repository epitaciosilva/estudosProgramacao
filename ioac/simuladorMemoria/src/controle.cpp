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

void Controle::read(int endereco, int conteudo) {
    for(int i = 0; i < this->linhasCache*this->tamanhoBloco; i++) {
        if(this->cache.getCache()[i][2] == endereco) {
            if(conteudo != 0) {
                int principal = this->buscarPrincipal(endereco);
                this->cache.atualizarCache(this->cache.getCache()[i][0]*this->tamanhoBloco, this->tamanhoBloco, this->principal.getPrincipal(), principal*this->tamanhoBloco, endereco, conteudo);
                std::cout << "Hit -> alocado na linha " << this->cache.getCache()[i][0] << " -> bloco " << principal << " substituido" << std::endl;
            } else {
               std::cout << "HIT -> linha " << this->cache.getCache()[i][0] << std::endl;
               this->cache.setFifu(i);
            }
            return;
        }
    }
    
    if(this->tipoMapeamento == 1) {
        this->mapeamentoDireto(endereco, conteudo);
    } else if(this->tipoMapeamento == 2) {
        this->totalmenteAssossiativo(endereco, conteudo);
    }
}

int Controle::buscarPrincipal(int endereco) {
    for(int i = 0; i < this->blocosPrincipal*this->tamanhoBloco; i++) {
        if(this->principal.getPrincipal()[i][1] == endereco) {
            return this->principal.getPrincipal()[i][0];  
        }
    }

    return 0;
}

void Controle::write(int endereco, int conteudo) {
    this->read(endereco, conteudo);
}

void Controle::mapeamentoDireto(int endereco, int conteudo) {
    int principal = this->buscarPrincipal(endereco);

    //linhaSub*this->tamanhoBloco é o index que começa a linha no vetor.
    int linhaSub = (endereco/this->linhasCache) % this->tamanhoBloco;

    this->cache.atualizarCache(
        linhaSub*this->tamanhoBloco, 
        this->tamanhoBloco, 
        this->principal.getPrincipal(), 
        principal * this->tamanhoBloco,
        endereco, conteudo);

    std::cout << "Miss -> alocado na linha " << linhaSub << " -> bloco " << principal << " substituido" << std::endl;
}

void Controle::totalmenteAssossiativo(int endereco, int conteudo) {
    int principal = this->buscarPrincipal(endereco);
    
    int linhaSub;
   
    if(this->politicaSubstituicao == 3) {
        linhaSub = this->cache.lfu(this->linhasCache*this->tamanhoBloco, this->tamanhoBloco);
    } else if(this->politicaSubstituicao == 4) {
        linhaSub = this->cache.lru(this->linhasCache*this->tamanhoBloco, this->tamanhoBloco);
    } else if(this->politicaSubstituicao == 2) {
        linhaSub = this->cache.fifo(this->linhasCache*this->tamanhoBloco, this->tamanhoBloco);
    } else {
        linhaSub = this->cache.aleatorio(this->linhasCache, this->tamanhoBloco);
    }

    this->cache.atualizarCache(linhaSub*this->tamanhoBloco, this->tamanhoBloco, this->principal.getPrincipal(), principal*this->tamanhoBloco, endereco, conteudo);
    std::cout << "Miss -> alocado na linha " << linhaSub << " -> bloco " << principal << " substituido" << std::endl;
}

void Controle::show() {
    this->cache.show(this->linhasCache*this->tamanhoBloco);
    this->principal.show(this->blocosPrincipal*this->tamanhoBloco);
}
// void Controle::parcialmenteAssossiativo(int enderecoSolicitado, int conteudo) {

// }