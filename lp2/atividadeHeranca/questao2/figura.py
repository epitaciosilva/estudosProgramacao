class Figura:
    def __init__(self, lado1, lado2):
        self.lado1 = lado1
        self.lado2 = lado2

    def __str__(self):
        return "Lado 1: {} \nLado 2: {} \nÁrea da figura: {}".format(self.lado1, self.lado2, self.calcularArea())
    
    def calcularArea(self):
        return self.lado1*self.lado2

    @property
    def lado1(self):
        return self.__lado1

    @lado1.setter
    def lado1(self, lado1):
        self.__lado1 = lado1

    @property
    def lado2(self):
        return self.__lado2

    @lado2.setter
    def lado2(self, lado2):
        self.__lado2 = lado2