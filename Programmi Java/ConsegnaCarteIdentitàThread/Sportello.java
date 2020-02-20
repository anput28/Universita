import java.util.Random;

public class Sportello{

	public synchronized void consegnaModulo(){
		System.out.println(Thread.currentThread().getName() +" ha ricevuto il modulo.");
	}

	public void compilaModulo(){
		Random rand = new Random();
		int tempoCompilazione = 1000 + rand.nextInt(9000);
		System.out.println(Thread.currentThread().getName() + " sta compilando il modulo.");
		try{
			Thread.sleep(tempoCompilazione);
		}catch(InterruptedException e){
			e.printStackTrace();
		}
	}

	public synchronized void stampaCarta(){
		try{
			Thread.sleep(3000);
		}catch(InterruptedException e){
			e.printStackTrace();
		}

		System.out.println("Stampata la carta di identita' di "+Thread.currentThread().getName());
	}
}