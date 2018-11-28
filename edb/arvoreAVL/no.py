class Node:
    def __init__(self, value):
        self.value = value
        self.__height = 0
        self.__fb = 0
        self.__left = None
        self.__right = None
    
    @property
    def height(self):
        return self.__height
    
    @property
    def fb(self):
        return self.__fb

    def __update(self):
        left = self.left.height if self.left else -1
        right = self.right.height if self.right else -1

        self.__height = 1 + max(left, right)
        self.__fb = left - right

    @property
    def left(self):
        return self.__left

    @left.setter
    def left(self, node):
        self.__left = node
        self.__update()

    @property
    def right(self):
        return self.__right

    @right.setter
    def right(self, node):
        self.__right = node
        self.__update()
