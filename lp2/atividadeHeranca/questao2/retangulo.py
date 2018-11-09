from figura import Figura

class Retangulo(Figura):
    def __init__(self, lado1, lado2):
        super().__init__(lado1, lado2)

    def __str__(self):
        return "\n-----Retangulo-----\n" + Figura.__str__(self)
