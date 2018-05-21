## Simulador de uma agência bancária

### Descrição da tarefa

* Implemente em C++ as respectivas classes, atributos e métodos (incluindo
construtores e destrutor) necessários para atender às seguintes abstrações:
  * Uma conta corrente possui uma agência, um número, um saldo, um status que informa se ela é
especial ou não, um limite (no caso de conta especial) e um conjunto de movimentações
(normalmente em grande número e variável entre contas).
  * Uma movimentação possui uma descrição, um valor e uma indicação se ela é uma
movimentação de crédito ou débito.

* Usando as classes implementadas, escreva um programa em C++ para simular
uma agência bancária que deve armazenar um conjunto de contas e permitir
as seguintes operações básicas:
  * Criações de conta, exclusão de contas, saques (respeitando o saldo e o limite), depósitos,
emissão de saldo e extrato, além de transferência entre contas.
  * Especificamente com relação à emissão de extrato, seu programa deverá exibir a lista de
movimentações realizadas por meio da sobrecarga do operador de inserção em stream (<<).
### Como executar
* make
* ./bin/executavel