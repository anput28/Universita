/* Se è presente WIN32 significa che siamo su una macchina windows quindi viene inclusa winsock.h
 * altrimenti siamo una macchina Unix, quindi vengono importate le librerie necessarie per utilizzare i socket.
 * La libreria winsock.h e le librerie usate su Unix utilizzano le stesse funzioni (o meglio, funzioni con gli stessi nomi).
 * L'unica differenza sta nella funzione che chiude un socket che in windows si chiama closesocket mentre in Unix si chiama close,
 * quindi nell'else viene definita una costante in modo da rendere uguali i due nomi.
 */
#ifdef WIN32
	#include <winsock.h>
#else
	#include <sys/socket.h>
	#include <unistd.h>
	#include <arpa/inet.h>
	#define closesocket close
#endif

#include <stdio.h>

#define QUEUE_LEN 6 //grandezza della coda di connessioni entranti
#define PROTO_PORT 27015 //porta TCP libera
#define NO_ERROR 0


//questa funzione termina l'esecuzione di Ws2_32.dll, cioè di WinSock, perciò è necessario eseguire questa funzione solo in Windows.
void clearwinsock(){
	#ifdef WIN32
		WSACleanup();
	#endif
}

int main(){

	int port = PROTO_PORT;
	if(port < 0){
		puts("Errore! Il numero di porta deve essere > 0");
	}

	//---------------------------------------------INIZIO INIZIALIZZAZIONE WINSOCK------------------------------------------------------
	//In Windows è necessario inizializzare WinSock mentre in Unix non c'è bisogno di alcuna inizializzazione
	#ifdef WIN32
		//struttura che contiene le informazioni sull'implementazione delle socket in windows
		WSADATA wsaData;

		//WSAStartup permette di indicare la versione di socket che si vuole utilizzare e quindi salva il valore indicato in wsaData
		//MAKEWORD è una macro formata da due elementi di tipo BYTE
		int result = WSAStartup(MAKEWORD(2,2), &wsaData);
		if(result != NO_ERROR){
			puts("Errore provocato da WSASturtup().\nNon e' possibile trovare una DLL WinSock utilizzabile.\n");
			return -1;
		}
	#endif
	//------------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------CREAZIONE SOCKET----------------------------------------------------------------------------
	/*
	  PF_INET = famiglia di protoccoli : internet (oggi è l'unica usata)
	  SOCK_STREAM = tipo di socket affidabile (è quello su cui si basa il protocollo TCP)
	  IPPROTO_TCP = protoccolo da usare nella socket, in questo caso TCP
	  La funzione socket() restituisce un valore > 0 che è il descrittore della socket.
	 */
	int server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(server_socket < 0){
		puts("Errore nella creazione del socket.");
		clearwinsock();
		return -1;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------ASSEGNAZIONE INDIRIZZO ALLA SOCKET-----------------------------------------------------------
	struct sockaddr_in sv_add; //struttura per l'indirizzo del server
	memset(&sv_add, 0, sizeof(sv_add)); //inizializza tutti i campi della struttura a 0, mi serve per riempire di 0 il campo 'sin_zero[8]'

	//imposto l'indirizzo del server
	sv_add.sin_family = AF_INET; //famiglia di inidirizzi : internet (l'unica usata al giorno d'oggi)
	sv_add.sin_port = htons(port); //converto il numero di porta in base all'architettura della macchina (BIG ENDIAN - LITTLE ENDIAN)
	sv_add.sin_addr.s_addr = inet_addr("127.0.0.1");

	//associo alla socket l'indirizzo del server che ho appena impostato
	if(bind(server_socket, (struct sockaddr*) &sv_add, sizeof(sv_add)) < 0){
		puts("Errore nell'assiociazione dell'indirizzo del server con la socket");
		closesocket(server_socket);
		clearwinsock();
		return -1;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------


	//---------------------------------------SETTAGGIO DELLA SOCKET ALL'ASCOLTO-----------------------------------------------------------
	if(listen(server_socket, QUEUE_LEN) < 0){
		puts("Errore! La socket non e' stata messa in ascolto.");
		closesocket(server_socket);
		clearwinsock();
		return -1;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------

	//-----------------------------------------------ACCETTAZIONE NUOVA CONNESSIONE-------------------------------------------------------
	struct sockaddr_in cl_add;
	memset(&cl_add, 0, sizeof(cl_add));

	int client_socket; //descrittore del socket del client
	int client_len; //grandezza dell'indirizzo del client

	puts("Server in attesa di connessioni...");

	while(1){
		client_len = sizeof(cl_add); //imposto la grandezza dell'indirizzo del client
		if((client_socket = accept(server_socket, (struct sockaddr*) &cl_add, &client_len)) < 0){
			puts("ERRORE! Connessione rifiutata.");
			closesocket(server_socket); //chiudo il socket
			clearwinsock();
			return -1;
		}
		//inet_ntoa() = converte gli host internet in indirizzi ip
		printf("Connessione stabilita con il client -> %s\n", inet_ntoa(cl_add.sin_addr));
	}

	//------------------------------------------------------------------------------------------------------------------------------------


	closesocket(server_socket);
	clearwinsock();
	return 0;
}

