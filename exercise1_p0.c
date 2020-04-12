#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "exercise1_p0.h"

/*----------------------------- Functions Exercise 1 -------------------------*/

/**
 * Ex. 1.1
 * Returns the binary representation of an integer.
 *
 * @param num An arbitrary integer in decimal representation.
 * @return The binary representation of the passed number.
 *
 */
int get_binary(int num){

// Implement this function

}

/**
 * Ex. 1.2.1
 * Returns the factorial of a number. (Iterative implementation).
 *
 * @param num An arbitrary natural number.
 * @return The factorial of the number, or ERROR_NUMBER if not a natural number.
 *
 */
long long int factorial_i(int num) {
    int i;
    long long int result=1;
    for (i=2; i <= num; i++) {
        result = result * i;
    }
    return result;
}

/**
 * Ex. 1.2.2
 * Returns the factorial of a number. (Recursive implementation).
 *
 * @param num An arbitrary natural number.
 * @return The factorial of the number, or ERROR_NUMBER if not a natural number.
 *
 */
long long int factorial_r(int num){
    long long int result;
    return (long long int)  num * factorial_r(num-1);
}

/**
 * Ex. 1.3.1
 * Returns the Fibonacci of a number. (Iterative implementation).
 *
 * @param num An arbitrary natural number.
 * @return The Fibonacci of the number, or ERROR_NUMBER if not a natural number.
 *
 */
int fibonacci_i(int num){

// Implement this function

}

/**
 * Ex. 1.3.2
 * Returns the Fibonacci of a number. (Recursive implementation).
 *
 * @param num An arbitrary natural number.
 * @return The Fibonacci of the number, or ERROR_NUMBER if not a natural number.
 *
 */
int fibonacci_r(int num){

// Implement this function

}

/**
 * Ex. 1.4
 * Indicates if the number passed is a prime number.
 *
 * @param num An arbitrary natural number greater than 1.
 * @return A boolean indicating whether the number is prime.
 *
 */
bool is_prime(int num){

// Implement this function

}

/**
 * Ex. 1.5
 * Indicates whether the number passed can be expressed as the sum of two prime numbers.
 *
 * @param num An arbitrary natural number greater than 1.
 * @param prime1 The first prime number returned such that num = prime1 + prime2
 * @param prime2 The second prime number returned such that num = prime1 + prime2
 * @return A boolean indicating whether the a pair of prime numbers exists that summed up equal to the first parameter.
 *
 */
bool get_sum_primes(int num, int *prime1, int *prime2) {

// Implement this function

}

/*-------------------------------- Execise 1 ----------------------------*/

void exercise_1() {

    printf("\n--- Exercise 1 ---\n");

    // Read an integer between MIN_NUMBER_EX1 and MAX_NUMBER_EX1.
    int num = read_number("\n>> Enter a number between %d and %d: ", MIN_NUMBER_EX1, MAX_NUMBER_EX1);

    /* 1.1 - Binary representation */
    int bin = get_binary(num);
    printf("The binary representation of %d is %d\n", num, bin);

    /* 1.2 - Factorial */
    // Iterative version
    long long int fac_i = factorial_i(num);
    // We know that in this case the number will be valid, so the condition of this 'if' should always be true.
    if (fac_i != ERROR_NUMBER) {
        printf("FactI(%d) = %lli\n", num, fac_i);
    } else {
        printf("Error found when calculating the factorial of %d. Please make sure that you passed a natural number.\n",
               num);
    }
    // Recursive version
    long long int fac_r = factorial_r(num);
    if (fac_r != ERROR_NUMBER) {
        printf("FactR(%d) = %lli\n", num, fac_r);
    } else {
        printf("Error found when calculating the factorial of %d. Please make sure that you passed a natural number.\n",
               num);
    }

    /* 1.3 - Fibonacci */
    // Iterative version
    int fib_i = fibonacci_i(num);
    // We know that in this case the number will be valid, so the condition of this 'if' should always be true.
    if (fib_i != ERROR_NUMBER) {
        printf("FibI(%d) = %d\n", num, fib_i);
    } else {
        printf("Error found when calculating the Fibonacci number of %d. Please make sure that you passed a natural number.\n",
               num);
    }
    // Recursive version
    int fib_r = fibonacci_r(num);
    if (fib_r != ERROR_NUMBER) {
        printf("FibR(%d) = %d\n", num, fib_r);
    } else {
        printf("Error found when calculating the Fibonacci number of %d. Please make sure that you passed a natural number.\n",
               num);
    }

    /* 1.4 - Is prime? */
    printf("%d is ", num);
    if (!is_prime(num)) printf("not ");
    printf("a prime number.\n");

    /* 1.5 - Is sum of primes? */
    int prime1;
    int prime2;
    bool is_sum_primes = get_sum_primes(num, &prime1, &prime2);
    if (is_sum_primes) {
        printf("%d = %d+%d\n", num, prime1, prime2);
    } else {
        printf("%d is not the sum of two prime numbers.\n", num);
    }

}

