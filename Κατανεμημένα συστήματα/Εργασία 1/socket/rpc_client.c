#include "rpc.h"
#include <err.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 6060
int newchild;

static void worker(char *, int);

// Cath error at malloc.

static void *catchmalloc(size_t n) {
  void *a;
  if ((a = malloc(n)) == NULL)
    err(1, "Malloc error");
  return (a);
}

// Function for average.

void avg_prog_1(char *host, int sock) {
  CLIENT *clnt;
  float *result_1;
  arg_arr avg_1_arg;
  int n, *arr;

#ifndef DEBUG
  clnt = clnt_create(host, avg_PROG, avg_VERS, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror(host);
    exit(1);
  }
#endif /* DEBUG */
  if (recv(sock, &n, sizeof(int), 0) < 0) {
    goto fail;
  }

  avg_1_arg.n = n;
  avg_1_arg.arr.arr_len = n;
  avg_1_arg.arr.arr_val = catchmalloc(n * sizeof(int));
  arr = avg_1_arg.arr.arr_val;

  if (recv(sock, arr, n * sizeof(int), 0) < 0)
    goto fail;

  result_1 = avg_1(&avg_1_arg, clnt);
  if (result_1 == (float *)NULL) {
    clnt_perror(clnt, "call failed");
  }

  printf("Sock: %d\tserver response: avg: %.3f\n", sock, *result_1);
  if (send(sock, result_1, sizeof(float), 0) < 0)
    goto fail;
  return;
fail:
  fprintf(stderr, "Connection with client %d dropped\n", sock);
  close(sock);
  if (arr != NULL)
    free(arr);

#ifndef DEBUG
  clnt_destroy(clnt);
#endif /* DEBUG */
}

// Function for min and max.

void minmax_prog_1(char *host, int sock) {
  CLIENT *clnt;
  struct mm *result_1;
  arg_arr minmax_1_arg;
  int n, *arr;

#ifndef DEBUG
  clnt = clnt_create(host, minmax_PROG, minmax_VERS, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror(host);
    exit(1);
  }
#endif /* DEBUG */
  if (recv(sock, &n, sizeof(int), 0) < 0) {
    goto fail;
  }

  minmax_1_arg.n = n;
  minmax_1_arg.arr.arr_len = n;
  minmax_1_arg.arr.arr_val = catchmalloc(n * sizeof(int));
  arr = minmax_1_arg.arr.arr_val;

  if (recv(sock, arr, n * sizeof(int), 0) < 0)
    goto fail;

  result_1 = minmax_1(&minmax_1_arg, clnt);
  if (result_1 == (struct mm *)NULL) {
    clnt_perror(clnt, "call failed");
  }
  printf("Sock: %d\tserver response: \nMin: %d\nMax: %d\n", sock,
         result_1->arr.arr_val[0], result_1->arr.arr_val[1]);
  if (send(sock, result_1->arr.arr_val, 2 * sizeof(int), 0) < 0)
    goto fail;
  return;
fail:
  fprintf(stderr, "Connection with client %d dropped\n", sock);
  close(sock);
  if (arr != NULL)
    free(arr);
#ifndef DEBUG
  clnt_destroy(clnt);
#endif /* DEBUG */
}

// Function for product.

void prod_prog_1(char *host, int sock) {
  CLIENT *clnt;
  struct farr *result_1;
  aprod prod_1_arg;
  int i, n, *arr;
  float a;

#ifndef DEBUG
  clnt = clnt_create(host, prod_PROG, prod_VERS, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror(host);
    exit(1);
  }
#endif /* DEBUG */

  if (recv(sock, &a, sizeof(int), 0) < 0) {
    goto fail;
  }
  if (recv(sock, &n, sizeof(int), 0) < 0) {
    goto fail;
  }
  prod_1_arg.a = a;
  prod_1_arg.arr.n = n;
  prod_1_arg.arr.arr.arr_len = prod_1_arg.arr.n;
  prod_1_arg.arr.arr.arr_val = catchmalloc(prod_1_arg.arr.n * sizeof(float));
  arr = prod_1_arg.arr.arr.arr_val;

  if (recv(sock, arr, n * sizeof(int), 0) < 0)
    goto fail;

  result_1 = prod_1(&prod_1_arg, clnt);
  if (result_1 == (struct farr *)NULL) {
    clnt_perror(clnt, "call failed");
  }
  printf("Sock: %d\tServer response: \n", sock);
  for (i = 0; i < prod_1_arg.arr.n; i++) {
    printf("%d :: %.3f\n", i, result_1->arr.arr_val[i]);
  }
  if (send(sock, result_1->arr.arr_val, n * sizeof(float), 0) < 0)
    goto fail;
  return;
fail:
  fprintf(stderr, "Connection with client %d dropped\n", sock);
  close(sock);
  if (arr != NULL)
    free(arr);

#ifndef DEBUG
  clnt_destroy(clnt);
#endif /* DEBUG */
}

static void worker(char *host, int sd) {
  int choice;
  // Receive choice from socket.
  while (1) {
    if (recv(sd, &choice, sizeof(int), 0) < 0) {
      fprintf(stderr, "Connection with %d dropped\n", sd);
      close(sd);
      _exit(0);
    }
    switch (choice) {
    case 1:
      avg_prog_1(host, sd);
      break;
    case 2:
      minmax_prog_1(host, sd);
      break;
    case 3:
      prod_prog_1(host, sd);
      break;
    case 4:
      printf("Sock %d disconnected\n", sd);
      close(sd);
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  char *host;

  if (argc < 2) {
    printf("usage: %s server_host\n", argv[0]);
    exit(1);
  }

  host = argv[1];

  int lsd;                /* Listening socket */
  struct sockaddr_in sin; /* Binding struct */
  int sin_size = sizeof(sin);
  int sd; /* Socket to accept new connexion */
  /* Create listening socket */
  if ((lsd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "%s: cannot create listening socket: ", argv[0]);
    perror(0);
    exit(1);
  }

  /* Prepare binding structure sin */
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(lsd, (struct sockaddr *)&sin, sin_size) < 0) {
    fprintf(stderr, "%s: cannot bind listening socket: ", argv[0]);
    perror(0);
    exit(1);
  }

  /* Initiate a listen queue */
  if (listen(lsd, 5) < 0) {
    fprintf(stderr, "%s: cannot listen on socket: ", argv[0]);
    perror(0);
    exit(1);
  }

  /* Take care of the SIGPIPE signal - ignore it signal(SIGPIPE, SIG_IGN); */

  while (1) {
    if ((sd = accept(lsd, (struct sockaddr *)&sin, &sin_size)) < 0) {
      fprintf(stderr,
              "%s: cannot accept a new connect request from socket: ", argv[0]);
      exit(errno);
    }
    if ((newchild = fork()) < 0) {
      fprintf(stderr,
              "%s: cannot create a new child to serve request: ", argv[0]);
      perror(0);
      exit(1);
    }
    if (newchild == 0) /* child */
    {
      fprintf(stdout,
              "New child %d was created from parent server %d %s to serve "
              "request\n",
              getpid(), getppid(), argv[0]);
      worker(host, sd);
      close(sd);
      exit(0);
    } else {
      close(sd);
    }
  }
}
