#include <stdio.h>
#include <gmp.h>


/*Met dans res la cle prive a partir de pq=n la factorisation du module et de e l'exposant prive*/

void find_private_key(mpz_t res, mpz_t p, mpz_t q, mpz_t e){

	mpz_t phip, phiq, phin;
	mpz_inits(phip, phiq, phin, NULL);
	mpz_sub_ui(phip, p,1);
	mpz_sub_ui(phiq, q, 1); 
	mpz_mul(phin, phip, phiq);
	mpz_invert(res,e,phin);
}


int main(int argc, char * argv[]){

	if(argc!=4){
		fprintf(stderr, "usage: ./facto_cle p q e\n");
		fprintf(stderr, "Ou p et q est la factorisation du module RSA et e l'exposant publique\n");
		return 0;
	}
	
	mpz_t p,q,e,d;
	mpz_inits(p,q,e,d,NULL);
	mpz_set_str(p, argv[1],10);
	mpz_set_str(q, argv[2],10);
	mpz_set_str(e, argv[3],10);
	find_private_key(d,p,q,e);	
	gmp_printf("%Zd\n", d);
	
	mpz_clears(p,q,e,d);
	return 0;
}
