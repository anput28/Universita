public class Conteggio extends Thread{
	private int numero;
	private FinestraPrincipale finestra;
	private Object lock;
	
	private static boolean stato = true; //true = conteggio crescente, false = conteggio decrescente
	public static boolean inAttesa = false;

	public Conteggio(FinestraPrincipale f, int n, Object l){
		setName("Conteggio");
		finestra = f;
		numero = n;
		lock = l;
	}

	public int getNumero(){
		return numero;
	}

	public void setNumero(int n){
		numero = n;
	}

	public static void fermati(boolean b){
		inAttesa = b;
	}

	public static void cambiaStato(boolean s){
		stato = s;
	}

	/*conta e stampa sul JTextFiled della finestra i numeri pari.
	Quando viene cliccato il tasto stop della finestra viene invocato il metodo cambiaStato() che segnala se il thread deve
	essere messo in attesa oppure deve riprendere l'esecuzione (cioè cambia il valore della variabile di classe inAttesa).
	Se inAttesa viene messo al valore true allora il thread si mette nello stato di attesa e attende un notify.*/

	public void conteggioCrescente(){
		numero += 2;
		finestra.setNumero(numero);

		try{
			Thread.sleep(500);
		}catch(InterruptedException e){
			e.printStackTrace();
		}

		if(inAttesa){
			synchronized(lock){
				try{
					lock.wait();
				}catch(InterruptedException exc){
					exc.printStackTrace();
				}	
			}
		}
	}

	public void conteggioDecrescente(){
		if(numero > 0){
			numero -= 2;
			finestra.setNumero(numero);

			try{
				Thread.sleep(500);
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
		

		if(inAttesa){
			synchronized(lock){
				try{
					lock.wait();
				}catch(InterruptedException exc){
					exc.printStackTrace();
				}	
			}
		}
	}

	/*Il thread si mette in attesa di un notify per iniziare a contare e durante la sua esecuzione verifica sempre il suo stato,
	cioè se deve contare in modo crescente o decrescente, quindi in base al valore della variabile stato esegue un conteggio o un altro.*/
	public void run(){
		synchronized(lock){
			try{
				lock.wait();
			}catch(InterruptedException exc){
				exc.printStackTrace();
			}	
		}

		while(true){
			if(stato){
				conteggioCrescente();
			}else{
				conteggioDecrescente();
			}
		}
	}
}