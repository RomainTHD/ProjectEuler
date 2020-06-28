#include <iostream>

#define NUMBER 600851475143

/**
 * Factorisation première d'un nombre
 */
int main() {
    /**
     * Nombre actuel
     */
    long long current_nb = NUMBER;

    /**
     * Nombre premier max
     */
    long long largestPrime = 1;

    /**
     * Factorisation finie ou non
     */
    bool finished = false;

    while (!finished) {
        if (current_nb == 1) {
            // Si nb = 1 factorisation finie

            std::cout << 1;

            finished = true;
        }
        else if (current_nb % 2 == 0) {
            // Si nb pair on le divise par 2 et on continue

            std::cout << "2 x ";

            current_nb /= 2;

            if (largestPrime == 1) {
                largestPrime = 2;
            }
        }
        else {
            // Calcul de divisibilité de 3 à nb/2

            long long half = (current_nb + 1) / 2;
            long long divider = 3;

            bool divided = false;

            while (!divided && divider <= half) {
                if (current_nb % divider == 0) {
                    // Si divisible

                    std::cout << divider << " x ";

                    if (largestPrime < divider) {
                        largestPrime = divider;
                    }

                    current_nb /= divider;
                    divided = true;
                }

                divider += 2;
            }

            if (!divided) {
                // Si aucune division, donc nombre premier

                std::cout << current_nb;

                if (largestPrime < current_nb) {
                    largestPrime = current_nb;
                }

                finished = true;
            }
        }
    }

    std::cout << std::endl << "Largest prime : " << largestPrime << std::endl;

    return EXIT_SUCCESS;
}
