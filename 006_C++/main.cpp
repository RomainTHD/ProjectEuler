#include <iostream>

#define NB_MAX 100

int main() {
    /**
     * Somme des carrés
     */
    long sumSq = 0;

    for (int i=1; i<=NB_MAX; i++) {
        sumSq += i*i;
    }

    /**
     * Somme de 1 à 10 = 55 = 11 * 5 = (10 + 1) * (10 / 2)
     */
    long sum = (NB_MAX + 1) * (NB_MAX / 2);

    /**
     * Carré de la somme
     */
    long sqSum = sum * sum;

    std::cout << (sqSum - sumSq) << std::endl;

    return EXIT_SUCCESS;
}
