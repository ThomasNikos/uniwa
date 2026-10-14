#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define BUFSIZE 1024
#define SERVER_PORT 6060
main( int argc, char **argv )
{int sd; /* Socket descriptor */
struct sockaddr_in server; /* Server to connect */
struct hostent *server_host; /* Host info */
char buf[BUFSIZE];
int nbytes;
/* Create socket */
if ( (sd=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
{ fprintf(stderr, "%s: cannot create socket: ", argv[0]);
  perror(0);
  exit(1);
}
/* Get info on host */
if ( (server_host=gethostbyname(argv[1])) == NULL )
{ fprintf(stderr, "%s: unknown host %s\n", argv[0], argv[1]);
  exit(1);
}
/* Set up struct sockaddr_in */
server.sin_family = AF_INET;
server.sin_port = htons(SERVER_PORT);
bcopy((char*)server_host->h_addr, (char*)&server.sin_addr, server_host->h_length);

/* Connect */
if ( connect(sd, &server, sizeof(server)) < 0 )
{
 fprintf(stderr, "%s: cannot connect to server: ", argv[0]);
 perror(0);
 exit(1);
}

/* Get answer data */
if ( (nbytes=read(sd, buf, BUFSIZE-1)) <= 0 )
{ fprintf(stderr, "%s: read failed: ", argv[0]);
  perror(0); exit(1);
}
buf[nbytes] = 0;
printf("Answer from server was:%s\n", buf);
close(sd);
exit(0);
}
