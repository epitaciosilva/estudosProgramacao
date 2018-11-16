from cliente import Cliente

class PessoaFisica(Cliente):
	def __init__(self, nome, endereco, telefone, cpf):
		super().__init__(nome, endereco, telefone)
		self.cpf = cpf

	@property
	def cpf(self):
		return self._cpf

	@cpf.setter
	def cpf(self, cpf):
		self._cpf = cpf

	def imprimirDados(self):
		print("CPF: {}".format(self.cpf))
		Cliente.imprimirDados(self)
