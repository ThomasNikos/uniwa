//decryption.c
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
	BIGNUM *d = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *c = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *start_m = BN_new();
	BN_hex2bn(&d, "3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB");
	BN_hex2bn(&c, "617AB29ECDA432F9B7C5F8E8044404EBFD8B285A699ABED2575B252F78057164");
	BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
	BN_hex2bn(&start_m, "4E696B6F6C616F732054686F6D6173");

	BN_mod_exp(m, c, d, n, ctx);

	printBN("(*) Decrypted Message = ", m);
	if(BN_cmp(start_m,m) == 0){
		printf("Messages are the same!\n");
	}else{
		printf("Messages are not the same!\n");
	}
}
