#include <stdio.h>
#include <stdbool.h>

unsigned long long iterative_factorial(unsigned int n) {
    unsigned long long acc = 1;
    for (int i = 1; i <= n; i++)
        acc *= i;
    return acc;
}

unsigned long long recursive_factorial(unsigned int n, unsigned long long acc) {
    if (n <= 1)
        return acc;
    else
        return recursive_factorial(n-1, n*acc);
}

unsigned int get_input() {
    int n;
    printf("Insert n: ");
    scanf("%u", &n);
    return n;
}

void print_factorial(int n, unsigned long long acc) {
    printf("factorial(%u)=%llu\n", n, acc);
    return;
}

int main() {
    unsigned int n;
    unsigned long long fac_n;
    unsigned int tmp;
    bool isRecursivelyComputed;

    printf("Choose method of computation of factorial \
            \ninput == 0    - Iterative \
            \ninput != 0    - Recursive \
            \nWaiting for input: ");
    scanf("%u", &tmp);
    isRecursivelyComputed = tmp;

    n = get_input();
    fac_n = (isRecursivelyComputed)? iterative_factorial(n) : recursive_factorial(n, 1);

    print_factorial(n, fac_n);
    return 0;
}
