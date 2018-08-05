# Análise de documentos

A análise de documentos constitui uma importante área da ciência de dados. A Google, por exemplo, se difer-
enciou de suas concorrentes pela capacidade de seus algoritmos de indexar páginas e avaliá-las em termos de
relevância para uma busca. Um dos procedimentos mais elementares neste contexto de análise é identificar as
palavras que ocorrem em documentos. Em particular, é comum haver três tipos de processamento: (i) remoção
de termos irrelevantes (stop words); (ii) contagem de ocorrências; (iii) ordenação por frequência.  

Considere, por exemplo, o arquivo texto abaixo, onde a primeira linha constitui um conjunto de stop words
a serem ignorados pela análise:

> um uma uns umas o a os as  
sabe uma frase simples  
outra frase nem tao simples assim  

O processamento deste documento, considerando todos os critérios acima, geraria o relatório abaixo:
> (assim, 1)  
> (frase, 2)  
> (nem, 1)  
> (outra, 1)  
> (simples, 2) (sabe, 1)  
> (tao, 1)  

Note que as palavras estão agrupadas pela inicial 1 e são impressas como pares (palavra, ocorrências).

## Especificação da aplicação
Você deverá escrever uma biblioteca para efetuar a análise acima, e uma aplicação que utilize esta biblioteca e
faça a leitura, análise e escrita dos resultados. Especificamente, sua aplicação deverá fornecer as opções de linha
de comando --std, --file arquivo e --gz, detalhadas a seguir:  

* **--std**  especifica que a entrada e a saı́da padrões serão utilizadas.
* **--file** arquivo indica a leitura de um arquivo de entrada arquivo.in e a escrita em um arquivo de saı́da
arquivo.out.  
* **--gz** especifica que a entrada e saı́da usam compactação GZip. Caso esta opção seja usada em combinação com
a opção **--file**, os arquivos de entrada e saı́da serão, respectivamente, **arquivo.in.gz** e **arquivo.out.gz**.

Para implementar a opção **--gz**, utilize a biblioteca **gzstream**. Além disso, sua biblioteca deverá permitir o
uso dos operadores de inserção e extração de streams e não apresentar redundância de código.

## Como Executar
    * make
    * ./bin/executavel [--std, --file nomearquivo]  