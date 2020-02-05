#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include "packetbuilder.h"
#define MAX 80 
#define PORT 5000 
#define SA struct sockaddr
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n,m; 
    char *str;
    char buff2[MAX];
    int exitFlag = 0;
    int exampleQueueNum = 3;
    double exampleSensorData = 10.423;
    char *exampleState = "Ready";
    str = malloc(sizeof (char) * MAX);
    int firstTime = 0;
    while (exitFlag != 1){
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n'); 
        /*printf("initial input is: |%s|\n", buff);
        strncat(buff2, buff, 1);
        printf("buff2 input is: |%s|\n", buff);*/
        //strcpy (str, buff);
        //strcat(str, "\n");

        //printf("Double1 is: %f\n", exampleSensorData);
        //printf("String is1: %s\n",buff);
        if (strncmp(buff,"a",1)==0){
        	str = BuildPacketI(buff, exampleQueueNum);
        }else if (strncmp(buff,"b",1)==0){
        	str = BuildPacketI(buff, exampleQueueNum);
        }else if (strncmp(buff,"j",1)==0){
        	str = BuildPacketS(buff, exampleState);
        }else{
        	str = BuildPacketD(buff, exampleSensorData);
        }
        //printf("String is2: |%s|\n",str);
        //printf("n is %d\n", n);
        n = strlen(str)-1;
       // printf("n is %d\n", n);
        m = write(sockfd, str, n); 
        m = write(sockfd, "\n", 1); 
        //printf("String is3: |%s|\n",str);
        //free(str);
        if (m < 0){
            	perror ("ERROR writing to socket\n");
        }
        bzero(buff, sizeof(buff)); 
        m = read(sockfd, buff, sizeof(buff)); 
        if (n < 0) {
      		perror("ERROR reading from socket\n");
    	}
        printf("From Server : %s\n", buff); 
        if ((strncmp(buff, "exit", 4)) == 0) { 
        	exitFlag = 1;
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
} 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 