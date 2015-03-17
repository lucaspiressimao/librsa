#include <math.h>
#include <string.h>
// void generate_keys()
// {

// }

// Check if it is prime
int prime(long int pr) 
{ 
	long int j;
    int i; 

    j = sqrt(pr); 
    
    for( i=2 ; i<=j ; i++ ) 
    { 
        if( (pr %i) == 0 ) 
            return 0; 
    } 
    return 1; 
}