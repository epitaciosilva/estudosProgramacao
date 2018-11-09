from ponto2d import Ponto2D

class Ponto3D(Ponto2D):
        def __init__(self, x, y, z):
            super().__init__(x,y)
            self.__z = z
        
        def __str__(self):
            return Ponto2D.__str__(self).replace(')', ", {})".format(self.z))
            
        @property
        def z(self):
            return self.__z
        
        @z.setter
        def z(self, z):
            self.__z = z