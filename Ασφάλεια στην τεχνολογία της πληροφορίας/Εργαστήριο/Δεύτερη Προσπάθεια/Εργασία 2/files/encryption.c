//encryption.c
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
	BIGNUM *name = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *c = BN_new();
	BN_hex2bn(&name, "4E696B6F6C616F732054686F6D6173");
	BN_hex2bn(&e, "0D88C3");
	BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");

	BN_mod_exp(c, name, e, n, ctx);

	printBN("(*) Encrypted Message = ", c);
}
