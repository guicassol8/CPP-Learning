#include <iostream>
#include <vector>
#include <gmp.h>
#include <stdio.h>

using namespace std;

long int somaAlgarismos (long int num){
	return num%10 + somaAlgarismos(num/10);
}


int main(){

	mpz_t n, i, j, resultado;
	mpz_init (n);
	mpz_init (i);
	mpz_init (j);
	mpz_init (resultado);
	mpz_set_ui(resultado, 0);
	mpz_set_ui(i, 1);
	mpz_set_ui(j, 1);
	gmp_scanf("%Zd", n);
	gmp_printf("%Zd\n", n);
	mpz_sqrtrem(resultado, i, n);
	mpz_sub(resultado, n, resultado);
	gmp_printf("resultado: %Zd\n", resultado);

	    mpz_t sum, temp;
    mpz_init(sum);
    mpz_init(temp);

    // Initialize a variable to use as a constant 10
    mpz_t ten;
    mpz_init_set_si(ten, 10);

    // Loop to extract digits and add them to the sum
    while (mpz_cmp_ui(resultado, 0) > 0) {
        // Get the last digit (remainder when divided by 10)
        mpz_mod(temp, resultado, ten);

        // Add the digit to the sum
        mpz_add(sum, sum, temp);

        // Remove the last digit (integer division by 10)
        mpz_fdiv_q(resultado, resultado, ten);
    }
	// for (mpz_set_ui(i,1); mpz_cmp(j,n) <= 0; mpz_add_ui(i,i,1),mpz_mul(j,i,i)){
	// 	mpz_add_ui(resultado,resultado,1);
	// }
	gmp_printf("Sum of digits: %Zd\n", sum);
	return 0;
}



/*
	int resultado = 0;
	for (int i = 1; i*i <= n; i++){
		resultado++;
	}
}*/