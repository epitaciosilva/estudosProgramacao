from no import Node

class AVL:
    def __init__(self):
        self.root = None

    def __add(self, value, node):
        if node == None:
            return Node(value)
        
        if value < node.value:
            node.left = self.__add(value, node.left)
        else:
            node.right  = self.__add(value, node.right)

        return self.__balance(node)

    def add(self, value):
        self.root = self.__add(value, self.root)

    def rotationRight(self, node):
        tmp       = node.left
        node.left  = tmp.right
        tmp.right = node
        
        return tmp

    def rotationLeft(self, node):
        tmp       = node.right
        node.right = tmp.left
        tmp.left  = node
        
        return tmp

    def __balance(self, node):
        if node != None:
            if node.fb < -1 and node.right != None:
                if node.right.fb <= 0: 
                    node = self.rotationLeft(node)
            elif node.fb > 1 and node.left != None:
                if node.left.fb >= 0:
                    node = self.rotationRight(node)
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