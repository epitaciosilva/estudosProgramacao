class HeapBinaria:
    def __init__(self):
        self.tree = []
    
    def __str__(self):
        return str(self.tree)

    def parent(self, index):
        return (index-1)//2

    def childLeft(self, index):
        return index*2+2

    def childRight(self, index):
        return index*2+1

    def swap(self, index1, index2):
        self.tree[index1],self.tree[index2] = self.tree[index2],self.tree[index1]

    def remove(index1, index2):
        self.tree[index1] = self.tree[index2]
        self.tree.pop(index2)

    def heapify(self, index):
        left = self.childLeft(index)
        right = self.childRight(index)
        largest = 0

        if left <= len(self.tree)-1 and self.tree[left] < self.tree[index]:
            largest = left
        else:
            largest = index

        if right <= len(self.tree)-1 and self.tree[right] < self.tree[largest]:
            largest = right

        if largest != index:
            self.swap(index, largest)
            self.heapify(largest)

    def pop(self):
        if len(self.tree) == 0:
            return
        elif len(self.tree) == 1:
            self.tree.pop(0)
            return

        self.remove(0, len(self.tree)-1)
        self.buildHeapify()

    def push(self,value):
        self.tree.append(value)
        self.buildHeapify()

    def buildHeapify(self):
        i = self.parent(len(self.tree)-1)
        
        while i >= 0:
            self.heapify(i)
            i -= 1


heap = HeapBinaria()
heap.push(20)
heap.push(10)
heap.push(5)
heap.push(8)
heap.push(3)
heap.push(30)
print(heap)
