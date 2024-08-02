#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>

#define N 4

int main(int argc, char ** argv) {
  int i, j, np, my_rank, sendarray = 0, sum = 0, count = 0, abs_value = 0, maxl = 0, maxf = 0, sbuf = 0, minl = 0, minp;
  int A[N][N], AR[N], B[N][N], B_loc[N], pos[N];
  int * receive, * maxfin, * minfin, * sendcnt, * recvnt, * displs1, * displs2, fin_min;

  MPI_Init( & argc, & argv);
  MPI_Comm_size(MPI_COMM_WORLD, & np);
  MPI_Comm_rank(MPI_COMM_WORLD, & my_rank);

  sendcnt = (int * ) malloc(N * sizeof(int));
  displs1 = (int * ) malloc(N * sizeof(int));
  receive = (int * ) malloc(N * sizeof(int));
  maxfin = (int * ) malloc(N * sizeof(int));
  minfin = (int * ) malloc(N * sizeof(int));

  for (i = 0; i < N; i++) {
    sendcnt[i] = N;
    displs1[i] = i * N;
  }

    /*In the main process (0) getting all the numbers for
    table A.*/

  if (my_rank == 0) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        printf("Give A[%d][%d]= \n", i, j);
        scanf("%d", & A[i][j]);
      }
    }
  }

  MPI_Scatterv( & A, sendcnt, displs1, MPI_INT, & AR, sendcnt[my_rank], MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);

  for (i = 0; i < N; i++) {
    if (i != my_rank) {
      sum += abs(AR[i]);
    }
  }
  if (abs(AR[my_rank]) > sum) {
    sendarray = 1;
  }

  MPI_Gather( & sendarray, 1, MPI_INT, receive, 1, MPI_INT, 0, MPI_COMM_WORLD);

  if (my_rank == 0) {
    for (i = 0; i < N; i++) {
      if (receive[i] == 1)
        count++;
    }
    if (count == N) {
      printf("\nyes\n");
      sbuf = 1;
    } else
      printf("\nno\n");
  }

  MPI_Bcast( & sbuf, 1, MPI_INT, 0, MPI_COMM_WORLD);

    //Finding Max.

  if (sbuf) {
    for (i = 0; i < N; i++) {
      abs_value = abs(AR[i]);
      if (maxl < abs_value)
        maxl = abs_value;
    }
    MPI_Gather( & maxl, 1, MPI_INT, maxfin, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (my_rank == 0) {
      for (i = 0; i < N; i++) {
        if (maxf < maxfin[i])
          maxf = maxfin[i];
      }
      printf("\nMax: %d\n", maxf);
    }
    MPI_Bcast( & maxf, 1, MPI_INT, 0, MPI_COMM_WORLD);

    recvnt = (int * ) malloc(N * sizeof(int));
    displs2 = (int * ) malloc(sizeof(int));

    for (i = 0; i < N; i++) {
      recvnt[i] = N;
      displs2[i] = i * N;
    }

    for (i = 0; i < N; i++) {
      B_loc[i] = maxf - abs(AR[i]);
    }

    MPI_Gatherv(B_loc, recvnt[my_rank], MPI_INT, & B, recvnt, displs2, MPI_INT, 0, MPI_COMM_WORLD);

    //Table B + Printing it.

    if (my_rank == 0) {
      printf("\nNew table B:\n");
      for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
          printf("%4d", B[i][j]);
        }
        printf("\n");
      }
    }

    //Finding Min.

    minl = abs(B_loc[0]);
    minp = my_rank;
    for (i = 0; i < N; i++) {
      abs_value = abs(B_loc[i]);
      if (minl > abs_value) {
        minl = abs_value;
        minp = i;
      }
    }
    MPI_Gather( & minl, 1, MPI_INT, minfin, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Gather( & minp, 1, MPI_INT, pos, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (my_rank == 0) {
      fin_min = minfin[0];
      minp = pos[0];
      int i_pos = 0;
      for (i = 1; i < N; i++) {
        if (fin_min > minfin[i]) {
          fin_min = minfin[i];
          i_pos = i;
          minp = pos[i];
        }
      }
      printf("\nMin: %d, is at i=%d, j=%d.\n", fin_min, i_pos, minp);
    }

  }

  free(sendcnt);
  free(displs1);
  free(receive);
  free(maxfin);
  free(minfin);
  MPI_Finalize();
}