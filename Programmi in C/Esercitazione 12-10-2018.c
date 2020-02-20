#include <stdio.h>

int main () {
	
	float kmMensili, costoCarburante, kmPercorsi;
	float spesaMensile = 0, divisioneSpesaMensile = 0;
	float costoMedioGiornaliero = 0, divisioneCostoMedio = 0;
	int numero = 1;
	
	while(numero == 1){
		printf("Inserire i Km percorsi mensilmente: ");
		scanf("%f", &kmMensili);
		if(kmMensili < 0){
			printf("Valore non valido!\n");
		} else {
			numero = 0;
		}
	}
	
	numero = 1;	
	while(numero == 1){
		printf("Inserire il costo/l di carburante: ");
		scanf("%f", &costoCarburante);
		if(costoCarburante < 0){
			printf("Valore non valido!\n");
		} else {
			numero = 0;
		}
	}
		
	numero = 1;
	while(numero == 1){
		printf("Inserire i Km percorsi con un litro: ");
		scanf("%f", &kmPercorsi);
		if(kmPercorsi < 0){
			printf("Valore non valido!\n");
		} else {
			numero = 0;
		}
	}
	
	divisioneSpesaMensile = kmMensili / kmPercorsi;
	spesaMensile = divisioneSpesaMensile * costoCarburante;
	printf("\nLa spesa mensile dell'utente e': %.2f\n", spesaMensile);
	
	divisioneCostoMedio = kmMensili / 30;
	costoMedioGiornaliero = divisioneCostoMedio * costoCarburante;
	printf("Il costo medio giornaliero dell'utente e': %.2f\n", costoMedioGiornaliero);
	
	costoCarburante += 0.20;
	spesaMensile = divisioneSpesaMensile * costoCarburante;
	printf("Se il costo del petrolio aumenta di 0.2 euro/litro, la spesa mensile incrementata e': %.2f", spesaMensile);
	
	return 0;
}
