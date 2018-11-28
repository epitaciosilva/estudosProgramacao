from abc import ABC, abstractmethod

class ContaBancaria(ABC):
    def __init__(self):
        self.saldo = 0

    def depositar(self, valor):
        self.saldo += valor

    def sacar(self, valor):
        if valor > self.saldo:
            print("Valor indiponível!")
            return False
        else:
            self.saldo -= valor
            return True

    def transferir(self, valor, contaBancaria):
        if self.sacar(valor):
            contaBancaria.depositar(valor)

    @abstractmethod
    def calcularSaldoFinal(self):
        raise NotImplementedError()

    @property
    def saldo(self):
        return self.__saldo

    @saldo.setter
    def saldo(self, saldo):
        self.__saldo = saldo