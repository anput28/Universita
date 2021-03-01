#include <stdio.h>

typedef struct {
	char mese[10];
	int anno;
}data;

typedef struct{
	char nomeFilm[30];
	char genereFilm[15];
	data dataUscita;
	int durata;
}film;

int main (){
	
	film archivio[5];
	int i;
	
	for(i = 0; i < 5; i++){
		printf("Dati Film %d\n", i+1);
		printf("%s", "Inserire il nome del film -> ");
		scanf("%s", archivio[i].nomeFilm);
		printf("%s", "Inserire il genere del film -> ");
		scanf("%s", archivio[i].genereFilm);
		printf("%s", "Inserire la data di uscita del film -> ");
		scanf("%s", archivio[i].dataUscita.mese);
		scanf("%d", &archivio[i].dataUscita.anno);
		printf("%s", "Inserire la durata del film -> ");
		scanf("%d", &archivio[i].durata);
		puts(" ");
	}
	
	for(i = 0; i < 5; i++){
		printf("Film %d\n", i+19);
		printf("Nome: %s\n", archivio[i].nomeFilm);
		printf("Genere: %s\n", archivio[i].genereFilm);
		printf("Data di uscita: %s %d\n", archivio[i].dataUscita.mese, archivio[i].dataUscita.anno);
		printf("Durata: %d\n\n", archivio[i].durata);
	}
	

	return 0;
}

