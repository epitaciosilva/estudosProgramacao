from  figura import Figura

class FiguraComplexa(Figura):
    def __init__(self, *args):
        self.figuras = args

    def __str__(self):
        string = "-----Figura Complexa-----\n"
        string += "Área da figura complexa: {}".format(self.calcularArea())

        for fig in self.figuras:
            string += "\n"+str(fig)
        
        return string

    def calcularArea(self):
        area = 0

        for fig in self.figuras:
            area += fig.calcularArea()

        return area
        
    @property
    def figuras(self):
        return self.__figuras

    @figuras.setter
    def figuras(self, args):
        self.__figuras = [fig for fig in args]
