from abc import ABC, abstractmethod
class AreaCalculavel(ABC):
    
    @abstractmethod
    def calcularArea(self): 
        return NotImplementedError()