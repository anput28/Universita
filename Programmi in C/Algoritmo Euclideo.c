#include <stdio.h>

int main(){
	
	int a, b, bScorta = 0, quoziente = 0, resto = 0, resto2 = 0;
	
	printf("Inserisci due numeri in modo che a >= b > 0:\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

 	//Controlli per calcolare l'MCD senza problemi.
	if(a < 0){
		a = a * (-1);
		printf("\nTrasformo a in positivo.\n");
	}
	if(b < 0){
		b = b * (-1);
		("Trasformo b in positivo.\n");
	}
	if(a < b){
		a = a ^ b;
	    b = a ^ b;
	    a = a ^ b; 
	    printf("Inverto a con b.\n");
	}
	
	printf("\nQuindi calcoliamo l'MCD(%d, %d)", a, b);

	//Controlli condizioni per calcolare l'MCD.	
	if(a == b){
		printf(" = %d", a);
		return 0;
	}
	
	bScorta = b;
	quoziente = a / b;
	resto = a % b;
	printf("\n\nPASSI DELL'ALGORITMO EUCLIDEO\n");
	printf("%d = %d * %d + %d\n",a = b * quoziente + resto, b, quoziente, resto);
	
	if(resto == 0){
			printf("L'MCD(%d, %d) = %d",a , b, b);
			return 0;
	}else
		if(resto > 0){
			while(resto > 0){
				quoziente = b / resto;
				resto2 = b % resto;
				printf("%d = %d * %d + %d\n", b = resto * quoziente + resto2, resto, quoziente, resto2);
				if(resto2 > 0){
					b = resto;
					resto = resto2;	
				}else{
					printf("\nL'MCD(%d, %d) = %d",a, bScorta, resto);
					return 0;
				}
			}
		}
}

