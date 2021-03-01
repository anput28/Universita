/* LABORATORIO DI INFORMATICA 2018/2019 - TRACK B
Docente: Cataldo Musto

ESERCITAZIONE 0 - Autovalutazione - 27/02/2019

Cognome: Putignano
Nome: Angelo
Matricola:  699320

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINETA 20
#define MAXETA 110
#define MINALTEZZA 120
#define MAXALTEZZA 210
#define MINPESO 40
#define MAXPESO 230
#define SIZE 10

int main(void) {
  srand(time(NULL));
  
  unsigned int eta;
  unsigned int peso;
  unsigned int altezzaCm;
  float altezzaConvertita;
  float BMI;
  
  float totaleBMIOver = 0, mediaBMIOver = 0;
  float totaleBMIUnder = 0, mediaBMIUnder = 0;
  float massimaAltezzaOver = 0.0, massimaAltezzaUnder = 0.0;
  unsigned int massimoPesoOver = 0, massimoPesoUnder = 0.0;
  
  int i;
  for(i = 0; i < SIZE; i++){														//ciclo che genera eta, altezza e peso delle 10 persone
  
   //------------------------------------------------------INIZIO GENERAZIONE DATI DELLE PERSONE----------------------------------------------------->
   
    eta = rand() % (MAXETA - MINETA + 1) + MINETA;
    
    if(eta <= 55){																	/*genero altezza e peso delle persone di eta inferiore a 55 anni.
																					  In base all'altezza cambio il range entro cui generare il peso.*/ 
    	altezzaCm = rand() % (MAXALTEZZA - MINALTEZZA + 1) + MINALTEZZA;			
    	
    	if(altezzaCm <= 137){
    		peso = rand() % (75 - MINPESO + 1 ) + MINPESO;							
		}
		
		if(altezzaCm > 137 && altezzaCm <= 155){
    		peso = rand() % (100 - MINPESO + 1 ) + MINPESO;
		}
		
		if(altezzaCm > 155 && altezzaCm <= 176){
			peso = rand() % (180 - 46 + 1 ) + 46;
		}
		
		if(altezzaCm > 176){
			peso = rand() % (MAXPESO - 55 + 1) + 55;
		}
		
	}
	
	if(eta > 55 && eta <= 77){														/*genero altezza e peso delle persone di eta compresa tra 56 e 77 anni.
																					  In base all'altezza cambio il range entro cui generare il peso. */
		altezzaCm = rand() % (190 - MINALTEZZA + 1) + MINALTEZZA;
		
		if(altezzaCm <= 137){
    		peso = rand() % (70 - MINPESO + 1 ) + MINPESO;
		}
		
		if(altezzaCm > 137 && altezzaCm <= 155){
    		peso = rand() % (97 - MINPESO + 1 ) + MINPESO;
		}
		
		if(altezzaCm > 155 && altezzaCm <= 176){
			peso = rand() % (145 - 46 + 1 ) + 46;
		}
		
		if(altezzaCm > 176){
			peso = rand() % (160 - 55 + 1) + 55;
		}
	}
	
	if(eta > 77 && eta < 90){														/*genero altezza e peso delle persone di eta compresa tra 78 e 89 anni.
																					 In base all'altezza cambio il range entro cui generare il peso. */		
		altezzaCm = rand() % (180 - MINALTEZZA + 1) + MINALTEZZA;
			
		if(altezzaCm > 137 && altezzaCm <= 160){
    		peso = rand() % (65 - MINPESO + 1 ) + MINPESO;
		}
		
		if(altezzaCm > 160){
			peso = rand() % (95 - 50 + 1 ) + 50;
		}
		
	}
	
	if(eta >= 90){																	/*genero altezza e peso delle persone di eta superiore ai 90 anni.
																					  In base all'altezza cambio il range entro cui generare il peso. */
		altezzaCm = rand() % (175 - MINALTEZZA + 1) + MINALTEZZA;
		
		if(altezzaCm <= 155){
    		peso = rand() % (60 - MINPESO + 1 ) + MINPESO;
		}else{
    		peso = rand() % (80 - MINPESO + 1 ) + MINPESO;
		}
			
	}
	
	//------------------------------------------------------FINE GENERAZIONE DATI DELLE PERSONE----------------------------------------------------->
   
    altezzaConvertita = altezzaCm / 100.0;									//conversione dell'altezza da cm a m 
    
    BMI = peso / (altezzaConvertita * altezzaConvertita);					//calcolo del Body Mass Index (BMI)
    
    if(eta >= 40){															//controllo del massimo di altezza e peso e della media tra i BMI OVER 40
    
    	if(altezzaConvertita > massimaAltezzaOver ){
    		massimaAltezzaOver = altezzaConvertita;
		}
		
		if(peso > massimoPesoOver ){
    		massimoPesoOver = peso;
		}
		
		totaleBMIOver += BMI;													//sommo il valore del BMI di ogni persona OVER 40		
		mediaBMIOver = totaleBMIOver / SIZE;									//e calcolo la media di volta in volta
			
	}else{																		//controllo del massimo di altezza e peso e della media tra i BMI UNDER 40
	
		if(altezzaConvertita > massimaAltezzaUnder ){
    		massimaAltezzaUnder = altezzaConvertita;
		}
		
		if(peso > massimoPesoUnder ){
    		massimoPesoUnder = peso;
		}	
		
		totaleBMIUnder += BMI;													//sommo il valore del BMI di ogni persona UNDER 40
		mediaBMIUnder = totaleBMIUnder / SIZE;									//e calcolo la media di volta in volta
	}
	
    printf("eta : %u, altezza : %.2f, peso : %u\n", eta, altezzaConvertita, peso );
  }
  
  //stampa di altezza massima, peso massimo e media dei BMI degli OVER 40
  puts("\nOVER 40:");
  printf("Massima altezza -> %.2f\nMassimo peso -> %u\n", massimaAltezzaOver, massimoPesoOver);
  if(mediaBMIOver > 25){
  	
  	puts("Il campione e' mediamente sovrappeso.");
  	
  }else{
  	
  	puts("Il campione e' mediamente sottopeso.");
  	
  }
  
   //stampa di altezza massima, peso massimo e media dei BMI degli OVER 40
  puts("\nUNDER 40:");
  printf("Massima altezza -> %.2f\nMassimo peso -> %u\n", massimaAltezzaUnder, massimoPesoUnder);
  if(mediaBMIUnder > 25){
  	
  	puts("Il campione e' mediamente sovrappeso.");
  	
  }else{
  	
  	puts("Il campione e' mediamente sottopeso.");
  	
  }
  
  return 0;
}

