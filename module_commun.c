#include <stdio.h>
#include <gmp.h>

int main(int argc, char * argv[]){
	
	if(argc!=6){
	
		fprintf(stderr, "usage ./module_commun e1 e2 n m1 m2\n");
		fprintf(stderr, "e1 e2 les deux exposants publique n le module commun et m1 m2 deux messages\n");
		return 0;
	}
	
	mpz_t res, e1,e2,n,m1,m2, u, v, gcd, tmp1,tmp2;
	mpz_inits(res,e1,e2,n,m1,m2,tmp1,tmp2,u,v,gcd,NULL);
	
	mpz_set_str(e1, argv[1], 10);
	mpz_set_str(e2, argv[2], 10);
	mpz_set_str(n, argv[3], 10);
	mpz_set_str(m1, argv[4], 10);
	mpz_set_str(m2, argv[5], 10);
		
	
		
	mpz_gcdext(gcd, u,v,e1,e2);

	if(mpz_cmp_ui(gcd, 1)!=0){
		gmp_printf("Le pgcd n'est pas 1: %Zd\n", gcd);
		return 0;
	}
	//mpz_mod(u,u,n);
	//mpz_mod(v,v,n);
	
		
	mpz_powm(tmp1, m1, u, n);
	mpz_powm(tmp2, m2, v, n);
	
	mpz_mul(res, tmp1, tmp2);
	mpz_mod(res, res, n);
	
	gmp_printf("%Zd\n", res);
	
	/*mpz_powm(tmp1, m1, v, n);
	mpz_powm(tmp2, m2, u, n);
	
	mpz_mul(res, tmp1, tmp2);
	mpz_mod(res, res, n);

	gmp_printf("%Zd\n", res);
*/
	mpz_clears(res,e1,e2,n,m1,m2,tmp1,tmp2,NULL);

}














