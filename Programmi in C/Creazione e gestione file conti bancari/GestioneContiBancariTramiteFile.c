/*Programma che aggiorna i conti dei clienti di una banca e permette di : 
1. stampare l'eleneco dei conti in file .txt
2. aggiornare il saldo di un cliente inserendo una transazione
3. creare il conto di un nuovo cliente
4. eliminare il conto di un cliente*/
#include <stdio.h>

unsigned int inserireScelta(void);
void elencoFormattato(FILE *eptr);
void aggiornaConto(FILE *aptr);
void creaConto(FILE *cptr);
void eliminaConto(FILE *dptr);

struct datiClienti{
	unsigned int conto;
	char cognome[20];
	char nome[15];
	double saldo;
};

int main(){
	
	FILE *ptr;
	
	if((ptr = fopen("clienti.dat", "rb+")) == NULL){
		puts("ERRORE! Impossibile aprire il file.");
	}else{
		unsigned int s;
		while((s = inserireScelta()) != 5){
			switch(s){
				case 1:
					elencoFormattato(ptr);
					break;
				case 2:
					aggiornaConto(ptr);
					break;
				case 3:
					creaConto(ptr);
					break;
				case 4:
					eliminaConto(ptr);
					break;
				default:
					break;
			}			
		}
		printf("%s", "\nFine dell'esecuzione.");
		fclose(ptr);	
	}

	return 0;
}

unsigned int inserireScelta(){
	printf("%s", "Scegli l'azione da compiere:\n"
			"1) Crea un elenco formattato di conti dei clienti.\n"
			"2) Aggiorna un conto.\n"
			"3) Crea un nuovo conto.\n"
			"4) Elimina un conto.\n"
			"5) Esci.\n");
	int scelta; 
	printf("%s", "-> ");
	scanf("%d", &scelta);
	
	return scelta;
}

void elencoFormattato (FILE *eptr){
	FILE *txt;
	if((txt = fopen("conti formattati.txt", "w")) == NULL){
		puts("\nERRORE. Impossibile aprire il file.\n");
	}else{
		rewind(eptr);
		fprintf(txt, "%-7s%-20s%-15s%s\n", "Conto", "Cognome", "Nome", "Saldo");
		
		while(!feof(eptr)){
			struct datiClienti dati = {0, "", "", 0.0};
			int datiLetti = fread(&dati, sizeof(struct datiClienti), 1, eptr);
			if(datiLetti != 0 && dati.conto != 0){
				fprintf(txt, "%-7u%-20s%-15s%.2f\n", dati.conto, dati.cognome, dati.nome, dati.saldo);
			}
		}
		puts("\nElenco creato nel file 'conti formattati.txt'.\n");
		fclose(txt);
	}
}

void aggiornaConto (FILE *aptr){
	
	unsigned int numConto;
	printf("%s","\nInserire il numero di conto del cliente da aggiornare (da 1 a 100)\n-> ");
	scanf("%u", &numConto);
		
	fseek(aptr, (numConto -1) * sizeof(struct datiClienti), SEEK_SET);
	struct datiClienti dati = {0, "", "", 0.0};
	fread(&dati, sizeof(struct datiClienti), 1, aptr);
	if(dati.conto == 0){
		puts("\nERRORE. Il conto non esiste.\n");
	}else{
		puts("\nStato attuale del conto:");
		printf("%-7s%-20s%-15s%s\n", "Conto", "Cognome", "Nome", "Saldo");
		printf("%-7u%-20s%-15s%.2f\n\n", dati.conto, dati.cognome, dati.nome, dati.saldo);
		
		printf("%s","\nInserisci la somma da addebitare (+) o il pagamento (-): ");
		double somma;
		scanf("%lf", &somma);
		dati.saldo += somma;
		
		puts("\nStato del conto aggiornato:");
		printf("%-7s%-20s%-15s%s\n", "Conto", "Cognome", "Nome", "Saldo");
		printf("%-7u%-20s%-15s%.2f\n\n", dati.conto, dati.cognome, dati.nome, dati.saldo);
		fseek(aptr, (numConto -1) * sizeof(struct datiClienti), SEEK_SET);
		fwrite(&dati, sizeof(struct datiClienti), 1,  aptr);
	}	
}

void creaConto (FILE *cptr){
	printf("%s", "\nInserire il numero di conto del cliente da aggiungere (da 1 a 100)\n-> ");
	unsigned int nuovoConto;
	scanf("%u", &nuovoConto);
		
	fseek(cptr, (nuovoConto - 1) * sizeof(struct datiClienti), SEEK_SET);
	struct datiClienti dati = {0, "", "", 0.0};
	fread(&dati, sizeof(struct datiClienti), 1, cptr);
	if(dati.conto != 0){
	puts("\nIl e' gia' presente nel file.\n");
	}else{
		dati.conto = nuovoConto;
		printf("%s", "\nInserire cognome, nome e saldo del cliente\n-> ");
		scanf("%19s%14s%lf", dati.cognome, dati.nome, &dati.saldo);
			
		puts("\nI seguenti dati sono stati inseriti nel file:");
		printf("%-7s%-20s%-15s%s\n", "Conto", "Cognome", "Nome", "Saldo");
		printf("%-7u%-20s%-15s%.2f\n\n", dati.conto, dati.cognome, dati.nome, dati.saldo);
		fseek(cptr, (nuovoConto - 1) * sizeof(struct datiClienti), SEEK_SET);	
		fwrite(&dati, sizeof(struct datiClienti), 1, cptr);
	}
}

void eliminaConto (FILE *dptr){
	printf("%s", "\nInserire il numero di conto del cliente da eliminare (da 1 a 100)\n-> ");
	unsigned int deleteConto;
	scanf("%u", &deleteConto);
		
	fseek(dptr, (deleteConto - 1) * sizeof(struct datiClienti), SEEK_SET);
	struct datiClienti dati;
	fread(&dati, sizeof(struct datiClienti), 1, dptr);
	if(dati.conto != deleteConto){
		puts("\nIl conto non esiste.\n");
	}else{
		printf("%s", "Sei sicuro di voler eliminare questo conto? (si/no)\n-> ");
		char risposta[3];
		scanf(" %2s", risposta);
		if(risposta[0] == 'n'){
			puts("\nPerfetto, non elimino il conto.\n");
		}else{
			struct datiClienti datiVuoti = {0, "", "", 0.0};
			fseek(dptr, (deleteConto - 1) * sizeof(struct datiClienti), SEEK_SET);
			fwrite(&datiVuoti, sizeof(struct datiClienti), 1, dptr);
			puts("\nConto eliminato correttamente.\n");	
		}
	}
}

