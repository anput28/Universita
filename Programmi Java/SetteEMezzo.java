import java.util.*;

public class SetteEMezzo{
	public static void main(String args[]){
		double carte[] = {0.5, 1, 2, 3, 4, 5, 6, 7};
		boolean isMatta =  false; 
		boolean sballato = false;

		double carteRicevute = 0.0;
		double nuovaCarta = 0.0;
		double sommaCarte = 0.0;

		double carteCPU = 0.0;
		String risposta;

		Scanner input = new Scanner(System.in);
		Random rand = new Random();

		System.out.println("SETTE E MEZZO\n\n\n");

		//GIOCATA DELL'UTENTE
		carteRicevute = carte[rand.nextInt(8)];
		System.out.println("Hai ricevuto la carta: "+carteRicevute);

		//gestione del 4
		if(carteRicevute == 4){
			System.out.println("Vuoi cambiare carta?(si/no)");
			risposta = input.next();
			if(risposta.equals("si")){
				carteRicevute = carte[rand.nextInt(8)];
				System.out.println("\nHai ricevuto la carta: "+carteRicevute);
			}
		}
		
		//Gestione della matta
		if(carteRicevute == 0.5){
			isMatta = rand.nextBoolean();
			if(isMatta == true){
				System.out.println("Hai ricevuto la matta.");
				System.out.println("\nVuoi far valere la matta 0.5? (si/no)");
				risposta = input.next();
				if(risposta.equals("no")){
					do{
						System.out.println("\nQuanto vuoi farla valere? (1-7)");
						carteRicevute = input.nextDouble();
					}while(carteRicevute < 1 && carteRicevute > 7);
				}
			}
		}

		do{
			System.out.print("Vuoi un'altra carta? (si/no)\n-> ");
			risposta = input.next();

			if(risposta.equals("si")){
				nuovaCarta = carte[rand.nextInt(8)];
				if(isMatta == false){
					if(nuovaCarta == 0.5){
						isMatta = rand.nextBoolean();
						if(isMatta == true){
							System.out.println("E' uscita la matta.");
							System.out.println("\nVuoi far valere la matta 0.5? (si/no)");
							risposta = input.next();
							if(risposta.equals("no")){
								do{
									System.out.println("\nQuanto vuoi farla valere? (1-7)");
									nuovaCarta = input.nextDouble();
								}while(carteRicevute < 1 && carteRicevute > 7);
							}
						}
					}
				}

				carteRicevute += nuovaCarta;
				System.out.println("La somma delle carte attuali e': "+carteRicevute+"\n");
			}
		}while(carteRicevute < 7.5 && risposta.equals("si"));
	
		if(carteRicevute > 7.5){
			System.out.println("Hai sballato, vince il mazziere.");
			sballato = true;
		}else if(carteRicevute == 7.5){
			System.out.println("Hai fatto sette e mezzo, vediamo cosa fa il mazziere...");
		}

		//GIOCATA DELLA CPU
		if(sballato == false){
			do{
				carteCPU += carte[rand.nextInt(8)];
				System.out.println("Il mazziere fa: "+carteCPU);
			}while(carteCPU < carteRicevute);

			if(carteCPU > 7.5){
				System.out.println("\nIl mazziere ha sballato.");
				carteCPU = 0.0;
			}

			if(carteCPU > carteRicevute && carteCPU <= 7.5){
				System.out.println("\nMi dispiace hai perso!");
			}else if(carteCPU == carteRicevute){
				if(isMatta == true){
					System.out.println("\nComplimenti hai vinto!");
				}else{
					System.out.println("\nMi dispiace hai perso!");
				}
			}else if(carteRicevute > carteCPU && sballato == false){
				System.out.println("\nComplimenti hai vinto!");
			}
		}
	}
		
}