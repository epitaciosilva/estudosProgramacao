from quadrado import Quadrado
from retangulo import Retangulo
from figuraComplexa import FiguraComplexa

def main():
    figuraComplexa = FiguraComplexa(Quadrado(3), Quadrado(10), Retangulo(2,7), Retangulo(5,3))
    print(figuraComplexa)

if __name__ == "__main__":
    main()