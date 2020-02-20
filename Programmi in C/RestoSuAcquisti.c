#include <stdio.h>

int main(){
	float acquisto, resto = 0;
	int banconota20 = 0, banconota10 = 0, banconota5 = 0;
	int cent20 = 0, cent10 = 0, cent5 = 0;
	
	printf("Inserisci il valore dell'acquisto: ");
	scanf("%f", &acquisto);

	resto = 100 - acquisto;
	printf("Il resto e' pari a : %.2f\n", resto);
	printf("\nVerranno fornite :\n");
	
	if(resto >= 50){
		resto -= 50;
		printf("1 banconota da 50\n");
	}
	if(resto >= 20){
		while(resto >= 20) {
			resto -= 20;
			banconota20++;
		}
		printf("%d banconota/e da 20\n", banconota20);
	}
	if(resto >= 10){
		while(resto >= 10){
			resto -= 10;
			banconota10++;
		}
		printf("%d banconota/e da 10\n", banconota10);
	}
	if(resto >= 5){
		while(resto >= 5){
			resto -= 5;
			banconota5++;
		}
		printf("%d banconota/e da 5\n", banconota5);
	}
	
	if(resto >= 4){
		resto-=4;
		printf(", 2 monete da 2");
	}
	if(resto >= 3){
		resto -=3;
		printf("1 moneta da 2\n1 moneta da 1\n");
	}
	if(resto >= 2){
		resto-=2;
		printf("1 moneta da 2\n");
	}
	if(resto >= 1){
		resto -= 1;
		printf("1 moneta da 1\n");
	}
	
	/*-------------calcolo parte decimale-----------------*/	
	if(resto >= 0.50){
		resto -= 0.50;
		printf("1 moneta/e da 50 centesimi\n");
	}
	if(resto >= 0.20){
		while(resto >= 0.20) {
			resto -= 0.20;
			cent20++;
		}
		printf("%d moneta/e da 20 centesimi\n", cent20);
	}
	if(resto >= 0.10){
		while(resto >= 0.10){
			resto -= 0.10;
			cent10++;
		}
		printf("%d moneta/e da 10 centesimi\n", cent10);
	}
	if(resto >= 0.05){
		while(resto >= 0.05){
			resto -= 0.05;
			cent5++;
		}
		printf("%d moneta/e da 5 centesimi\n", cent5);
	}
		
	if(resto >= 0.04){
		resto -= 0.04;
		printf("2 monete da 2 centesimi\n");
	}
	if(resto >= 0.03){
		resto -= 0.03;
		printf("1 moneta da 2 centesimi\n1 moneta da 1 centesimo\n");
	}
	if(resto >= 0.02){
		resto -= 0.02;
		printf("1 moneta da 2 centesimi\n");
	}
	if(resto >= 0.01){
		resto -= 0.01;
		printf("1 moneta da 1 centesimo\n");
	}
return 0;
}

