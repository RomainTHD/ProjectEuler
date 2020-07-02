#include <iostream>

#define PRIME_MAX 10001

bool isPrime(long nb) {
    bool prime = true;
    bool finished = false;

    if (nb % 2 == 0) {
        prime = false;
    }

    long divider = 3;

    while (!finished && prime) {
        if (nb % divider == 0) {
            prime = false;
        }

        if (divider > nb/2) {
            finished = true;
        }

        divider += 2;
    }

    if (nb > 0 && nb <= 3) {
        prime = true;
    }

    return prime;
}


int main() {
    int primeCount = 1;
    long nb = 3;

    std::cout << "0 : " << 2 << std::endl;

    while (primeCount < PRIME_MAX) {
        if (isPrime(nb)) {
            // std::cout << primeCount << " : " << nb << std::endl;

            primeCount++;
        }

        nb += 2;
    }

    return EXIT_SUCCESS;
}
