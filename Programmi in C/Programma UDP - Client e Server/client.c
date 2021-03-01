#if defined WIN32
	#include <winsock.h>
#else
	#include <string.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <netinet/in.h>
	#include <netdb.h>
#define closesocket close
#endif

#include <stdio.h>

#define NOME 40

void clearwinsock(){
	#ifdef WIN32
		WSACleanup();
	#endif
}

int main(int argc, char *argv[]) {
	//--------------------------------------INIZIALIZZAZIONE WINSOCK-------------------------------------------------------
	#if defined WIN32
		// Initialize Winsock
		WSADATA wsa_data;
		int result =
		WSAStartup(MAKEWORD(2,2), &wsa_data);
		if (result != 0) {
			printf("Error at WSAStartup()\n");
			return 0;
		}
	#endif
	//-------------------------------------------------------------------------------------------------------------------------
	
	//----------------------------------------------------INSERIMENTO DATI UTENTE------------------------------------------------
	int porta = 0;
	const char *nomeServer;
	struct hostent *serverHost;
	
	printf("Inserire il nome del server: \n->");
	scanf("%s", nomeServer);
	
	serverHost = gethostbyname(nomeServer);
	
	char* indirizzoServer; 
	if (serverHost == NULL) {
		fprintf(stderr, "gethostbyname() failed.\n");
		exit(EXIT_FAILURE);
	}else{
		struct in_addr* ina = (struct in_addr*) serverHost->h_addr_list[0];
		indirizzoServer = inet_ntoa(*ina);
	}
	
	do{
		printf("\nInserire il numero di porta del server: \n->");
		scanf("%d", &porta);
		if(porta < 49152 || porta > 65535){
			fprintf(stderr, "ERRORE! Bisogna inserire una porta privata (49152 - 65535).\n");
		}
	}while(porta < 49152 || porta > 65535);
			
	//---------------------------------------------------------------------------------------------------------------------------
	
	//-----------------------------------------CREAZIONE SOCKET CLIENT---------------------------------------------------------
	int client_socket;
	if ((client_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
		fprintf(stderr, "socket() failed");
	}
	//-------------------------------------------------------------------------------------------------------------------------
	
	//----------------------------------------CREAZIONE E INIZIALIZZAZIONE DEI SOCKET_ADDRESS---------------------------------------
	struct sockaddr_in sockaddr_server;
	struct sockaddr_in sockaddr_client;
	
	
	//inizializzazione socket address del server
	memset(&sockaddr_server, 0, sizeof(sockaddr_server));
	sockaddr_server.sin_family = PF_INET;
	sockaddr_server.sin_port = htons(porta);
	sockaddr_server.sin_addr.s_addr = inet_addr(indirizzoServer);
	
	printf("\n\n%s\n", sockaddr_server.sin_addr.s_addr);
	
}
