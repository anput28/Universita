/* Scrivere un programma che prenda in input i dati di 10 studenti (Nome, Cognome, classe, voti), raggruppi gli studenti della stessa classe,
calcoli la media dei voti di ogni studente e la media della classe*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MATERIE 8
#define STUDENTI 5
#define LENGHTNAME 16
#define LENGHTSURNAME 21


typedef struct{
	char cognome[LENGHTSURNAME];
	char nome[LENGHTNAME];
	char classe;
	unsigned int voti[MATERIE];
}dati;

int main (){
	dati studente[STUDENTI] = {0};
	char *materie[MATERIE] = {"Italiano", "Matematica", "Inglese", "Storia", "Informatica", "Chimica", "Fisica", "Educazione Fisica"};
	int valido = 0; //flag per verificare la validità del nome e del cognome
	int sommaVotiStudente = 0;
	float mediaVotiStudente[STUDENTI] = {0};
	float sommaClasseA = 0;
	float sommaClasseB = 0;
	float mediaClasseA = 0;
	float mediaClasseB = 0;
	int numClasseA = 0; //numero degli studenti della classe A
	int numClasseB = 0; //numero degli studenti della classe B
	
	size_t i; //indice per gli studenti
	size_t j; //indice per scorrere i caratteri del nome e del cognome degli studenti

	for(i = 0; i < STUDENTI; i++){
		
		printf("STUDENTE %d:\n", i+1);
		
		//INSERIMENTO DEL NOME DELLO STUDENTE
		do{															//controllo sull'inserimento del nome dell'utente
			printf("%s","Inserire NOME dello studente -> ");
			scanf("%15s", studente[i].nome);
			for(j = 0; j < LENGHTNAME; j++){								//scorro i caratteri del vettore nome
				if( (isdigit(studente[i].nome[j])) != 0 ){			//se trovo un carattere che corrispodne ad una cifra...
					puts("\nIl nome non e' valido!\n");					
					valido = 0;										//...setto il flag di validità a 0...
					break;											//...interrompo il controllo e...
				}else{
					valido = 1;
				}
			}
		}while(valido != 1);										//faccio ripetere l'inserimento finché il flag di validità non è 1
		
		valido = 0;
		
		//INSERIMENTO DEL COGNOME DELLO STUDENTE
		do{															//controllo sull'inserimento del cognome dell'utente
			printf("%s","Inserire COGNOME dello studente -> ");
			scanf("%15s", studente[i].cognome);
			for(j = 0; j < LENGHTSURNAME; j++){								//scorro i caratteri del vettore cognome
				if( (isdigit(studente[i].cognome[j])) != 0 ){			//se trovo un carattere che corrispodne ad una cifra...
					puts("\nIl cognome non e' valido!\n");					
					valido = 0;										//...setto il flag di validità a 0...
					break;											//...interrompo il controllo e...
				}else{
					valido = 1;
				}
			}
		}while(valido != 1);									//faccio ripetere l'inserimento finché il flag di validità non è 1
		
		valido = 0;
		//INSERIMENTO DELLA CLASSE
		do{
			printf("%s", "Inserire la classe dello studente (A oppure B) -> ");
			scanf(" %c", &studente[i].classe);
			if((studente[i].classe != 'a') || (studente[i].classe != 'b')){			//se sono stati inseriti 'a' oppure 'b', invece di 'A' oppure 'B', li rendi maiuscoli
					studente[i].classe = toupper(studente[i].classe);
					valido = 1;
			}
			if((studente[i].classe != 'A') && (studente[i].classe != 'B')){		//se invece sono stati inseriti caratteri completamente diversi da 'A' e 'B' 
				puts("\nQuesta classe non esiste.\n");							//stampa l'errore
				valido = 0;														//imposta il flag a 0
			}else{
				valido = 1;
			}	
		}while(valido != 1);												//ripeti finché la classe inserita non è uguale ad 'A' oppure a 'B'
		
		//INSERIMENTO DEI VOTI DELLO STUDENTE
		for(j = 0; j < MATERIE; j++){
		
			do{
				printf("Inserire voto in %s (da 0 a 10) -> ", materie[j]);
				scanf("%u", &studente[i].voti[j]);
				if(studente[i].voti[j] < 0 || studente[i].voti[j] > 10){		//se il voto non rientra tra 0 - 10 lo faccio reinserire
					puts("\nVoto non valido.\n");
					valido = 0;
				}else{
					valido = 1;
				}
			}while(valido != 1);
			
			sommaVotiStudente += studente[i].voti[j];	
		}
		mediaVotiStudente[i] = (float) sommaVotiStudente / MATERIE;  		//caloclo la media dei voti dello studente e lo metto nella relativa posizione nel vettore
		printf("Media dei voti dello studente: %.3f", mediaVotiStudente[i]);
		puts("\n");
		sommaVotiStudente = 0; //riazzero la variabile per poterla usare nella prossima iterazione	
	}
	
	for(i = 0; i < STUDENTI; i++){
		if(studente[i].classe == 'A'){
			numClasseA++;
			sommaClasseA += mediaVotiStudente[i];
		}else{
			numClasseB++;
			sommaClasseB += mediaVotiStudente[i];
		}
	}
	if(numClasseA != 0){
		mediaClasseA = sommaClasseA / (float) numClasseA;
		
	}
	
	if(numClasseB != 0){
		mediaClasseB = sommaClasseB / (float) numClasseB;	
	}	
	
	
	puts("<----------------------------------->");
 	puts("CLASSE A:");
	printf("Numero di studenti -> %d\n", numClasseA);
	printf("Media dei voti della classe -> %.3f\n", mediaClasseA);
 	puts("<----------------------------------->");
 	puts("CLASSE B:");
	printf("Numero di studenti -> %d\n", numClasseB);
	printf("Media dei voti della classe -> %.3f\n", mediaClasseB);
	puts("<----------------------------------->");
	return 0;
}



