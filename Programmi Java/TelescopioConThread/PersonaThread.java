public class PersonaThread extends Thread{
	private Telescopio t;

	PersonaThread(Telescopio t, String nome){
		setName(nome);
		this.t = t;
	}

	public void run(){
		//stampa per evidenziare il fatto che ogni thread instanziato si mette in attesa di essere servito dallo scheduler
		System.out.println(getName()+" in attesa di osservare la cometa.");
		System.out.println(getState());

		/*una volta instanziato un thread prova ad usare il telescopio.
		La chiamata al metodo osservazione è stata racchiusa in metodo synchronized sull'oggetto telescopio.
		Questo vuol dire che se più thread vogliono invocare il metodo osservazione lo potranno fare ma uno per volta.*/
		synchronized(t){
			t.osservazione();
		}

		System.out.println(getState());
	}
}