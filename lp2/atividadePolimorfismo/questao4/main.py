from quadrado import Quadrado
from retangulo import Retangulo
from circunferencia import Circunferencia

def main():
    quadrado = Quadrado(5)
    retangulo = Retangulo(5,10)
    circunferencia = Circunferencia(10)
    print(circunferencia.calcularArea(), retangulo.calcularArea(), quadrado.calcularArea())
    
if __name__ == "__main__":
    main()