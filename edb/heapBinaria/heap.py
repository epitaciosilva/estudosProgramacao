from copy import copy 

class HeapBinaria:
    def __init__(self):
        self.arvore = []

    def pai(self, index):
        return (index-1)//2

    def filhoEsquerdo(self, index):
        return index*2+2

    def filhoDireito(self, index):
        return index*2+1

    def swap(self, index1, index2):
        value = copy(self.arvore[index1])
        self.arvore[index1] = copy(self.arvore[index2])
        self.arvore[index2] = value

    def remove(index1, index2):
        self.arvore[index1] = copy(self.arvore[index2])
        self.arvore.pop(index2)

    def heapify(self, index):
        esquerdo = self.filhoEsquerdo(index)
        direito = self.filhoDireito(index)
        maior = 0

        if esquerdo <= len(self.arvore)-1 and self.arvore[esquerdo] < self.arvore[index]:
            maior = esquerdo
        else:
            maior = index

        if direito <= len(self.arvore)-1 and self.arvore[direito] < self.arvore[maior]:
            maior = direito

        if maior != index:
            self.swap(index, maior)
            self.heapify(maior)

    def pop(self):
        if len(self.arvore) == 0:
            return
        elif len(self.arvore) == 1:
            self.arvore.pop(0)
            return

        self.remove(0, len(self.arvore)-1)
        self.contruirHeapify()

    def push(self,value):
        self.arvore.append(value)
        self.contruirHeapify()

    def contruirHeapify(self):
        i = self.pai(len(self.arvore)-1)
        
        while i >= 0:
            self.heapify(i)
            i -= 1
    def print(self):
        print(self.arvore)

heap = HeapBinaria()
heap.push(20)
heap.push(10)
heap.push(5)
heap.push(8)
heap.push(3)
heap.push(30)
heap.print()