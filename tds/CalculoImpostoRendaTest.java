package param;

import static org.junit.Assert.assertThat;

import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;

import org.hamcrest.CoreMatchers;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class CalculoImpostoRendaTest {
	private double esperado;
	private double salario;
	
	public CalculoImpostoRendaTest(double esperado, double salario) {
		this.esperado = esperado; 
        this.salario = salario;
    }
	
	/**
	 * Este método calcula o imposto a ser pago baseado no valor de uma dada compra.
	 * 
	 * Se  valor < 1201 deve pagar 0% de imposto
	 * Se  1201 <= valor <= 5000 deve pagar 10% de imposto
	 * Se  5001 <= valor <= 10000 deve pagar 15% de imposto
	 * Se  valor > 10000 deve pagar 20% de imposto
	 *
	 */
	@Parameters
	public static Object[][] adicionarValores() {
		return new Double[][] {
			{ 1200.0 * 0, 1200.0}, 
			{1201.0 * 0.1, 1201.0},
			{5000.0 * 0.1, 5000.0},
			{5001.0 * 0.15, 5001.0},
			{10000.0 * 0.15, 10000.0},
			{25000.0 * 0.2, 25000.0}
		};
	}
	
	@Test
	public void testCalcularImposto() {
		ByteArrayOutputStream saida = new ByteArrayOutputStream();
		System.setOut(new PrintStream(saida, true));
		
		CalculoImpostoRenda.calculaImposto(salario);
		assertThat(new String(saida.toByteArray()), CoreMatchers.containsString("Valor em Dinheiro: R$"+esperado));
        
		System.setOut(System.out); 
	}
}
