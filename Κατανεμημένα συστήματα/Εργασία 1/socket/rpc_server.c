#include "rpc.h"
#include <err.h>
#include <stdio.h>
#include <stdlib.h>

// Cath error at malloc.

static void *catchmalloc(size_t n) {
  void *a;
  if ((a = malloc(n)) == NULL)
    err(1, "Malloc error");
  return (a);
}

float *avg_1_svc(arg_arr *argp, struct svc_req *rqstp) {
  static float result;
  int i, sum;
  for (i = 0, sum = 0; i < argp->n; i++) {
    sum += argp->arr.arr_val[i];
  }

  result = sum / (float)argp->n;
  return &result;
}

struct mm *minmax_1_svc(arg_arr *argp, struct svc_req *rqstp) {
  static struct mm result;
  int i, *min, *max;

  result.arr.arr_len = 2;
  result.arr.arr_val = catchmalloc(2 * sizeof(int));
  min = &result.arr.arr_val[0];
  max = &result.arr.arr_val[1];
  *min = *argp->arr.arr_val;
  *max = *argp->arr.arr_val;
  for (i = 0; i < argp->n; i++) {
    if (argp->arr.arr_val[i] < *min)
      *min = argp->arr.arr_val[i];
    if (argp->arr.arr_val[i] > *max)
      *max = argp->arr.arr_val[i];
  }
  return &result;
}

struct farr *prod_1_svc(aprod *argp, struct svc_req *rqstp) {
  static struct farr result;
  int i;

  result.arr.arr_len = argp->arr.n;
  result.arr.arr_val = catchmalloc(argp->arr.n * sizeof(float));
  for (i = 0; i < argp->arr.n; i++) {
    result.arr.arr_val[i] = argp->a * argp->arr.arr.arr_val[i];
  }
  return &result;
}