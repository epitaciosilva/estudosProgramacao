from cliente import Cliente

class PessoaJuridica(Cliente):
	def __init__(self, nome, endereco, telefone, cnpj, nomeFantasia):
		super().__init__(nome, endereco, telefone)
		self.cnpj = cnpj
		self.nomeFantasia = nomeFantasia

	@cnpj.setter
	def cnpj(self, cnpj):
		self._cnpj = cnpj

	@property
	def cnpj(self):
		return self._cnpj

	@nomeFantasia.setter
	def nomeFantasia(self, nomeFantasia):
		self._nomeFantasia = nomeFantasia

	@property
	def nomeFantasia(self):
		return self._nomeFantasia

	def imprimirDados(self):
		print("CNPJ: {}\n Nome Fantasia: {}\n".format(self.cnpj, self.nomeFantasia))
		print(Cliente.imprimirDados(self))
