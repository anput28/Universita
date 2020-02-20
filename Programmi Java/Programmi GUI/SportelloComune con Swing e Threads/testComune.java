/* Aggiungere una finestra con i nomi di chi finisce di compilare il modulo ed è pronto a stampare la carta.
Aggiungere finestra con i nomi dei clienti serviti definitivamente*/

public class testComune{
	public static void main(String args[]){
		Object oggetto = new Object();
		Object oggetto2 = new Object();
		String nomi[] = {"1) Pietro", "2) Carmela","3) Francesca", "4) Angelo", "5) Arianna", "6) Gherard", "7) Rosemary", "8) Giuseppe", "9) Giusy", "10) Giulio"};
		
		Sportello consegnaCarteIdentita = new Sportello(oggetto2);
		
		FinestraPrincipale fp = new FinestraPrincipale(oggetto, oggetto2);
		fp.setVisible(true);

		Richiedente persone[] = new Richiedente[nomi.length];
		
		for(int i = 0; i < persone.length; i++){
			persone[i] = new Richiedente(nomi[i], consegnaCarteIdentita, fp, oggetto);
		}

		for(int i = 0; i < persone.length; i++){
			persone[i].start();
		}

	}
}