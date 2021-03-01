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


void clearwinsock(){
	#ifdef WIN32
		WSACleanup();
	#endif
}

int main(int argc, char *argv[]) {
	
	int port = 0;
	
	do{
		printf("Inserire il numero di porta: \n");
		scanf("%d", port);
		if(port < 49152 || port > 65535){
			printf("ERRORE! Bisogna inserire una porta privata (49152 - 65535).");
		}
	while(port < 49152 || port > 65535){

	
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
		int my_socket;
}
