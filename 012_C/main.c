#include <stdio.h>
#include <malloc.h>

#define NB_DIVISORS 50

typedef unsigned long long int bigInt;

bigInt getNthNumber(bigInt n) {
    return (n*(n+1))/2;
}

int getNbOfDividers(int* array, bigInt n) {
    if (array[n] == 0) {
        // On prend en compte 1 et n
        int nb = (n == 1) ? 1 : 2;

        for (int i=2; i<=n/2; i++) {
            if (n % i == 0) {
                nb++;
            }
        }

        array[n] = nb;
    }

    return array[n];
}

int main() {
    bigInt n = 0;
    int nb;

    unsigned int size = 1;
    int* array = malloc(sizeof(int) * size);
    array[0] = 0;

    do {
        n++;
        bigInt nth = getNthNumber(n);

        if (size <= nth) {
            unsigned int oldSize = size;
            size = nth + 1;
            array = realloc(array, sizeof(int) * size);

            for (unsigned int i=oldSize; i<size; i++) {
                array[i] = 0;
            }
        }

        nb = getNbOfDividers(array, nth);
    }
    while (nb < NB_DIVISORS);

    printf("%llu: %d div\n", n, nb);


    for (unsigned int i=0; i<100; i++) {
        printf("%d:%d ", getNthNumber(i), array[getNthNumber(i)]);
    }

    return 0;
}

// https://www.mathblog.dk/triangle-number-with-more-than-500-divisors/
// https://www.xarg.org/puzzle/project-euler/problem-12/
// https://www.xarg.org/2016/06/calculate-the-sum-of-divisors/
// https://www.lucaswillems.com/fr/articles/38/project-euler-12-solution-python
