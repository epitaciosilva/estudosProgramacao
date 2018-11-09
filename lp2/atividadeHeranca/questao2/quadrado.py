from figura import Figura

class Quadrado(Figura):
    def __init__(self, lado1):
        super().__init__(lado1, lado1)

    def __str__(self):
        return "\n-----Quadrado-----\n" + Figura.__str__(self)
