from veiculo import Veiculo

class Onibus(Veiculo):
    def __init__(self):
        super().__init__()

    def ligar(self):
        print("Ônibus ligado")
        self.status = "ON"

    def desligar(self):
        print("Ônibus desligado")
        self.status = "OFF"
    