from areaCalculavel import AreaCalculavel

class Circunferencia(AreaCalculavel):
    def __init__(self, raio):
        self.__raio = raio
        self.__pi = 3.14

    def calcularArea(self):
        return 2*self.__pi*self.__raio

