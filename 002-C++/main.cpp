#include <iostream>

long fibo(long n1, long n2, long max, long acc) {
    const long nb = n1 + n2;

    if (nb % 2 == 0) {
        return fibo(n2, nb, max, acc + nb);
    }
    else if (nb < max) {
        return fibo(n2, nb, max, acc);
    }
    else {
        return acc;
    }
}

int main() {
    std::cout << fibo(1, 2, 4000000, 2) << std::endl;

    return EXIT_SUCCESS;
}
