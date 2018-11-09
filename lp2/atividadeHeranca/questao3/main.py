from automovel import Automovel
from onibus import Onibus
from motocicleta import Motocicleta

def main():
    moto = Motocicleta()
    auto = Automovel()
    bus = Onibus()

    moto.ligar()
    auto.ligar()
    bus.ligar()

    print(moto.isLigado())
    print(auto.isLigado())
    print(bus.isLigado())

    moto.desligar()
    auto.desligar()
    bus.desligar()

    print(moto.isLigado())
    print(auto.isLigado())
    print(bus.isLigado())

if __name__ == "__main__":
    main()