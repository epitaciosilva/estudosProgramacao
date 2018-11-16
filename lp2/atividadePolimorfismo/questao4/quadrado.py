from areaCalculavel import AreaCalculavel

class Quadrado(AreaCalculavel):
    def __init__(self, lado):
        self.__lado = lado

    def calcularArea(self):
    	return self.__lado**2

