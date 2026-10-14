#include <err.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


#define BUFSIZE 1024
#define SERVER_PORT 6060

static void avg(int);
static void minmax(int);
static void prod(int);

// Cath error at malloc.

static void *catchmalloc(size_t n) {
  void *a;
  if ((a = malloc(n)) == NULL)
    err(1, "Malloc error");
  return (a);
}

// Function for average.

static void avg(int sd) {
  float res;
  int *arr, n, i;

  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr = catchmalloc(n * sizeof(int));
  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++) {
    printf("Give [%d]: ", i);
    scanf("%d", &arr[i]);
  }
  send(sd, &n, sizeof(int), 0);
  send(sd, arr, n * sizeof(int), 0);
  recv(sd, &res, sizeof(float), 0);
  printf("Server response: %.3f\n", res);

  free(arr);
}

// Function for min and max.

static void minmax(int sd) {
  int *arr, res[2], n, i;

  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr = catchmalloc(n * sizeof(int));
  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++) {
    printf("Give [%d]: ", i);
    scanf("%d", &arr[i]);
  }

  send(sd, &n, sizeof(int), 0);
  send(sd, arr, n * sizeof(int), 0);
  recv(sd, &res, 2 * sizeof(int), 0);
  printf("Server response: min: %d max: %d", res[0], res[1]);

  free(arr);
}

// Function for product.

static void prod(int sd) {
  float a, *res;
  int *arr, n, i;

  printf("Enter the value of a: ");
  scanf("%f", &a);
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr = catchmalloc(n * sizeof(int));
  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++) {
    printf("Give [%d]: ", i);
    scanf("%d", &arr[i]);
  }

  send(sd, &a, sizeof(float), 0);
  send(sd, &n, sizeof(int), 0);
  send(sd, arr, n * sizeof(int), 0);

  res = catchmalloc(n * sizeof(float));
  recv(sd, res, n * sizeof(float), 0);
  for (i = 0; i < n; i++) {
    printf("Server Response:\n%d :: %.3f\n", i, res[i]);
  }
  free(arr);
}

int main(int argc, char **argv) {
  int sd, choice;              /* Socket descriptor */
  struct sockaddr_in server;   /* Server to connect */
  struct hostent *server_host; /* Host info */
  int result;
  char *host;

  host = "localhost";

  /* Create socket */
  if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "%s: cannot create socket: ", argv[0]);
    perror(0);
    exit(1);
  }
  /* Get info on host */
  if ((server_host = gethostbyname(host)) == NULL) {
    fprintf(stderr, "%s: unknown host %s\n", argv[0], argv[1]);
    exit(1);
  }
  /* Set up struct sockaddr_in */
  server.sin_family = AF_INET;
  server.sin_port = htons(SERVER_PORT);
  bcopy((char *)server_host->h_addr, (char *)&server.sin_addr,
        server_host->h_length);

  /* Connect */
  if (connect(sd, (const struct sockaddr *)&server, sizeof(server)) < 0) {
    fprintf(stderr, "%s: cannot connect to server: ", argv[0]);
    perror(0);
    exit(1);
  }
  // Get operation from client.
  while (1) {
    printf("\nChoose an operation:\n1. Average\n2. MinMax\n3. Product\n4. "
           "Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      send(sd, &choice, sizeof(int), 0);
      avg(sd);
      break;
    case 2:
      send(sd, &choice, sizeof(int), 0);
      minmax(sd);
      break;
    case 3:
      send(sd, &choice, sizeof(int), 0);
      prod(sd);
      break;
    case 4:
      send(sd, &choice, sizeof(int), 0);
      goto end;
    default:
      printf("Invalid number\n");
    }
  }

end:
  close(sd);
  exit(0);
}
