//verify_sign_alice.c
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
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *s = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *start_m = BN_new();
	BN_hex2bn(&s, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&start_m, "4C61756E63682061206D697373696C652E");
	BN_mod_exp(m, s, e, n, ctx);

	printBN("(*) Verify Sign = ", m);
	if(BN_cmp(start_m,m) == 0){
		printf("Messages are the same!\n");
	}else{
		printf("Messages are not the same!\n");
	}
}
