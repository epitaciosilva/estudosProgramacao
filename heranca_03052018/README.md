## Simulador de um depósito
### Descrição da tarefa

1. Utilizando os conceitos de herança, crie as classes descritas
abaixo:
    * Classe Produto:
        - Atributos: nome, preço, marca, descrição, data de fabricação.
    * Classe Produto Durável (herdando da classe produto):
        - Atributos: material predominante, durabilidade.
    * Classe Produto não Durável (herdando da classe Produto):
        - Atributos: data de validade, gênero (alimentício, produto de limpeza, roupa,    produto de uso pessoal).
        
2. Implementação
    * Crie, pelo menos mais 3 classes que herdam da classe Produto Durável (carro, livro, celular) e 3 da classe Produto não Durável (pizza, refrigerante chocolate) e que possuem atributos e métodos relevantes para essa classe.

3. Crie uma classe depósito que armazena qualquer tipo de produto,
implementados anteriormente, que possua os seguintes métodos:
    * Adicionar produto.
    * Remover produto.
    * Informar quantidade de produtos no depósito
    * Informar se o depósito está vazio;
    * Informar o produto com maior valor.