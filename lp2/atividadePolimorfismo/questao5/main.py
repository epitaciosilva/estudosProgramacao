from contaCorrente import ContaCorrente
from contaInvestimento import ContaInvestimento

def main():
    cc = ContaCorrente()
    ci = ContaInvestimento()

    cc.depositar(5000)
    ci.depositar(1000)
    print(cc.calcularSaldoFinal())
    print(ci.calcularSaldoFinal(), "\n")

    cc.sacar(2000)
    ci.sacar(500)
    print(cc.calcularSaldoFinal())
    print(ci.calcularSaldoFinal(), "\n")

    cc.transferir(1000, ci)

    print(cc.calcularSaldoFinal())
    print(ci.calcularSaldoFinal())

if __name__ == "__main__":
    main()