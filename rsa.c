#include <math.h>
#include <string.h>

// Compute the solution x to x*n % m == 1 using the Generalized Euclidean Agorithm
int calc_private_key_exp(int n, int m) // Receive public key exponent and phi
{
	int t0 = 0;
	int t1 = 1;
	int s0 = 1;
	int s1 = 0;
	int r = m - 1; // Just to get started
	int a = m;
	int b = n;
	int q, s, t;
	
	while( r > 0 )
	{
		q = a/b;
		r = a - b*q;
		s = s0 - q*s1;
		t = t0 - q*t1;
		a = b;
		b = r;
		t0 = t1;
		t1 = t;
		s0 = s1;
		s1 = s;
	}
	// If we find a negative value, we calculate it modulo m
	return t0 < 0 ? t0 + m : t0;
} 

// Check if it is prime
int prime(long int pr, long int *j) 
{ 
    int i; 

    *j = sqrt(pr); 
    
    for( i=2 ; i <= *j ; i++ ) 
    { 
        if( (pr %i) == 0 ) 
            return 0; 
    } 
    return 1; 
}

void calc_public_key_exp(long int phi, long int *j, long int prime_num1, long int prime_num2, long int * public_key_exp, long int * private_key_exp) 
{ 
    int k; 
    int i;
    long int J = *j;
    k=0; 

    for( i=2 ; i < phi ; i++ ) 
    { 
        // continue if it is even, we need odd
        if( (phi % i) == 0) 
            continue; 

        // check if it is a prime number and diferent from that 2 that we used before
        if( (prime(i , &J) == 1) && (i != prime_num1) && (i != prime_num2)) 
        { 
            // store the public key
            public_key_exp[k]=i; 

            // calculate the private key for this public key
            if( calc_private_key_exp(public_key_exp[k], phi) > 0 ) 
            { 
                private_key_exp[k] = calc_private_key_exp(public_key_exp[k], phi); 
                k++; 
            } 

            // If reach the stack limit
            if(k == 99) 
                break;
        } 
    } 
}