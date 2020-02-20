public class Richiedente extends Thread{
	private boolean primoCliente = true;
	private Sportello sportello;
	private FinestraPrincipale finestra;
	private Object trigger;


	public Richiedente(String nome, Sportello s, FinestraPrincipale f, Object o){
		setName(nome);
		sportello = s;
		finestra = f;
		trigger = o;
	}

	public void run(){
		System.out.println(currentThread().getName()+": in attesa.");

		try{
			synchronized(trigger){
				trigger.wait();
			}
		}catch(InterruptedException e){
			e.printStackTrace();
		}

		finestra.setAttesaConsegnaModulo();
		sportello.compilaModulo();
		finestra.setAttesaStampaCarta();
		System.out.println(currentThread().getName()+": ha stampato la sua carta d' identita'");
	}


}