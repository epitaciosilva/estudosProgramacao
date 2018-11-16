from cliente import Cliente

class PessoaJuridica(Cliente):
	def __init__(self, nome, endereco, telefone, cnpj, nomeFantasia):
		super().__init__(nome, endereco, telefone)
		self.cnpj = cnpj
		self.nomeFantasia = nomeFantasia
	
	@property
	def cnpj(self):
		return self._cnpj

	@cnpj.setter
	def cnpj(self, cnpj):
		self._cnpj = cnpj

	@property
	def nomeFantasia(self):
		return self._nomeFantasia

	@nomeFantasia.setter
	def nomeFantasia(self, nomeFantasia):
		self._nomeFantasia = nomeFantasia


	def imprimirDados(self):
		print("CNPJ: {}\nNome Fantasia: {}\n".format(self.cnpj, self.nomeFantasia), end="")
		Cliente.imprimirDados(self)
