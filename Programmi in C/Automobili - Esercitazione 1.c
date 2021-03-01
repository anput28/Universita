/* LABORATORIO DI INFORMATICA 2018/2019 - TRACK B
Docente: Cataldo Musto

ESERCITAZIONE 0 - Autovalutazione - 08/03/2019

Cognome: <Putignano>
Nome: <Angelo>
Matricola: <matricola>

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define CHAR_TARGA 7		 //numero dei caratteri della targa
#define CHAR_MARCA 17		 //numero di caratteri per la marca della macchina (la più lunga è FISKER COACHBUILD)	
#define CHAR_MODELLO 15		 //numero dei caratteri per il modello della macchina
#define NUM_MACCHINE 5		 //numero di macchine per cui inserire i dati
#define MIN_ANNO 1999	   	 //anno di immatricolazione minimo
#define MAX_ANNO 2019		 //anno di immatricolazione massimo
#define MIN_COSTO 100		 //costo minimo di un tagliando
#define MAX_COSTO 500		 //costo massimo di un tagliando
#define MIN_KILOMETRI 21000	 //minimo numero di chilometri in cui può essere effettuato un tagliando
#define MAX_KILOMETRI 250000	 //massimo numero di chilometri in cui può essere effettuato un tagliando
#define MIN_TAGLIANDI 1      //numero minimo di tagliandi
#define MAX_TAGLIANDI 10     //numero massimo di tagliandi
#define ROT_ETA 2005 		//indica l'anno di immatricolazione a partire dal quale la macchina non è considereta vecchia
#define ROT_KM 200000 		//indica i chilometri a partire dal quale la macchina è considerata da rottamare
#define ROT_COSTO 400		//indica il costo della manutenzione a partire dal quale la macchina è considerata da rottamare

typedef struct{		//struct che definisce il tipo di dato per inserire la data
	int giorno;
	int mese;
	int anno;
}data;

typedef struct{						//struct che definisce il tipo di dato per inserire le informazioni su un tagliando
	data dataTagliando;
	int kmTagliando;  				//numero di km in cui è stato effettuato il tagliando
	int costoManutenzione; 			//costo dell'intervento di manutenzione
}libretto;



typedef struct{							//struct che definisce il tipo di dato per inserire le informazioni di una macchina
	
	libretto tagliandi[MAX_TAGLIANDI];
	int annoImmatr; 					//anni di immatricolazione della macchina
	int daRottamare; 	//flag che indica se la macchina è da rottamare o meno
	char modello[CHAR_MODELLO];
	char marca[CHAR_MARCA];
	char targa[CHAR_TARGA];
}datiAuto;

int main(void) {
	srand(time(NULL));
	
	datiAuto macchina[NUM_MACCHINE];
	char matriculation[3] = {0};			//array di appoggio per l'inserimento dell'anno di immatricolazione
	int numTagliandi = 0;					//variabile che conta il numero di tagliandi effettuati su una macchina
	int annoTagliando = 0;					//variabile che serve a tenere traccia degli anni dei tagliandi generati
	int contKm ;							//contatore dei kilometri per tenerne traccia ad ogni tagliando
	int sommaCosto[NUM_MACCHINE] = {0};		//vettore che tiene traccia della spesa totale per i tagliandi di ogni macchina
	int maxCosto = 0;						//serve a tenere traccia della macchina che ha speso di più per i tagliandi
	float mediaCosto = 0;					//variabile che memorizza la media del costo dei tagliandi di una macchina
	int valido = 0;						    //flag che indica la validità dei dati inseriti 
	int indiceCostoMax = 0;					//indice che servirà per stampare i dati della macchina che ha speso di più per i tagliandi
	int j;									//indice secondario per i cicli annidati 
	int i; 									//indice per il ciclo che permette di inserire i valori delle macchine
	
	//---------------------------------------INIZIO INSERIMENTO DATI DA TASTIERA---------------------------------------//
	for(i = 0; i < NUM_MACCHINE; i++){
		printf("----------Macchina %d----------\n", i+1);
		
		do{
			printf("%s", "Inserire la targa della macchina -> ");
			gets(macchina[i].targa);
			if((strlen(macchina[i].targa)) != CHAR_TARGA){								//se la lunghezza della targa è diversa da 7 ripeto l'inserimento della targa
				puts("\nLa targa deve avere 7 caratteri.\n");
				valido = 0;
			}else{
				if(((isdigit(macchina[i].targa[0])) != 0) || ((isdigit(macchina[i].targa[1])) != 0) ){		//controllo sulle prime due lettere della targa
					puts("\nI primi due caratteri della targa devono essere 2 lettere.\n");
					valido = 0;
				}else
					if (((isdigit(macchina[i].targa[2])) == 0) || ((isdigit(macchina[i].targa[3])) == 0) || ((isdigit(macchina[i].targa[4])) == 0)){ //controllo sulle cifre 2, 3 e 4 della targa
						puts("\nDopo le due lettere devono essere inseriti 3 numeri.\n");
						valido = 0;
					}else
						if(((isdigit(macchina[i].targa[5])) != 0) || ((isdigit(macchina[i].targa[6])) != 0) ){	//controllo sulle ultime due lettere della targa
							puts("\nGli ultimi due caratteri della targa devono essere 2 lettere.\n");
							valido = 0;
						}else{
							valido = 1;
						}
			}	
		}while(valido != 1);	
		
		do{
			printf("%s", "Inserire la marca della macchina -> ");
			gets(macchina[i].marca);
			if((strlen(macchina[i].marca)) > CHAR_MARCA){								//se sono stati inseriti più di 17 caratteri per la marca la faccio reinserire
				puts("\nLa marca puo' contenere al massimo 17 caratteri.\n");
				valido = 0;
			}else{															//se il numero di caratteri è giusto
				for(j = 0; j < CHAR_MARCA; j++){								
					if((isdigit(macchina[i].marca[j])) != 0){ 		 		//controllo che non siano stati inseriti numeri, se si faccio reinserire la marca
						puts("\nLa marca non puo' contenere numeri.\n");
						valido = 0;
						break;
					}else{
						valido = 1;
					}
				}
			}	
		}while(valido != 1);
		
		do{
			printf("%s", "Inserire il modello della macchina -> ");
			gets(macchina[i].modello);
			if((strlen(macchina[i].modello)) > CHAR_MODELLO){				//se sono stati inseriti più di 15 caratteri faccio reinserire il modello
				puts("\nIl modello deve contenere al massimo 15 caratteri.");
				valido = 0;
			}else{
				valido = 1;
			}	
		}while(valido != 1);
		
		do{
			printf("%s", "Inserire anno di immatricolazione della macchina (da 1999 a 2019) -> ");
			gets(matriculation);								//inserisco l'anno di immatricolazione in un vettore di char per controllare l'inserimento di lettere
			for(j = 0; j <= 3; j++){							//itero l'array di caratteri						
				if((isdigit(matriculation[j])) == 0){			//se un elemento non corrisponde ad un numero
					matriculation[j] = 0;						//lo setto a 0 in modo da poter avere sempre un numero minimo di 4 cifre da confrontare con l'anno di immatricolazione minimo e massimo
				}
			}
			macchina[i].annoImmatr = atoi(matriculation);		//tramite atoi() trasformo il vettore di caratteri in un intero e lo inserisco nella giusta variabile
			if(	macchina[i].annoImmatr < MIN_ANNO || macchina[i].annoImmatr > MAX_ANNO){ 	//se l'anno inserito è < 1999 oppure > 2019 lo faccio reinserire
				puts("\nL'anno di immatricolazione deve essere compreso tra 1999 e 2019.\n");
				valido = 0;
			}else{
				valido = 1;
			}
		}while(valido != 1);
		
		//controllo se la macchina è da rottamare in base agli anni
		if(macchina[i].annoImmatr < ROT_ETA){
			macchina[i].daRottamare = 1;
		}
		
		//---------------------------------------INIZIO GENERAZIONE DEI DATI RELATIVI AI TAGLIANDI---------------------------------------//
		annoTagliando = macchina[i].annoImmatr;
		contKm = 0;
		do{	
			int mesi31[7] = {1, 3, 5, 7, 8, 10, 12};			//array contenete i mesi che hanno 31 giorni
			int meseIndice;										//variabile che sarà un indice casuale del vettore mesi31
				
			if( annoTagliando >= MAX_ANNO){				//se l'ultmo tagliando è stato effettuato in un anno >= 2019	
				break;									//termino forzatamente la generazione di tagliandi
			}else{
				//Generazione dell'ANNO
				macchina[i].tagliandi[numTagliandi].dataTagliando.anno = (annoTagliando + 1) + rand() % (MAX_ANNO - annoTagliando);	
				annoTagliando = macchina[i].tagliandi[numTagliandi].dataTagliando.anno;							//aggiorno annoTagliando all'ultimo anno generato
				
				//generazione il GIORNO del tagliando tra 1 e 31
				macchina[i].tagliandi[numTagliandi].dataTagliando.giorno = 1 + rand() % 31; 	
				
				//Gestione generazione del MESE
				if(macchina[i].tagliandi[numTagliandi].dataTagliando.giorno > 28){					//gestisco il caso in cui giorno è > 28
					if(macchina[i].tagliandi[numTagliandi].dataTagliando.giorno > 30){ 						//se il giorno è > 30
						meseIndice = rand() % 7;													//genero tra 0 e 7 perché meseIndice deve essere l'indice del vettore mesi31
						macchina[i].tagliandi[numTagliandi].dataTagliando.mese = mesi31[meseIndice];			//il mese viene generato tra i mesi indicati in mesi31	
					}else{																			//altrimenti
						macchina[i].tagliandi[numTagliandi].dataTagliando.mese = 1 + rand() % 12; 		//genero un qualsiasi mese tra 1 e 12
						while(macchina[i].tagliandi[numTagliandi].dataTagliando.mese == 2){						//se è stato generato il mese 2 (febbraio)
							macchina[i].tagliandi[numTagliandi].dataTagliando.mese = 1 + rand() % 12;	//lo rigenero finché non viene generato un mese diverso	
						}
					}				
				}else {
					macchina[i].tagliandi[numTagliandi].dataTagliando.mese = 1 + rand() % 12; //se giorno < 28 genero un qualsiasi mese tra 12 e 1	
				}
				
				//generazione del COSTO dell'intervento di manutenzione
				macchina[i].tagliandi[numTagliandi].costoManutenzione = MIN_COSTO + rand() % (MAX_COSTO - MIN_COSTO);		
				sommaCosto[i] += macchina[i].tagliandi[numTagliandi].costoManutenzione;  				//sommo di volta in volta il costo di ogni tagliando
				
				//controllo se la macchina è da rottamare in base al costo della manutenzione
				if(macchina[i].tagliandi[numTagliandi].costoManutenzione > ROT_COSTO){
					macchina[i].daRottamare  = 1;
				}
					
				//generazione dei KILOMETRI in cui è stato effettuato il tagliando, tramite contKm tengo traccia dei Km percorsi dalla macchina				
				macchina[i].tagliandi[numTagliandi].kmTagliando = (contKm + MIN_KILOMETRI) + rand() % ((MAX_KILOMETRI - contKm) - MIN_KILOMETRI);		
				contKm = macchina[i].tagliandi[numTagliandi].kmTagliando;
				
				//STAMPO I DATI GENERATI
				printf("Tagliando %d:\n", numTagliandi+1);
				printf("\tData del tagliando: %d/%d/%d\n", macchina[i].tagliandi[numTagliandi].dataTagliando.giorno, macchina[i].tagliandi[numTagliandi].dataTagliando.mese, macchina[i].tagliandi[numTagliandi].dataTagliando.anno);
				printf("\tCosto: %d\n",  macchina[i].tagliandi[numTagliandi].costoManutenzione);
				printf("\tKilomentri: %d\n\n",  macchina[i].tagliandi[numTagliandi].kmTagliando);
				
				numTagliandi++;						//il numero dei tagliandi viene incrementato
				
				valido = rand() % 3;				//a valido assegno un valore random tra 0, 1 e 2
			}
		}while(valido == 1 || valido == 0);					//finché valido è uguale a 1 o a 0 vengono generati altri tagliandi
		
		//controllo se la macchina è da rottamare in base ai chilometri
		if(contKm > ROT_KM){
			macchina[i].daRottamare = 1;
		}
		
		//calcolo del massimo tra i costi dei tagliandi delle varie macchine
		if(sommaCosto[i] > maxCosto){
			maxCosto = sommaCosto[i];
			indiceCostoMax = i;						// verrà usato per stamapre i dati relativi alla macchina che ha speso di più
		}	
		
		//gestione calcolo della MEDIA del costo dei tagliandi
		if(numTagliandi != 0){
			mediaCosto = (float) sommaCosto[i] / (float) numTagliandi;
			printf("Media del costo dei tagliandi -> %.2f\n", mediaCosto);	
		}else{
			puts("Non e' stato effettuato nessun tagliando sulla macchina.");
		}	
		
		numTagliandi = 0;			 
		puts(" ");
	}
	
  	//---------------------------------------FINE GENERAZIONE DEI DATI RELATIVI AI TAGLIANDI---------------------------------------//
  	
  	puts("-----DATI DELLA MACCHINA CHE HA SPESO DI PIU' PER I TAGLIANDI-----");
  	printf("Targa: %s\n", macchina[indiceCostoMax].targa);
  	printf("Marca: %s\n", macchina[indiceCostoMax].marca);
  	printf("Modello: %s\n", macchina[indiceCostoMax].modello);
  	printf("Anno di Immatricolazione: %d\n", macchina[indiceCostoMax].annoImmatr);
  	puts("Tagliandi:");
	for(i = 0; i < MAX_TAGLIANDI; i++){
  		//questo controllo serve a capire quando non ci sono più tagliandi per quella macchina
  		if(macchina[indiceCostoMax].tagliandi[i].dataTagliando.giorno < 1 || macchina[indiceCostoMax].tagliandi[i].dataTagliando.giorno > 31){ 
  			break;
		}
  		printf("%d)\tData del tagliando: %d/%d/%d\n", i+1, macchina[indiceCostoMax].tagliandi[i].dataTagliando.giorno, macchina[indiceCostoMax].tagliandi[i].dataTagliando.mese, macchina[indiceCostoMax].tagliandi[i].dataTagliando.anno);
  		printf("  \tCosto: %d\n", macchina[indiceCostoMax].tagliandi[i].costoManutenzione);
  		printf("  \tKilometri: %d\n", macchina[indiceCostoMax].tagliandi[i].kmTagliando);
	}
  	puts("------------------------------------------------------------------");
  	
  	puts("\n-----AUTO DA ROTTAMARE-----");
  	for(i = 0; i < NUM_MACCHINE; i++){
  		if(macchina[i].daRottamare == 1){
  			printf("Macchina %d:\n", i+1);
  			printf("\tTarga: %s\n", macchina[i].targa);
		  	printf("\tMarca: %s\n", macchina[i].marca);
		  	printf("\tModello: %s\n", macchina[i].modello);
		  	printf("\tAnno di Immatricolazione: %d\n", macchina[i].annoImmatr);
		}
		puts(" ");
	}
	puts("---------------------------");
  return 0;
}
