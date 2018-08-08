# gzcut

Ambientes UNIX oferecem a ferramenta cut, um programa simples, porém bastante útil, que permite filtrar
arquivos de entrada, especificando delimitadores e selecionando apenas os campos desejados. O exemplo abaixo
ilustra o uso desta ferramenta, onde a opção -d designa o delimitador (entre aspas simples) a ser usado para
identificação dos campos e a opção -f designa quais campos deverão ser selecionados.

### Entrada

> 1,14.23,2.43,15.6,2.8,3.06,0.28,2.29  
> 1,13.2,2.14,11.2,2.65,2.76,0.26,1.28  
> 1,13.16,2.67,18.6,2.8,3.24,0.3,2.81  
> 1,14.37,2.5,16.8,3.85,3.49,0.24,2.18  
> 1,13.24,2.87,21,2.8,2.69,0.39,1.82  

### Comando 

> cut -d ’,’ -f -2,4-5,7- < entrada.in  

### Saída

> 1,14.23,15.6,2.8,0.28,2.29  
> 1,13.2,11.2,2.65,0.26,1.28  
> 1,13.16,18.6,2.8,0.3,2.81  
> 1,14.37,16.8,3.85,0.24,2.18  
> 1,13.24,21,2.8,0.39,1.82  

## Especificação da aplicação

Você deverá implementar uma biblioteca de seleção de campos separados por um delimitador, como descrito
acima. Você deverá, também, implementar uma aplicação chamada gzcut que use esta biblioteca e permita o
processamento de arquivos com e sem compactação GZip. Especificamente, sua aplicação deverá fornecer as
opções de linha de comando **--std**, **--file** arquivo e **--gz**, detalhadas a seguir:  

* **--std** especifica que a entrada e a saı́da padrões serão utilizadas.
* **--file** arquivo indica a leitura de um arquivo de entrada arquivo.in e a escrita em um arquivo de saı́da
arquivo.out.
* **--gz** especifica que a entrada e saı́da usam compactação GZip. Caso esta opção seja usada em combinação com
a opção **--file**, os arquivos de entrada e saı́da serão, respectivamente, arquivo.in.gz e arquivo.out.gz.
Para implementar a opção **--gz**, utilize a biblioteca **gzstream**. Além disso, sua biblioteca deverá permitir o
uso dos operadores de inserção e extração de streams e não apresentar redundância de código.

## Como executar

* make
* ./bin/executavel [-d ’,’ -f 2,4,5,7 entrada.in]

### Observação: 
O programa não consegui realizar a operação com o " - ", apenas com os campos específicos. 

#### Exemplo
> ./bin/executavel -d ’,’ -f 2,4,5,7 entrada.in
