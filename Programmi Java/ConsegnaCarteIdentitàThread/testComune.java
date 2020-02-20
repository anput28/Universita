public class testComune{
	public static void main(String args[]){
		String nomi[] = {"1) Pietro", "2) Carmela","3) Francesca", "4) Angelo", "5) Arianna", "6) Gherard", "7) Rosemary", "8) Giuseppe", "9) Giusy", "10) Giulio"};
		Sportello consegnaCarteIdentita = new Sportello();
		Richiedente persone[] = new Richiedente[nomi.length];
		
		for(int i = 0; i < persone.length; i++){
			persone[i] = new Richiedente(nomi[i], consegnaCarteIdentita);
		}

		for(int i = 0; i < persone.length; i++){
			persone[i].start();
		}

	}
}