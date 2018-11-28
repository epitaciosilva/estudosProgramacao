from no import Node

class AVL:
    def __init__(self):
        self.root = None

    def __add(self, value, node):
        if node == None:
            return Node(value)
        
        if value > node.value:
            node.left = self.__add(value, node.left)
        else:
            node.right  = self.__add(value, node.right)

        return self.__balance(node)

    def add(self, value):
        self.root = self.__add(value, self.root)

    def rotationRight(self, node):
        no = node.right
        node.right = no.left
        node.left = no

        return no

    def rotationLeft(self, node):
        no = node.left
        node.left = no.left
        node.right = no

        return no

    def __balance(self, node):
        if node != None:
            if node.fb > 1:
                if node.right != None and node.right.fb >= 0: 
                    node = self.rotationRight(node)
            elif node.left != None and node.fb < -1:
                if node.left <= 0:
                    node = self.rotationLeft(node)

        return node

    def __str__(self):
        iter = self.root
        if iter != None:
            print(iter.value)
            while iter.left != None:
                print(iter.left.value)
                iter = iter.left
            
            iter = self.root
            while iter.right != None:
                print(iter.right.value)
                iter = iter.right
            
        return " "