//serves information
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
	int socketd;
	socketd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socketd == -1) {
		std::cout << "Fatal error: Unabled to create socket!" << std::endl;
		return 1;
	}
	
	//Prepare to listen for incoming connections
	struct sockaddr_in server;
	struct sockaddr_in client;
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(12345);
	
	//Bind
	int r = bind(socketd, (struct sockaddr *)&server, sizeof(server));
	if (r < 0) {
		std::cout << "Unable to find to port!" << std::endl;
		return 1;
	}
	
	//Listen for connections
	std::cout << "Listening for incoming connections..." << std::endl;
	listen(socketd, 3);
	
	//Accept any incoming
	int c = sizeof(struct sockaddr_in);
	int nsocketd = accept(socketd, (struct sockaddr *)&client, (socklen_t*)&c);
	
	if (nsocketd < 0) {
		std::cout << "Connection failed!" << std::endl;
		return 1;
	}
	
	std::cout << "Connected accepted!" << std::endl;
	
	//Receive data
	char reply[2000];
	recv(nsocketd, reply, 2000, 0);
	
	std::cout << "Data:" << std::endl;
	std::cout << reply << std::endl;
	
	close(nsocketd);
	close(socketd);
	return 0;
}
