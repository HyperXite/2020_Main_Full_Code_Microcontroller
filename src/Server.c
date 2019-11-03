#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main( int argc, char *argv[] )
{
    int sockfd, clisockfd, portno;
    char start[255] = "start";
    char end[255] = "end";
    socklen_t clilen;
    char buffer[255];
    char contentBuffer[255];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    //int optval;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR1 opening socket");
        return(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("ERROR2 on binding");
        return(1);
    }

    listen(sockfd,5);
    clilen = (socklen_t) sizeof(cli_addr);

    clisockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (clisockfd < 0) 
    {
        perror("ERROR3 on accept");
        return(1);
    }

    while (strncmp(end, buffer,3) !=0)
    {
        //bzero(buffer,255);
        //bzero(contentBuffer,255);
        memset(buffer, '\0', sizeof(buffer));
        memset(contentBuffer, '\0', sizeof(contentBuffer));
        /* If connection is established then start communicating */
        n = read( clisockfd,buffer,255 );
        if (n < 0)
        {
            perror("ERROR4 reading from socket");
            return(1);
        }

        strncpy(contentBuffer,buffer,strlen(buffer) - 1);

        //printf("command2db1: %s.\n",start);
       	//printf("command1db1: %s.\n",buffer);
        //printf("startcomparedb1: %d\n",strncmp(start, buffer,5));
        //printf("endcomparedb1: %d\n",strncmp(end, buffer,3));

        if (strncmp(start, contentBuffer,5) == 0)
        {
            printf("command: %s\n",buffer);
            n = write(clisockfd,"Hello\n",7);
            if (n < 0)
            {
                perror("ERROR5 writing to socket");
                return(1);
            }
        }else if (strncmp(end, contentBuffer,3) == 0){
        	printf("command: %s\n",buffer);
        	n = write(clisockfd,"shutting down\n",14);
            if (n < 0)
            {
                perror("ERROR6 writing to socket");
                return(1);
            }
        }
        else 
        {
            printf("Unknown command: %s\n",contentBuffer);
            n = write(clisockfd,"ERRCmd\n",8);
            if (n < 0)
            {
                perror("ERROR7 writing to socket");
                return(1);
            }           
        }
    }
    close(sockfd);
    return 0;


}