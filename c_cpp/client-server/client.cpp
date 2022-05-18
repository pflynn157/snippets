//receives information
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
	int socketd;
	socketd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socketd == -1) {
		std::cout << "Fatal error: Unabled to create socket!" << std::endl;
		return 1;
	}
	
	//Connect to our server
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(12345);
	
	int r = connect(socketd, (struct sockaddr *)&server, sizeof(server));
	if (r < 0) {
		std::cout << "Fatal Error: Unable to connect to server." << std::endl;
		return 1;
	}
	
	std::cout << "Connected!" << std::endl;
	std::cout << "Sending data..." << std::endl;
	
	const char *msg = "Hello!";
	send(socketd, msg, strlen(msg), 0);
	
	close(socketd);
	return 0;
}
