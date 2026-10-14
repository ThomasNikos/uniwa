#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM * a){

	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

int main(){
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *t = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *subp1 = BN_new();
	BIGNUM *subq1 = BN_new();
	BIGNUM *fn = BN_new();
	BIGNUM *d = BN_new();

	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	BN_hex2bn(&e, "0D88C3");
	BN_hex2bn(&t, "1");

	BN_mul(n, p, q, ctx);
	BN_sub(subp1, p, t);
	BN_sub(subq1, q, t);
	BN_mul(fn, subp1, subq1, ctx);
	BN_mod_inverse(d, e, fn, ctx);

	printBN("(*) N = ", n);
	printBN("(*) F(N) = ", fn);
	printBN("(*) d = ", d);

}