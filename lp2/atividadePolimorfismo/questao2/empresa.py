from pessoaFisica import PessoaFisica
from pessoaJuridica import PessoaJuridica

class Empresa:
	def __init__(self):
		self.clientes = []

	def cadastrarCliente(self, cliente):
		self.clientes.append(cliente)

	def imprimirClientes(self):
		for cli in self.clientes:
			cli.imprimirDados()

	def imprimirQtdClientes(self):
		print("Total: {}".format(len(self.clientes)))
		print("Pessoas Físicas: {}".format(self.qtdPorTipo(PessoaFisica)))
		print("Pessoas Jurídicas: {}".format(self.qtdPorTipo(PessoaJuridica)))

	def qtdPorTipo(self, tipo):
		return len(list(filter(lambda cli: type(cli) == tipo, self.clientes)))

	@property
	def clientes(self):
		return self.__clientes
	
	@clientes.setter
	def clientes(self, clientes):
		self.__clientes = clientes
