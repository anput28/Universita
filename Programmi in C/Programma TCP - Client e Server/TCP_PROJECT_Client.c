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

#define BUFFER_SIZE 512
#define PROTO_PORT 27015 //porta TCP libera


//questa funzione termina l'esecuzione di Ws2_32.dll, cioè di WinSock, perciò è necessario eseguire questa funzione solo in Windows.
void clearwinsock(){
	#ifdef WIN32
		WSACleanup();
	#endif
}

int main(){
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

	//-------------------------------------------------------CREAZIONE SOCKET-------------------------------------------------------------
	int client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(client_socket < 0){
		puts("Errore nella creazione del socket.");
		clearwinsock();
		return -1;
	}
	//------------------------------------------------------------------------------------------------------------------------------------

	//--------------------------------------------COSTRUZIONE INDIRIZZO SERVER------------------------------------------------------------
	struct sockaddr_in sv_add;
	memset(&sv_add, 0, sizeof(sv_add));

	sv_add.sin_family = AF_INET;
	sv_add.sin_port = htons(PROTO_PORT);
	sv_add.sin_addr.s_addr = inet_addr("127.0.0.1");
	//------------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------CONNESSIONE AL SERVER------------------------------------------------------------
	if((connect(client_socket, (struct sockaddr*) &sv_add, sizeof(sv_add))) < 0){
		puts("ERRORE! Impossibile connettersi al server.");
		closesocket(client_socket);
		clearwinsock();
		return -1;
	}
	//------------------------------------------------------------------------------------------------------------------------------------

	char msg_to_send[] = "Ciao Server"; //stringa da inviare al server
	int msg_len = sizeof(msg_to_send);

	//---------------------------------------------------INVIO DATI AL SERVER-------------------------------------------------------------
	if((send(client_socket, msg_to_send, msg_len, 0)) != msg_len){
		puts("ERRORE! Sono stati inviati piu' byte del previsto.");
		closesocket(client_socket);
		clearwinsock();
		return -1;
	}
	//------------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------RICEVERE DATI DAL SERVER---------------------------------------------------------
	int bytes_rcvd;
	int total_bytes_rcvd = 0;
	char buf[BUFFER_SIZE];
	puts("Ricevuto: ");
	while(total_bytes_rcvd < msg_len){
		if( (bytes_rcvd = recv(client_socket, buf, BUFFER_SIZE-1, 0)) <= 0){
			puts("Errore nella ricezione dei dati o per la chiusura prematura della connessione.");
			closesocket(client_socket);
			clearwinsock();
			return -1;
		}
		total_bytes_rcvd += bytes_rcvd;
		buf[bytes_rcvd] = '\0';
		printf("%s", buf);
	}
	//------------------------------------------------------------------------------------------------------------------------------------

	closesocket(client_socket);
	clearwinsock();
}
