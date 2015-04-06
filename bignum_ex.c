#include <stdio.h> 
#include <stdlib.h> 
#include "src/bignum.h"

main()
{
	int a,b;
	bignum n1,n2,n3,zero;
	bignum teste;

	str_to_bignum("1234567890987654321234567890987654321", &teste);
	print_bignum(&teste);

	str_to_bignum("0", &teste);
	print_bignum(&teste);

	scanf("%d %d\n",&a,&b);
	printf("a = %d    b = %d\n",a,b);
	int_to_bignum(a,&n1);
	int_to_bignum(b,&n2);

	add_bignum(&n1,&n2,&n3);
	printf("addition -- ");
	print_bignum(&n3);

	printf("compare_bignum a ? b = %d\n",compare_bignum(&n1, &n2));

	subtract_bignum(&n1,&n2,&n3);
	printf("subtraction -- ");
	print_bignum(&n3);

    multiply_bignum(&n1,&n2,&n3);
	printf("multiplication -- ");
            print_bignum(&n3);

	int_to_bignum(0,&zero);
	if (compare_bignum(&zero, &n2) == 0)
		printf("division -- NaN \n");
            else {
		divide_bignum(&n1,&n2,&n3);
		printf("division -- ");
            	print_bignum(&n3);
	}
	printf("--------------------------\n");
	
}
