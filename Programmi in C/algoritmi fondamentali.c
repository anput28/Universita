//														ALGORITMI DI RICERCA

/*RICERCA LINEARE ESAUSTIVA
Algoritmo di ricerca meno efficiente di tutti perch� anche se trova l'elemento cercato 
continua a scorrere il vettore finch� non arriva all'ultimo elemento.
Complessit�
	caso migliore : O(n)
	caso medio : O(n)
	caso peggiore : O(n)
*/
int ricerca(int array[], int n, int x){
	int posizione = -1;
	int i;
	for(i = 0; i < n; i++){
		if(array[i] == x){
			posizione = i;
		}
	}
	
	return posizione; //se l'elemento non viene trovato restituisce -1 che non � sicuramente una posizione
}


/*RICERCA LINEARE CON SENTINELLA
Algoritmo di ricerca un p� pi� efficiente della ricerca lineare esaustiva, perch� appena trova
l'elemento cercato smette di analizzare il vettore.
Complessit�
	caso migliore : O(1)
	caso medio : O(n/2)
	caso peggiore : O(n)
*/
int ricercaBinaria(int array[], int n, int x){
	int posizione = -1;
	int i;
	while((i < n) && (posizione < 0)){
		if(array[i] == x){
			posizione = i;
		}
		i++;
	}
	return posizione; //se l'elemento non viene trovato restituisce -1 che non � sicuramente una posizione
}

/*RICERCA BINARIA (O DICOTOMICA)
Algoritmo di ricerca pi� efficiente di tutti, tuttavia ha un vincolo : richiede che il vettore da 
analizzare sia ordinato, quindi richiede un algoritmo di ordinamento prima della sua esecuzione.
L'idea alla base della ricerca binaria � quella di analizzare l'elemento al centro del vettore rispetto 
all'elemento cercato, il vettore � come se fosse diviso a met� quindi si analizza una met� (contenente valori pi� grandi del mediano) o
l'altra (contente i valori pi� piccoli del mediano) in base al risultato del confronto tra il mediano e il valore cercato. Questo metodo 
viene ripetuto sulla parte di vettore che si sta continuando ad analizzare finch� l'elemento non corrisponde proprio al centro del vettore
oppure finch� non ci sono pi� elementi da controllare.
Questa ricerca viene utilizzata per esempio per consultare dizionari, elenchi telefonici ecc.

Complessit�:
	caso migliore : O(1)
	caso peggiore : O(log2 n)
*/

int ricercaBinaria(int array[], int n, int x){
	int posizione = -1;
	int primo = 0;
	int ultimo = n-1;
	
	int i = 0;
	
	while((primo <= ultimo) && (posizione = -1)){
		i = (primo + ultimo)/2;
		if(array[i] == x){
			posizione = i;
		}else if(x > array[i]){
			primo = i + 1;
		}else {
			ultimo = i - 1;
		}
	}
	
	return posizione;
}


//														ALGORITMI DI ORDINAMENTO DI BASE
/*Non esiste un algoritmo di ordinamento migliore rispetto agli altri perch� l'efficienza di un algoritmo di ordinamento dipende:
-dal grado di ordinamento dei dati;
-dalla quantit� di dati da ordinare;
Ci sono due tipi di algoritmi di ordinamento:
-Algoritmi interni : che tramite una serie di confronti e scambi ordinano direttamente l'array originale;
-Algoritmi esterni : che per ordinare l'array usano un altro array di appoggio dove copiare man mano gli elementi in ordine, questi algoritmi
					 utilizzano il doppio della memoria.
*/

/*ORDINAMENTO PER SELEZIONE (SELECTION SORT)
Si basa sul concetto di minimi successivi, cio� l'algoritmi in un'array di n elementi cerca il pi� piccolo analizzando sequenzialemente tutti gli 
elementi, quando trova il pi� piccolo lo mette in prima posizione scambiandolo con l'elemento che c'era, dopodich� trova il minimo nei restanti n-1 
elementi e lo mette in seconda posizione. Continua in questo modo fino al penultimo elemento (l'ultimo sar� automaticamente ordinato).
Questo algoritmo non tiene conto del fatto che il vettore sia ordinato o meno, in qualsiasi caso effettuer� gli tutti i confronti e gli scambi previsti.

Complessit�:
	caso migliore : (n-1)*n = O(n^2)
	caso medio : (n-1)*n = O(n^2)
	caso peggiore : (n-1)*n = O(n^2)
*/

void selectionSort (int array[] int n){
	int minimo = 0;
	int posizioneMinimo = 0;
	
	int j;
	int i;
	for(i = 0; i < n-1; i++){
		minimo = array[i];
		posizioneMinimo = i;
		for(j = i+1; j < n; j++){
			if(array[j] < minimo){
				minimo = array[j];
				posizioneMinimo = j;
			}
		}
		array[posizioneMinimo] = array[i];
		array[i] = min;
	}
}

/*ORDINAMENTO A BOLLE (BUBBLE SORT)
L'algoritmo al fine di ordinare l'array confronta man mano due elementi adiacenti del vettore e se questi non sono ordinati li scambia. 
Continua ad eseguire questo processo finch� il vettore non � completamente ordinato. L'algoritmo � suddiviso in passi, ad ogni passo
viene portato nella corretta posizione un solo elemento, tuttavia durante un passo possono avvenire diversi scambi al fine di ridurre il pi�
possibile il numero di passi da eseguire in totale. Inoltre poich� ad un passo viene ordinato un elemento, al passo successivo sar� analizzata
solo la parte non ordinata del vettore.
Il vantaggio del bubble sort � che la sua durata dipende dal numero di scambi che vengono fatti ad ogni passo, quindi se ad un passo non viene 
effettuato nessuno scambio vuol dire che l'array � tutto ordinato e che l'algoritmo pu� terminare. 

Complessit�:
	caso migliore: O(n)
	caso medio: circa O(n^2)
	caso peggiore: O(n^2)

*/
void bubbleSort (int array[], int n){
	int scambio = 0;
	int posizione = 0;
	int i, temp;
	
	while((posizione < n) && (!scambio)){
		scambio = 1;
		posizione++;
		for(i = n-1; i >= posizione; i--){
			if(array[i] < array[i-1]){
				temp = array[i];
				array[i] = array[i-1];
				array[i-1] = temp;
				scambio = 0;
			}
		}
	}
}

/*ORDINAMENTO PER INSERZIONE (INSERTION SORT)
L'algoritmo considera il vettore come se fosse diviso in due parti : una parte ordinata di n elementi (inizialmente costituita solo dal primo elemento) e 
una parte non ordinata formata dai restanti elementi dell'array, all' n-esima iterazione la parte ordinata del vettore sar� formata da n elementi.
L'algoritmo analizza sequenzialmente tutti gli elementi della parte non ordinata del vettore (partendo dal secondo). Per ogni elemento, finch� questo 
non vine posizionato nella giusta posizione, controlla se � minore dell'elemento precedente, se cos� li scambia, e poi continua a confrontarlo con gli altri 
elementi della parte ordinata del vettore (se viene raggiunta la prima posizione, l'elemento viene posizionato l�), altrimenti l'elemento in questione � 
ordinato quindi passa ad analizzare il prossimo elemento non ordinato. 
Ad ogni passo dell'algoritmo cresce la parte ordinata e decresce quella non ordinata.
E' pi� efficace utilizzarlo quando si sa che il vettore � parzialmente ordinato.
Questo algoritmo � tipico per esempio per ordinare un mazzo di carte.

complessit�:
	caso migliore: O(n)
	caso medio: circa O(n^2)
	caso peggiore: O(n^2)	
*/
void insertionSort(int array[], int n){
	int i, j;
	int daOrdinare;
	
	for(i = 1; i < n; i++){
		daOrdinare = array[i];
		j = i-1;
		while((j >= 0) && (array[j] > daOrdinare)){
			array[j+1] = array[j];
			j--;
		}
		array[j] = daOrdinare;
	}
}


//														ALGORITMI DI ORDINAMENTO AVANZATI
/*Gli algoritmi di ordinamento di base hanno una complessit� troppo elevata, mediamente O(n^2), quindi � necessario cercare algoritmi di ordinamente con
una complessit� inferiore, che si avvicini alla complessit� lineare cio� O(n)
*/

/*SHELL SORT
L'algoritmo � un estensione dell'insertion sort e si basa sul confronto di tutti gli elementi che per� non sono adiacenti ma che si trovano ad una certa distanza.
Quindi data una certa distanza d nel primo passo ogni elemento viene confrontato con un altro distante d posizioni, se il primo � maggiore i due valori vengono scambiati.
Al secondo passo la distanza viene decrementata e vengono rieseguiti i confronti. Al prossimo passo la distanza viene ridotta ancora di pi� fino 
ad arrivare una distanza di 1, che significa controllare gli elementi adiacenti (quindi all'ultimo passo viene eseguito un insertion sort).
In qeusto modo gli elementi vengono spostati almeno nella zona in cui dovrebbe stare con meno confronti rispetto agli algoritmi di base.

Complessit�:
	caso migliore: O(n log n)
	caso medio: O(n log^2 n)
	caso peggiore: O(n log^2 n)
*/

void shellSort (int array[], int n){
	int gap, temp;
	int arrayGap[] = {9,5,3,1,2,1};
	int i, j, k;
	
	for(i = 0; i < sizeof(arrayGap); i++){
		gap = arrayGap[i];
		for(j = gap; j < n; j++){
			temp = array[j];
			for(k = j-gap; (temp < array[k]) && (k >= 0); k = k - gap){
				array[k+gap] = array[k];
				array[k] = temp;
			}
		}
	}
}

/*QUICK SORT
L'algoritmo prevede la scelta di un valore all'interno del vettore (chiamato pivot). Il vettore sulla base del pivot scelto viene diviso in due partizoni
una contenente gli elementi pi� piccoli del pivot e l'altra contente gli elementi pi� grandi. Dopodich� in ogniuna delle partizioni viene scelto
un altro pivot e si ripete il processo di mettere da una parte gli elementi pi� piccoli del pivot e dall'altra gli elementi pi� grandi. Questo processo viene 
ripetuto finch� il vettore non � completamente ordinato.
L'efficienza dell'algoritmo dipende dalla scelta del pivot, la scelta ottimale sarebbe quella di un pivot che sia il valore mediano tra quelli del vettore,
in modo da avere sempre partizioni ben definite e di pari dimensioni. Il caso peggiore invece sarebbe quello di scegliere un pivot che sia 
il secondo elemento pi� grande o pi� piccolo tra quelli del vettore.
Quindi in teoria si dovrebbe calcolare il valore mediano di un vettore e sceglierlo come pivot, ma alcune volte questo processo pu� richiedere del tempo
che andrebbe ad annullare l'effettiva efficienza dell'algoritmo.

Complessit�:
	caso migliore: O(n log n)
	caso medio:  O(n log n)
	caso peggiore:O(n^2)
*/

void quickSort (int array[], int limiteSinistro, int limiteDestro){
	int i;
	if(limiteDestro <= limiteSinistro){
		return; //caso base della ricorsivit�, quando il limite destro e sinistro coincidono
	}else{
		i = partizione(array, limiteSinistro, limiteDestro);
		quickSort(array, limiteSinistro, i-1);
		quickSort(array, i+1, limiteDestro);
	}
}

int partizione (int vettore[], int limiSin, int limDes){
	int i = limiSin-1;
	int j = limiDes + 1;
	int temp;
	int indicePivot = (limiSin+limiDes)/2;
	int pivot = vettore[indicePivot];
	
	while(i < j){
		while(vettore[--j] > pivot);
		while(vettore[++i] < pivot);
		if(i < j){
			temp = vettore[i];
			vettore[i] = vettore[j];
			vettore[j] = temp;
		}
	}
	
	return j;
}
	
/*MERGE SORT
L'algoritmo si basa sulla tecnica del Divide et Impera. Il merge sort � un algoritmo che dato un array lo divide ricorsivamente a met� (se gli elementi
sono dispari una parte avr� un elemento in pi�) fino ad considerare i singoli elementi del vettore. A questo punto gli elementi a coppie viene fusi e ordinati,
le coppie vengono poi fuse e ordinate tra di loro fino ad ottenere l'array completamente ordinato.
In questo modo l'algoritmo � efficiente sempre allo stesso modo, sia se il vettore � completamente disordinato o parzialmente ordinato.

complessit�:
	caso migliore: O(n log n)
	caso medio: O(n log n)
	caso peggiore: O(n log n)
*/

void mergeSort(int array[], int limiteSinistro, int limiteDestro){
	if(limiteDestro <= limiteSinistro){
		return; //passo base della ricorsione
	}else{
		int centro = (limiteSinitro + limiteDestro)/2;
		mergeSort(array, limiteSinistro, centro);
		mergeSort(array, centro+1, limiteDestro);
		
		merge(array, limiteSinistro, centro, limiteDestro);
	}
	
}	

void merge(int a[], int s, int c, int d){
	int i, j, k;
	int *ausiliario = (int*) malloc((r-s+1)*sizeof(int));
	
	for(i = c+1; i > s; i--){
		ausiliario[i-1] = a[i-1];
		for(j = c; j < d; j++){
			aux[d+c-j] = a[j+1];
			for(k = s; k <= d; k++){
				if(aux[j] < aux[i]){
					a[k] = aux[j--];
				}else{
					a[k] = aux[i++];
				}
			}
		}
	}
}
