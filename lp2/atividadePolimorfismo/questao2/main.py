from pessoaFisica import PessoaFisica
from pessoaJuridica import PessoaJuridica
from empresa import Empresa

if __name__ == "__main__":
	pessoaFisica = PessoaFisica("João", "Natal", "(12) 34567-8901", "12345678901")
	pessoaJuridica1 = PessoaJuridica("Coca", "EUA", "(00) 1111-2222", "180378123712", "Coca-cola")
	pessoaJuridica2 = PessoaJuridica("Dolly", "BR", "(00) 1111-2222", "180378123712", "Dolly Guarana")
	empresa = Empresa()

	empresa.cadastrarCliente(pessoaFisica)
	empresa.cadastrarCliente(pessoaJuridica1)
	empresa.cadastrarCliente(pessoaJuridica2)
	
	empresa.imprimirClientes()
	empresa.imprimirQtdClientes()