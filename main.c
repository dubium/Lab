#include <stdio.h>
#include <stdbool.h>

int* primes;

int* generate_primes(int num);
bool is_prime(int num){
    bool prime = true;

    if (num>1){
        for (int i=2; i<num; i++){
            if (num%i == 0){
                prime = false;
                break;
            }
        }
    }
    return prime;
}
int* generate_primes (int num) {
    static int pr[10];
    int j=0;
    for (int i=2; i<=num; i++) {
        if (is_prime(i)) { pr[j] = i; j++;}    }

    return pr;
};
bool get_sum_primes(int num, int *prime1, int *prime2) {
    bool is_sum_primes = false;
    /*Determinar tamaño array*/

    //size_t n = sizeof(primes) / sizeof(primes[0]);

    for (int j = 0; primes[j] < num; j++) {
        *prime1 = primes[j];

        for (int i = j; primes[i] < num; i++) {
            *prime2 = primes[i];
            // prime2 = &primes[i]  FAILS
            int prime_sum = *prime1 + *prime2;

            if (num == prime_sum) {
                is_sum_primes = true;
                break;
            }
        }

        if (is_sum_primes == true) {
            break;
        }
    }
    return is_sum_primes;
}


int main() {
    int prime1;
    int prime2;
    int num = 12;

    primes = generate_primes(15);
    bool is_sum_primes = get_sum_primes(num, &prime1, &prime2);
    if (is_sum_primes) {
        printf("%d = %d+%d\n", num, prime1, prime2);
    } else {
        printf("%d is not the sum of two prime numbers.\n", num);
    }

    return 0;
}

//int primes[] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173};
/*
 char* get_binary2(int num){
    static char bin[5];
    bin[4] = '\0';
    int i = 0;
    for (i=3; i>=0; i--) {
        bin[i] = (char) num%2 + '0';
        num = num/2;
    }
    return bin;
}
char* get_binary3(int num){
    static char bin[5];
    bin[4] = '\0';
    int i = 0;
    for (i=0; i<4; i++)  {
        if (num%2)  { bin[3-i] = '1';}
        else        { bin[3-i] = '0'; }
        num = num/2;
    }
 //   printf("HELLO!");
 //   printf("%s",bin);
    return bin;
}
*/

//int primes[10];  // look for how to create dynamic arrays (mallowc / alloc)
