#include <math.h>
#include <string.h>
#include <stdio.h>

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
    k=0; 

    for( i=2 ; i < phi ; i++ ) 
    { 
        // continue if it is even, we need odd
        if( (phi % i) == 0) 
            continue; 

        // check if it is a prime number and diferent from that 2 that we used before
        if( (prime(i , &*j) == 1) && (i != prime_num1) && (i != prime_num2)) 
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

void encrypt(long int int_message[100], char * msg, long int public_key_exp[100], long int modulus, long int * encrypted_msg)
{ 
    long int pt;
    long int key = public_key_exp[0];
    long int k;
    long int len;
    long int j;
    long int i = 0;

    len = strlen(msg); 

    while( i != len ) 
    { 
        pt = int_message[i]; 
        k = 1; 

        for( j=0 ; j<key ; j++ ) 
        { 
            k = k * pt;
            k = k % modulus; 
        } 

        encrypted_msg[i] = k; 
        i++; 
    } 

    encrypted_msg[i] = -1; 

    printf("\nThe encrypted message is\n"); 
    
    for(i=0;encrypted_msg[i]!=-1;i++) 
        printf("%c",(char)encrypted_msg[i]); 
}

void decrypt(long int * encrypted_msg, long int private_key_exp[100], long int modulus, long int int_message[100])
{ 
    long int ct;
    long int key = private_key_exp[0];
    long int k; 
    long int i = 0;
    long int j;
  
    printf("\nThe decrypted message is\n"); 

    while(encrypted_msg[i] != -1) 
    { 
        k = 1; 
        ct = encrypted_msg[i];
        
        for( j=0 ; j < key ; j++ )
        { 
            k = k * ct;
            k = k % modulus; 
        }

        int_message[i] = k; 
        i++; 
    }

    int_message[i] = -1; 

    for(i=0;int_message[i]!=-1;i++) 
       printf("%c",(char)int_message[i]);
}