from areaCalculavel import AreaCalculavel

class Retangulo(AreaCalculavel):
    def __init__(self, lado1, lado2):
        self.__lado1 = lado1
        self.__lado2 = lado2

    def calcularArea(self):
    	return self.__lado1*self.__lado2