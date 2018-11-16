from pessoaFisica import PessoaFisica
from pessoaJuridica import PessoaJuridica

class Empresa:
	def __init__(self):
		self.clientes = [];

	def cadastrarCliente(self, cliente):
		self.clientes.append(cliente)

	def imprimirClientes(self):
		for cli in self.clientes:
			cli.imprimirDados()

	def imprimirQtdClientes(self):
		print("Total: " + len(self.cliente))

	@property
	def clientes(self):
		return self._clientes
