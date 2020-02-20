#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lancio ();

int main(){
	srand(time(NULL));
	int punto = 0, partiteVinte = 0, cont = 1, i = 0;
	int risultato, flag;
	char carattere;
	float saldo = 1000, puntata;
	
	printf("%50s","---GIOCO DEI DADI---\n");
	printf("Il tuo saldo corrente : %.2f\n", saldo);
	do{
		printf("%25s %d :\n","Manche", cont);
		do{
			printf("\n%s","Quanto vuoi scommettere? ");
			scanf("%f", &puntata);
			if(puntata > saldo){
				printf("%s", "Non hai abbastanza soldi.");
			}
		}while(puntata > saldo);
		flag = 0;
		risultato = lancio();
		cont++;
		printf("La somma dei due dadi lanciati e' pari a : %d\n",risultato);
		switch(risultato){
			case 7:
			case 11:
				flag = 1;
				break;
			case 2:
			case 3:
			case 12:
				break;
			default:
				punto = risultato;
				puts("Vediamo se sei fortunato :");
				do{
					i++;
					risultato = lancio();
					printf("%10s %d ---> %d\n","Lancio", i , risultato);
				}while((risultato != punto) && (risultato != 7));
				i = 0;
				
				if(risultato == punto){
					flag = 1;
				}
				break;
		}
		
		if(flag == 1){
			partiteVinte++;
			saldo += puntata;
			puts("_______________________________________");
			puts("Hai vinto questa manche!");
			printf("Saldo attuale : %.2f\n", saldo);
			puts("_______________________________________");
		}else{
			saldo -= puntata;
			puts("_______________________________________");
			puts("Hai perso questa manche!");
			printf("Saldo attuale : %.2f\n", saldo);
			puts("_______________________________________");
		}
		//--------------------------------------------------------------------
		if(saldo <= 200){
			puts("Oh, stai per andare a secco...");
		}
		
		//-------------------------------------------------------------------
		if(saldo <= 0){
			puts("Non hai abbastanza soldi per giocare ancora!");
			carattere = 'n';
		}else{
			puts("Vuoi continuare a giocare (s/n)?");
			scanf(" %c", &carattere);
		}
		
	}while(carattere == 's');
	
	printf("\nHai vinto %d manche!\n", partiteVinte);
	

	return 0;
}

int lancio () {
	int dado1 = 1 + (rand() % 6);
	int dado2 = 1 + (rand() % 6);
	return dado1 + dado2;
}
