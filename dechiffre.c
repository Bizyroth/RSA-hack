#include <stdio.h>
#include <gmp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void dechiffre(mpz_t res, mpz_t cipher, mpz_t d, mpz_t n){
	mpz_powm(res, cipher, d,n);
}


int main(int argc, char * argv[]){

	if(argc!=4){
		fprintf(stderr, "usage: ./dechiffre cipher d n\n");
		fprintf(stderr, "Ou cipher est un entier representant un texte chiffre d la cle prive et n le module rsa\n");
		return 0;
	}
	
	mpz_t res, cipher, d, n;
	mpz_inits(res, cipher, d, n, NULL);
	
	mpz_set_str(cipher, argv[1],10);
	mpz_set_str(d, argv[2], 10);
	mpz_set_str(n, argv[2], 10);
	dechiffre(res,cipher,d,n);
	
	gmp_printf("%Zd\n",res);
	mpz_clears(res,cipher,d,n,NULL);
	return 0;
}
