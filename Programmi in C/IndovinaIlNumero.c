#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	srand(time(NULL));
	int numComputer, numGiocatore;
	char risp;
	
	do{
		numComputer = 1 + rand() % 1000;
		printf("%s", "Ho un numero da 1 a 1000.\nRiesci a indovinare il mio numero?\nInserisci la tua prima risposta.\n -> ");
		scanf("%d", &numGiocatore);
		
		if(numGiocatore != numComputer){
			while(numGiocatore != numComputer){
				if(numGiocatore > numComputer){
					puts("Troppo alto. Riprova.");
				}else{
					puts("Troppo basso. Riprova.");
				}
				printf("%s", " -> ");
				scanf("%d", &numGiocatore);
			}	
		}
		if(numGiocatore == numComputer){
			puts("Eccellete! Hai indovinato il numero!\nVuoi giocare ancora (s/n)?");
			scanf(" %c", &risp);
		}
	}while(risp == 's');
	
	printf("%s", "Grazie di aver giocato! Arrivederci.");
	
	return 0;
}


