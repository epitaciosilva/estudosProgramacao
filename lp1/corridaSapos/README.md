## Corrida de Sapos

### Como executar
  * make
  * Insira as informações dos sapos e pistas nos arquivos pistas.txt e sapos.txt nos seguintes formatos: 
    * Sapos: nome-identificador  
    * Pistas: nome-tamanho
  * ./bin/executavel

### Gerar documentação
Para gerar a documentação do projeto basta executar o comando abaixo e acessar o arquivo **docs/index.html**  
  * doxygen Doxyfile
 

### Descrição da tarefa
Implemente em C++ um programa que simule a uma corrida de sapos. Implemente
uma classe chamada Sapo contendo: 
  * Atributos: nome, identificador, distância percorrida, quantidade de pulos dados,
  quantidade de provas disputadas, vitórias, empates, quantidade total de pulos dados.
  * Atributo estático público: distância total da corrida
  * Métodos públicos:
    * Construtor(es).
    * getters e setters, quando necessários.
    * pular:
        * incrementa distância percorrida de forma randômica entre 1 e o máximo
          que o sapo pode saltar
        * Incrementa o número de pulos dados em uma unidade
### Especificação do Projeto
O código desenvolvido deve seguir as especificações abaixo:
  1. O programa deverá ler um arquivo que conterá as informações dos sapos
    disponíveis para a corrida.  
  2. O programa deverá ler um arquivo que conterá as informações sobre as pistas
    disponíveis para a corrida.  
  3. Ao iniciar o programa, o usuário poderá:
    a) Ver estatísticas dos sapos.  
    b) Ver estatísticas das pistas.  
    c) Iniciar uma corrida.  
    d) Criar sapos.  
    e) Criar uma pista.  
  4. Para iniciar uma corrida:  
    a) O usuário deverá escolher uma pista de corrida que os sapos irão disputar.  
    b) É mostrado ao usuário a lista dos sapos que iram participar da corrida com
    seus nomes e números.  
    c) O usuário dará o start (pei) da corrida.  
  5. Durante a corrida:  
    a) Cada sapo irá pular individualmente, mostrando ao usuário seu nome,
    numeração e quanto ele pulou, em cada pulo.  
    b) A medida que um sapo chegar na linha de chegada, ele não deverá mais
    pular nem emitir mais mensagens na tela.  
    c) Quando o ultimo sapo terminar a corrida, o programa mostrará o Rank da
       corrida.  
  6. Lembre que as operações de criação de sapos e corridas devem salvar os
    mesmo nos arquivos, bem como as estatísticas dos sapos após as corridas
    realizadas. 

### Organização do projeto
O código do projeto deve seguir a configuração de pastas e arquivos:  
  * /bin – código executável  
  * /src – código fonte  
  * /docs – documentação  
  * makefile  
  * README – arquivo contendo informações sobre: configuração, compilação e
    execução.  
