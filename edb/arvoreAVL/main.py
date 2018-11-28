from no import Node
from avl import AVL

def main():
    avl = AVL()
    value = 0

    while value != -1:
    	value = int(input("Digite um numero: "))
    	avl.add(value)
    	print(avl)

if __name__ == "__main__":
    main()