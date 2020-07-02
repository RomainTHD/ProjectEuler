#include <iostream>

// #define DEBUG
#define NB_MAX 20

/**
 * Récupère la décomposition première d'un nombre
 *
 * @param primes Tableau du nombre d'occurences d'un nombre
 * @param current_nb Nombre à évaluer
 */
void getPrimes(int primes[], int current_nb) {
    /**
     * Factorisation finie ou non
     */
    bool finished = false;

    while (!finished) {
        if (current_nb == 1) {
            // Si nb = 1 factorisation finie

#ifdef DEBUG
            std::cout << 1;
#endif

            primes[1]++;

            finished = true;
        }
        else if (current_nb % 2 == 0) {
            // Si nb pair on le divise par 2 et on continue

#ifdef DEBUG
            std::cout << "2 x ";
#endif

            primes[2]++;

            current_nb /= 2;
        }
        else {
            // Calcul de divisibilité de 3 à nb/2

            int half = (current_nb + 1) / 2;
            int divider = 3;

            bool divided = false;

            while (!divided && divider <= half) {
                if (current_nb % divider == 0) {
                    // Si divisible

#ifdef DEBUG
                    std::cout << divider << " x ";
#endif

                    primes[divider]++;

                    current_nb /= divider;
                    divided = true;
                }

                divider += 2;
            }

            if (!divided) {
                // Si aucune division, donc nombre premier

#ifdef DEBUG
                std::cout << current_nb;
#endif

                primes[current_nb]++;

                finished = true;
            }
        }
    }
}

/**
 * Le plus petit multiple de tous les nombres de 1 à 20 est le produit du max de facteurs premiers<br>
 *
 * Exemple pour 10 : on peut factoriser tous les nombres < 10 avec 2, 2, 2, 3, 3, 5 et 7,
 * donc le plus petit multiple est 2520 = 2^3 x 3^2 x 5 x 7
 */
int main() {
    int primesMax[NB_MAX+1]{0};

    for (int nb=1; nb<NB_MAX+1; nb++) {
        int primes[NB_MAX+1]{0};

        getPrimes(primes, nb);

        for (int j=0; j<NB_MAX+1; j++) {
            if (primesMax[j] < primes[j]) {
                primesMax[j] = primes[j];
            }
        }

#ifdef DEBUG
        std::cout << std::endl << i << " - ";

        for (int j=0; j<NB_MAX+1; j++) {
            int nb = primes[j];

            if (nb != 0) {
                std::cout << j << "^" << nb << " x ";
            }
        }

        std::cout << std::endl;
#endif

    }

    long res = 1;

    for (int nb=0; nb<NB_MAX+1; nb++) {
        int compt = primesMax[nb];

        for (int p=0; p<compt; p++) {
            res *= nb;

#ifdef DEBUG
            std::cout << nb << " x ";
#endif
        }
    }

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}