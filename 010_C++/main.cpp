#include <iostream>
#include <vector>

#define NB_MAX 2000000

/**
 * Nombre premier ou non
 *
 * @param nb Nombre à évaluer
 *
 * @return Premier ou non
 */
bool isPrime(int nb) {
    bool prime = true;
    bool finished = false;

    // Si nombre pair
    if (nb % 2 == 0) {
        prime = false;
    }

    int divider = 3;

    // On va passer tous les diviseurs de 2 en 2 à partir de 3
    while (!finished && prime) {
        if (nb % divider == 0) {
            prime = false;
        }

        if (divider > nb/2) {
            finished = true;
        }

        divider += 2;
    }

    // Cas spéciaux : 1, 2 et 3 sont premiers
    if (nb > 0 && nb <= 3) {
        prime = true;
    }

    return prime;
}

/**
 * Retourne un vector de tous les nombres premiers de 2 à <code>max</code>.<br>
 * Gourmand en mémoire mais très efficace.
 *
 * @see [fr] https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne
 * @see [en] https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * @param max Borne supérieure
 * @return Nombres premiers de 2 à <code>max</code>
 */
std::vector<long> eratosthenes(long max) {
    std::vector<bool> primeTab(max, true);
    std::vector<long> res;

    for (size_t i=1; i<max; i++) {
        if (primeTab[i]) {
            res.push_back(i+1);

            for (size_t j=i; j<max; j+=i+1) {
                primeTab[j] = false;
            }
        }
    }

    return res;
}

/**
 * Méthode naïve, brute-force
 *
 * @return Somme
 */
unsigned long long naive() {
    unsigned long long int sum = 2;

    for (int i=3; i<NB_MAX; i+=2) {
        if (isPrime(i)) {
            sum += i;
        }

        /*
        if (i % 100000 == 1) {
            std::cout << i << std::endl;
        }
        */
    }

    return sum;
}

/**
 * Méthode plus rapide et intelligente que la méthode naïve.<br>
 * Pour aller plus loin il faudrait utiliser le crible d'Atkin
 *
 * @see https://en.wikipedia.org/wiki/Sieve_of_Atkin
 * @return Somme
 */
unsigned long long smart() {
    std::vector<long> prime = eratosthenes(NB_MAX);

    unsigned long long int sum = 0;

    for (long i : prime) {
        sum += i;
    }

    return sum;
}

int main() {
    std::cout << smart() << std::endl;

    return EXIT_SUCCESS;
}