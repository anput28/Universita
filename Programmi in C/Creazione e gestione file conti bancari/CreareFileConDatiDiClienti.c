/* Programma che permette di inserire numero di conto, cognome, nome e saldo in un file "clienti.dat" in modo sequenziale*/

#include <stdio.h>

struct datiClienti {
	unsigned int numeroConto;
	char cognome[20];
	char nome[15];
	double saldo;
};

int main(){
	
	FILE *punt;
	
	if((punt = fopen("clienti.dat", "wb")) == NULL){
		puts("Errore. Impossibile aprire il file.");
	}else{
		struct datiClienti dati = {0, "", "", 0.0};
		
		printf("%s", "Inserire il numero di conto da 1 a 100 (0 per terminare):\n");
		scanf("%u", &dati.numeroConto);
		
		while(dati.numeroConto != 0){
			printf("%s", "\nInserire cognome, nome e saldo:\n");
			fscanf(stdin, "%19s%14s%lf", dati.cognome, dati.nome, &dati.saldo);
			fseek(punt, (dati.numeroConto -1) * sizeof(struct datiClienti), SEEK_SET);
			fwrite(&dati, sizeof(struct datiClienti), 1, punt);	
			printf("%s", "Inserire il numero di conto da 1 a 100 (0 per terminare):\n");
			scanf("%u", &dati.numeroConto);
		}
		
		fclose(punt);
	}
	
	return 0;
}

