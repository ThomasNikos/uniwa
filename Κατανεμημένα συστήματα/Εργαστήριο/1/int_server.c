#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

static void serve(int);

#define PORT 6060
int newchild;

main( int argc, char **argv )
{int lsd; /* Listening socket */
struct sockaddr_in sin; /* Binding struct */
int sin_size=sizeof(sin);
int sd; /* Socket to accept new connexion */
/* Create listening socket */
if ( (lsd=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
{
 fprintf(stderr, "%s: cannot create listening socket: ", argv[0]);
 perror(0);
 exit(1);
}

/* Prepare binding structure sin */
sin.sin_family = AF_INET;
sin.sin_port = htons(PORT);
sin.sin_addr.s_addr = htonl(INADDR_ANY);

if ( bind(lsd, &sin, sin_size) < 0 )
{
 fprintf(stderr, "%s: cannot bind listening socket: ", argv[0]);
 perror(0);
 exit(1);
}

/* Initiate a listen queue */
if ( listen(lsd, 5) < 0 )
{
 fprintf(stderr, "%s: cannot listen on socket: ", argv[0]);
 perror(0);
 exit(1);
}

/* Take care of the SIGPIPE signal - ignore it signal(SIGPIPE, SIG_IGN); */

while ( 1 )
{
 if ( (sd=accept(lsd, &sin, &sin_size)) < 0 )
   {
    fprintf(stderr, "%s: cannot accept a new connect request from socket: ", argv[0]);
    exit(errno);
   }
if ( (newchild=fork()) <0 )
{
 fprintf(stderr, "%s: cannot create a new child to serve request: ", argv[0]);
 perror(0);
 exit(1);
}
if (newchild == 0) /* child */
{
 fprintf(stdout, "New child %d was created from parent server %d %s to serve request\n", getpid(), getppid(), argv[0]);
 serve(sd);
 shutdown(sd, 2);
 close(sd);
 exit(0);
}
}
}

void serve(int sd)
{
 char *answer;
 write(sd, "This is a sample http server response: HTTP/1.1 200 OK\n" ,55 );
 return;
}
