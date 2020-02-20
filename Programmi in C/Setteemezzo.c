#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matta (int, int);
float lancio ();

int main(){
	srand(time(NULL));
	
	//dichiarazione e assegnazione variabili
	float carta, cartaMazziere, puntoGioc, puntoMazz;
	char risp;
	int flagMattaMazziere = 0, flagMatta = 0;
	
	puts("REGOLE SETTE E MEZZO:");
	printf("Valore carte:\nDa 1 a 7 hanno il loro valore;\n8, 9 e 10 valgono 0.5.\nPer indicare la matta viene usato l'11.\n");
	printf("Ricevi una carta dal mazziere, se questa e' un 4 la puoi cambiare.\n");
	printf("Se ricevi l'11 (cioe' la matta) alla prima mano o dopo che hai cambiato il 4,\npuoi scegliere un valore da 0.5 a 7 con cui giocarla.");
	printf("Potrai scegliere se ricevere altre carte per avvicinarti a 7.5,\nse vai oltre questo punteggio 'sballi' quindi perdi la partita.");
	printf("Se alla fine della mano tu e il mazziere avrete carte uguali vince il mazziere, tranne se tu hai la matta.\n");
	puts("-------------------------------------------------------------------------------");
	carta = lancio();
	printf("LA TUA CARTA -> %.1f\n", carta);
	//gestione del 4 come prima carta
	if(carta == 4){
		puts("Vuoi cambiare carta?");
		scanf(" %c", &risp);
		if(risp == 's'){
			carta = lancio();
		}
		printf("LA TUA CARTA INZIALE -> %.1f\n", carta);
	}
	//gestione della matta come prima carta
	if(carta == 11){
		carta = matta(carta, flagMatta);
		printf("LA TUA CARTA INZIALE -> %.1f\n", carta);
	}
	//stampa carta con cui si inizia a giocare
	puntoGioc = carta;
	
	//Giocata dell'utente
	printf("Vuoi un'altra carta (s/n) ?");
	scanf(" %c", &risp);
	if(risp == 's'){	
		while(risp == 's'){
			if(puntoGioc < 7.5){
				carta = lancio();
				printf("\tCarta ricevuta -> %.1f\n", carta);
				if(carta == 11){
					carta = matta(carta, flagMatta);
				}
				puntoGioc += carta;	
				printf("\tPunteggio corrente -> %.1f\n", puntoGioc);
				printf("\tVuoi un'altra carta (s/n) ?");
				scanf("\t %c", &risp);
			}else{
				puts("\tNon puoi ricevere altre carte.");
				risp = 'n';
			}
		}	
	}
	
	printf("IL TUO PUNTEGGIO -> %.1f\n", puntoGioc);
	if(puntoGioc > 7.5){
		puts("Hai sballato!\nParita vinta dal mazziere.");
	}else{
		//Giocata del Mazziere
		cartaMazziere = lancio();
		printf("\nCARTA INIZIALE DEL MAZZIERE -> %.1f\n", cartaMazziere);
		if(cartaMazziere < puntoGioc){
			puntoMazz = cartaMazziere;
			do{
				cartaMazziere = lancio();
				if(cartaMazziere == 11){
					flagMattaMazziere = 1;
					if(puntoMazz == 7){
						cartaMazziere = 0.5;
					}else{
						cartaMazziere = (int) (7 - puntoMazz);
					}
				}
				puntoMazz += cartaMazziere;
			}while(puntoMazz < puntoGioc);
			printf("PUNTEGGIO MAZZIERE -> %.1f\n", puntoMazz);
			
			if(puntoMazz <= 7.5){
				if(puntoMazz == puntoGioc){
					if(flagMattaMazziere == 0){
						if(flagMatta == 1){
							printf("Hai vinto, perche' hai la matta, con il punteggio di %.1f", puntoGioc);
						}else{
							puts("Hai perso!");
						}
					}else{
						puts("Hai perso, perche' il mazziere ha la matta.");
					}
				}else{
					printf("Hai perso!\nPartita vinta dal mazziere con il punteggio di %.1f.", puntoMazz);
				}
			}else{
				printf("Il mazziere ha sballato.\nHai vinto con il punteggio di %.1f.", puntoGioc);
			}
		}else{
			printf("Hai perso!\nPartita vinta dal mazziere con il punteggio di %.1f.", puntoMazz);
		}
	}
	
return 0;
}

int matta (int cartaMatta, int flagMattaGioc){
	flagMattaGioc = 1;
	while(cartaMatta < 1 || cartaMatta > 7){
		puts("Quanto vuoi far valere la matta (da 1 a 7) ? ");
		scanf("%d", &cartaMatta);	
		if(cartaMatta < 1 || cartaMatta > 7){
			puts("Numero non valido! Inserire valore da 1 a 7 per continuare.");
		}
	}
	return cartaMatta;
}

float lancio (){
	float array[9] = {1,2,3,4,5,6,7,0.5,11};
	int indiceRandom = rand() % 9;
	return array[indiceRandom];
}

