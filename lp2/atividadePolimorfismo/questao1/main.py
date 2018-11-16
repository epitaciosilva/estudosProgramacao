class Viajante:
	def dizerOla(self):
		if (type(self) == Espanhol):
			print("Hola")
		elif(type(self) == Americano):
			print("Hello")
		elif(type(self) == Brasileiro):
			print("OLá")

class Espanhol(Viajante):
	def __init__(self):
		pass

class Brasileiro(Viajante):
	def __init__(self):
		pass
class Americano(Viajante):
	def __init__(self):
		pass

v1 = Espanhol()
v2 = Brasileiro()
v3 = Americano()

v1.dizerOla()
v2.dizerOla()
v3.dizerOla()