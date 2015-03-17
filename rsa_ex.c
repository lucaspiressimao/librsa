#include <stdio.h> 
#include <stdlib.h> 
#include "rsa.h"

long int p;
long int q;
long int n; //modulus
long int t;
long int e[100];
long int d[100];
long int temp[100];
long int j;
long int m[100];
long int en[100];
long int i; ;

char msg[100]; 

void        ce(); 
void        encrypt(); 
void        decrypt(); 
long int    cd(long int); 

void main() 
{ 
    // Receive 2 prime numbers
    printf("\nEnter first prime number\n"); 
    scanf("%d",&p); 

    // Check if it is prime
    if( prime(p) == 0 ) 
    { 
        printf("\nIs is not prime\n"); 
        exit(1); 
    } 

    printf("\nEnter second prime number\n"); 
    scanf("%d",&q); 

    // Check if it is prime
    if( prime(q) == 0 || p == q ) 
    { 
        printf("\nIs is not prime or it is equal to number 1\n"); 
        exit(1); 
    } 

    printf("\nMessage to encrypt and decrypt\n"); 
    fflush(stdin); 
    scanf("%s",msg); 

    // Copy message to int
    for( i=0 ; msg[i]!=NULL ; i++ ) 
        m[i] = msg[i]; 
    
    // Calculate modulus
    n = p*q; 
    t = (p-1) * (q-1); 

    ce(); 

    printf("\nPOSSIBLE VALUES OF e AND d ARE\n"); 
    
    for( i=0 ; i<j-1 ; i++ ) 
        printf("\n%ld\t%ld",e[i],d[i]); 
    
    encrypt(); 
    decrypt(); 
}



void ce() 
{ 
    int k; 

    k=0; 

    for( i=2 ; i<t ; i++ ) 
    { 
        if( (t % i) == 0) 
            continue; 

        if( (prime(i) == 1) && (i != p) && (i != q)) 
        { 
            e[k]=i; 

            if( cd(e[k]) > 0 ) 
            { 
                d[k] = cd(e[k]); 
                k++; 
            } 

            if(k == 99) 
                break;
        } 
    } 
} 

long int cd(long int x) 
{ 
    long int k = 1; 

    while(1) 
    { 
        k = k+t; 
        if( (k % x) == 0 ) 
            return( k / x ); 
    } 
} 

void encrypt() 
{ 
    long int pt,ct,key=e[0],k,len; 

    i = 0; 
    len = strlen(msg); 
    
    while( i != len ) 
    { 
        pt = m[i]; 
        pt = pt-96; 
        k = 1; 

        for( j=0 ; j<key ; j++ ) 
        { 
            k = k * pt;
            k = k % n; 
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
    long int pt,ct,key = d[0],k; 
  
    i=0; 
  
    while(en[i] != -1) 
    { 
        ct = temp[i]; 
        k = 1; 

        for( j=0 ; j<key ; j++ )
        { 
            k = k * ct;
            k = k % n; 
        }

        pt = k + 96; 
        m[i] = pt; 
        i++; 
    }

    m[i] = -1; 

    printf("\nTHE DECRYPTED MESSAGE IS\n"); 
    
    for(i=0;m[i]!=-1;i++) 
       printf("%c",m[i]); 
}
