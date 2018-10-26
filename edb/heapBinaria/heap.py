from copy import copy 
arvore = []

def pai(index):
    return (index-1)//2

def filhoEsquerdo(index):
    return index*2+2

def filhoDireito(index):
    return index*2+1

def swap(index1, index2):
    global arvore
    value = copy(arvore[index1])
    arvore[index1] = copy(arvore[index2])
    arvore[index2] = value

def remove(index1, index2):
    arvore[index1] = copy(arvore[index2])
    arvore.pop(index2)

def heapify(index):
    global arvore

    esquerdo = filhoEsquerdo(index)
    direito = filhoDireito(index)
    maior = 0

    if esquerdo <= len(arvore)-1 and arvore[esquerdo] < arvore[index]:
        maior = esquerdo
    else:
        maior = index

    if direito <= len(arvore)-1 and arvore[direito] < arvore[maior]:
        maior = direito

    if maior != index:
        swap(index, maior)
        heapify(maior)

def pop():
    if len(arvore) == 0:
        return
    elif len(arvore) == 1:
        arvore.pop(0)
        return

    remove(0, len(arvore)-1)
    contruirHeapify()

def push(value):
    global arvore
    arvore.append(value)
    contruirHeapify()

def contruirHeapify():
    i = pai(len(arvore)-1)
    
    while i >= 0:
        heapify(i)
        i -= 1

push(20)
push(10)
push(5)
push(8)
push(3)
push(30)
print(arvore)
pop()
print(arvore)

