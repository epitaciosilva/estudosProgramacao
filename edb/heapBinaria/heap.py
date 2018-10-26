from copy import copy 
arvore = []

def swap(index1, index2, remover=False):
    global arvore
    if not remover:
        value = copy(arvore[index1])
        arvore[index1] = copy(arvore[index2])
        arvore[index2] = value
    else: 
        arvore[index1] = copy(arvore[index2])
        arvore.pop(index2)

def heap():
    index = len(arvore)-1
    pai = (index-1)//2

    while index > 0: # enquanto não chegar na raiz
        pai = (index-1)//2
        if arvore[pai] < arvore[index]:
            break
        swap(index, pai)
        index = copy(pai)

def pop():
    if len(arvore) == 0:
        return
    elif len(arvore) == 1:
        arvore.pop(0)
        return

    swap(0, len(arvore)-1, remover=True)

    index = 0
    while(True):
        posicao = 0
        filhoEsquerdo = index*2+1
        filhoDireito = index*2+2

        if filhoDireito >= len(arvore) or arvore[filhoEsquerdo] <= arvore[filhoDireito]:
            posicao = copy(filhoEsquerdo)
        else: 
            posicao = copy(filhoEsquerdo)
        
        if arvore[posicao] < arvore[index]:
            swap(index, posicao)
            index = copy(posicao)
        else:
            break

def push(value):
    global arvore
    arvore.append(value)
    heap()

push(20)
push(10)
push(30)
push(8)
push(5)
print(arvore)
pop()
print(arvore)