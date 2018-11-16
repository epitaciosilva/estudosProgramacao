class Viajante:
	def __init__(self, cls):
		self.__cls = cls

	def dizerOla(self):	
		self.__cls.dizerOla(self)

class Brasileiro(Viajante):
	def dizerOla(self):
		print("Olá")

class Espanhol(Viajante):
	def dizerOla(self):	
		print("Hola")

class Americano(Viajante):
	def dizerOla(self):
		print("Hello")

v1 = Viajante(Americano)
v2 = Viajante(Espanhol)
v3 = Viajante(Brasileiro)

v1.dizerOla()
v2.dizerOla()
v3.dizerOla()
