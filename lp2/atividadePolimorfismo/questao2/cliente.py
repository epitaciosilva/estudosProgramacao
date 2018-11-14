class Cliente:
	def __init__(self, nome, endereco, telefone):
		self.nome = nome
		self.endereco = endereco
		self.telefone = telefone

	@property
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, nome):
		self.__nome = nome

	@property
	def endereco(self):
		return self.__endereco

	@endereco.setter
	def endereco(self, endereco):
		self.__endereco = endereco

	@property
	def telefone(self):
		return self.__telefone
	
	@telefone.setter
	def telefone(self, telefone):
		self.__telefone = telefone

	def imprimirDados(self):
		print("Nome: {}\nEndereco: {}\nTelefone: {}\n".format(self.nome, self.endereco, self.telefone))




