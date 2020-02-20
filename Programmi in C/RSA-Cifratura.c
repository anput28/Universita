#include <stdio.h>

void RSA (int *vet);

int main(){
	
	int num, resto;
	int vet[3];
	
	printf("%s","Inserire un numero di 4 cifre: ");
	scanf("%d", &num);
	
	for(size_t i = 1; i <= 4; i++){
		resto = num % 10;
		vet[4-i] = resto;
		num = num / 10;
	}
	
	RSA(vet);
	
	return 0;
}

void RSA (int *vet){
	
	for(size_t i = 0; i <= 3; i++){
		vet[i] = (vet[i]+7) % 10;
	}
	
	printf("%d%d%d%d",vet[2], vet[3], vet[0], vet[1]);
}


