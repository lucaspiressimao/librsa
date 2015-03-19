int prime(long int pr, long int * j);
int calc_private_key_exp(int n, int m);
void calc_public_key_exp(long int phi, long int *j, long int prime_num1, long int prime_num2, long int * public_key_exp, long int * private_key_exp);
void encrypt(long int int_message[100], char * msg, long int public_key_exp[100], long int modulus, long int * encrypted_msg);
void decrypt(long int * encrypted_msg, long int private_key_exp[100], long int modulus, long int int_message[100]);