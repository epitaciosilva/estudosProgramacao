from veiculo import Veiculo

class Motocicleta(Veiculo):
    def __init__(self):
        super().__init__()

    def ligar(self):
        print("Motocicleta ligada")
        self.status = "ON"
    
    def desligar(self):
        print("Motocicleta desligada")
        self.status = "OFF"
    