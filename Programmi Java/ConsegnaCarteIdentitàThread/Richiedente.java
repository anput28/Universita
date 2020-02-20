public class Richiedente extends Thread{
	private Sportello sportello;

	public Richiedente(String nome, Sportello s){
		setName(nome);
		sportello = s;
	}

	public void run(){
		System.out.println(currentThread().getName() + " in attesa di ritirare il modulo.");
		sportello.consegnaModulo();

		sportello.compilaModulo();
		sportello.stampaCarta();
	}
}