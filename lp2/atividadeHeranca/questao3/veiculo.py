class Veiculo:
    def __init__(self):
        self.status = "OFF"

    def ligar(self):
        self.status = "ON"
    
    def desligar(self):
        self.status = "OFF"
    
    def isLigado(self):
        return self.status == "ON"
    
    @property
    def status(self):
        return self.__status
        
    @status.setter
    def status(self, status):
        self.__status = status

    