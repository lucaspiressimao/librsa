#include <stdio.h> 
#include <stdlib.h> 
#include "rsa.h"

long int prime_num1;
long int prime_num2;
long int modulus;
long int phi;
long int public_key_exp[100];
long int private_key_exp[100];
long int temp[100];
long int j;
long int int_message[100];
long int en[100];
long int i;

char msg[100]; 

// void calc_public_key_exp() ;
void        encrypt(); 
void        decrypt(); 

void main() 
{ 
    // Receive 2 prime numbers
    printf("\nEnter first prime number\n"); 
    scanf("%d",&prime_num1); 

    // Check if it is prime
    if( prime(prime_num1 , &j) == 0 ) 
    {
        printf("\nIs is not prime\n"); 
        exit(1); 
    } 

    printf("debug j %ld\n", j);

    printf("\nEnter second prime number\n"); 
    scanf("%d",&prime_num2); 

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
    for( i=0 ; msg[i]!=NULL ; i++ ) 
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
    
    encrypt(); 
    decrypt(); 
}

void encrypt() 
{ 
    long int pt,ct,key=public_key_exp[0],k,len; 

    i = 0; 
    len = strlen(msg); 
    
    // formula to crypt message: c = m^e % mod{n} 

    while( i != len ) 
    { 
        pt = int_message[i]; 
        printf("\n--->%d\n",pt );
        // pt = pt-96; 
        // printf("\n--->%d\n",pt );
        k = 1; 

        for( j=0 ; j<key ; j++ ) 
        { 
            k = k * pt;
            k = k % modulus; 
        } 

        temp[i] = k; 
        ct = k + 96; 
        en[i] = ct; 
        i++; 
    } 

    en[i] = -1; 

    printf("\nTHE ENCRYPTED MESSAGE IS\n"); 
    
    for(i=0;en[i]!=-1;i++) 
        printf("%c",en[i]); 
} 

void decrypt() 
{ 
    long int pt,ct,key = private_key_exp[0],k; 
  
    i=0; 
  
    while(en[i] != -1) 
    { 
        ct = temp[i]; 
        k = 1; 

        for( j=0 ; j<key ; j++ )
        { 
            k = k * ct;
            k = k % modulus; 
        }

        // pt = k + 96; 
        int_message[i] = pt; 
        i++; 
    }

    int_message[i] = -1; 

    printf("\nTHE DECRYPTED MESSAGE IS\n"); 
    
    for(i=0;int_message[i]!=-1;i++) 
       printf("%c",int_message[i]);

   printf("\n"); 
}

// void calc_public_key_exp() 
// { 
//     int k; 
//     int i;

//     k=0; 

//     for( i=2 ; i < phi ; i++ ) 
//     { 
//         // continue if it is even, we need odd
//         if( (phi % i) == 0) 
//             continue; 

//         // check if it is a prime number and diferent from that 2 that we used before
//         if( (prime(i , &j) == 1) && (i != prime_num1) && (i != prime_num2)) 
//         { 
//             // store the public key
//             public_key_exp[k]=i; 

//             // calculate the private key for this public key
//             if( calc_private_key_exp(public_key_exp[k], phi) > 0 ) 
//             { 
//                 private_key_exp[k] = calc_private_key_exp(public_key_exp[k], phi); 
//                 k++; 
//             } 

//             // If reach the stack limit
//             if(k == 99) 
//                 break;
//         } 
//     } 
// }