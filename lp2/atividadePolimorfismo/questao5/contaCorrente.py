from contaBancaria import ContaBancaria

class ContaCorrente(ContaBancaria):
    def __init__(self):
        super().__init__()

    def calcularSaldoFinal(self):
        return self.saldo - self.saldo*0.1