#include <stdio.h> 
#include <stdlib.h> 
#include "src/rsa.h"


long int prime_num1;
long int prime_num2;
long int modulus;
long int phi;
long int public_key_exp[100];
long int private_key_exp[100];
long int j;
long int int_message[100];
long int encrypted_msg[100];
long int i;

char msg[100]; 

void main() 
{ 
    // Receive 2 prime numbers
    printf("\nEnter first prime number\n"); 
    scanf("%ld",&prime_num1); 

    // Check if it is prime
    if( prime(prime_num1 , &j) == 0 ) 
    {
        printf("\nIs is not prime\n"); 
        exit(1); 
    } 

    printf("debug j %ld\n", j);

    printf("\nEnter second prime number\n"); 
    scanf("%ld",&prime_num2); 

    // Check if it is prime
    if( prime(prime_num2 , &j) == 0 || prime_num1 == prime_num2 ) 
    { 
        printf("\nIs is not prime or it is equal to number 1\n"); 
        exit(1); 
    } 

    printf("debug j %ld\n", j);

    printf("\nMessage to encrypt and decrypt\n"); 
    fflush(stdin); 
    scanf("%s",msg); 

    // Convert message to int
    for( i=0 ; msg[i] != '\0' ; i++ ) 
        int_message[i] = msg[i]; 
    
    // Calculate modulus
    modulus = prime_num1 * prime_num2;
    phi = modulus - (prime_num1 + prime_num2 -1);

    calc_public_key_exp(phi, &j, prime_num1, prime_num2, public_key_exp, private_key_exp); 
    // calc_public_key_exp(); 

    printf("debug j %ld\n", j);

    printf("\nPossible values of key exponent:\n\npublic\tprivate"); 
    

    for( i=0 ; i<j-1 ; i++ ) 
        printf("\n%ld\t%ld",public_key_exp[i],private_key_exp[i]); 
    
    encrypt(int_message, msg, public_key_exp, modulus, encrypted_msg); 
    decrypt(encrypted_msg, private_key_exp, modulus, int_message); 
    
    printf("\n"); 
}
