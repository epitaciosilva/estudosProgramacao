from veiculo import Veiculo

class Automovel(Veiculo):
    def __init__(self):
        super().__init__()

    def ligar(self):
        print("Automóvel ligado")
        self.status = "ON"
    
    def desligar(self):
        print("Automóvel desligado")
        self.status = "OFF"
    