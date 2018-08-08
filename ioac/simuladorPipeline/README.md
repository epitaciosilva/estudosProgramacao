# Simulador de pipeline considerando conflitos de dados, estruturais e de controle

Descrição: Implementar uma ferramenta que simule a execução em pipeline 5 estágios do MIPS. O
simulador recebe como entrada um conjunto de instruções em Assembly MIPS, simula a execução dessas
instruções considerando todas as dependências de dados e conflitos estruturais e, tem como saída, a
quantidade de ciclos necessários para executar essas instruções e a informação sobre os estágios em cada
ciclo.

### CONSIDERAÇÕES:

1) Considere um pipeline de 5 estágios na arquitetura Harvard onde os estágios:
    * IF: Busca a próxima instrução;
    * ID: Decodifica a instrução e busca operandos que são registradores;
    * EX: Executa a instrução;
    * MEM: leitura da memória;
    * WB: salva na memória ou no registrador.

2) O programa recebe um código escrito em assembly e montará, ao final, a sua execução no pipeline
ciclo por ciclo. Não é obrigatório que o programa faça a análise dos conflitos em tempo de
execução, ele pode processar todo o código e em seguida montar/imprimir o pipeline, conforme
exemplo na frente.

3) As instruções utilizadas serão ADD, SUB, BEQ, BNE, LW, SW e JUMP. Não se preocupe com as
demais instruções.

4) As instruções BEQ, BNE e JUMP não utilizam labels. No lugar deles é utilizado o número da
instrução para onde se deve saltar.

5) Não se preocupe com a execução completa das instruções, i.e., os registradores das instruções são
apenas referências para que você saiba onde tem conflito e que possa resolver tal conflito. EX: Em
“add $t0, $t1, $t2” não é preciso carregar os valores dos registradores $t1 e $t2 nem salvar em $t0.
Apenas utilize-os para montar a execução ciclo a ciclo do pipeline.

6) Não deve ser realizada reordenação

7) Considere que a arquitetura não tem redirecionamento (forwarding)

8) Quanto aos conflitos, considere:

    * Conflitos de dados:
      * A ferramenta deve ser capaz de detectar as dependências de dados e parar o pipeline até que a dependência
        seja resolvida.
    * Conflitos estruturais:
      * Para considerar os conflitos estruturas, a ferramenta deve assumir sempre uma arquitetura harvard. Ou
        seja, não haverão casos de conflitos por memória. Considere apenas a disputa pelo estágio do pipeline.
    * Conflitos de controle:
      * Assuma que os saltos serão SEMPRE tomados. Nesse caso, ao encontrar um salto, é preciso verificar qual
        o Label e preencher o pipeline com a instruções a partir do label.
## Saída da Ferramenta:
  * A saída da ferramenta deve mostrar:
    * A quantidade de ciclos total para executar as instruções
    * O estágio que cada instrução se encontra por ciclo.

## Como executar
  * make
  * Insira as instruções no arquivo instrucoes.txt.
  * bin/programa