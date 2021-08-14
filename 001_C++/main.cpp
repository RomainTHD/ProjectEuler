#include <iostream>

#define NB_MAX 1000
#define MULTIPLES {3, 5}

/**
 * Somme par itération
 *
 * @return Somme des nb mod 3 ou mod 5
 */
int sumIter() {
    int multiples[] MULTIPLES;
    int nbMultiples = sizeof(multiples) / sizeof(multiples[0]);

    int sum = 0;

    for (int i=1; i<NB_MAX; i++) {
        bool ok = false;

        for (int j=0; j<nbMultiples && !ok; j++) {
            int mult = multiples[j];

            if (mult <= i && i % mult == 0) {
                ok = true;
            }
        }

        if (ok) {
            sum += i;
        }
    }

    return sum;
}

/**
 * Somme par récursion
 *
 * @param nb Nombre initial
 * @param acc Accumulateur
 *
 * @return Somme des nb mod 3 ou mod 5
 */
int sumRec(int nb, int acc) {
    nb--;
    // Évite de compter 1000

    if (nb % 3 == 0 || nb % 5 == 0) {
        return sumRec(nb, acc + nb);
    }
    else if (nb > 0) {
        return sumRec(nb, acc);
    }
    else {
        return acc;
        // Optimisation par la queue, le compilateur n'a plus besoin de nb et acc donc peut free les var
        // avant d'entrer dans la récursion suivante
    }
}

int main() {
    std::cout << sumIter() << std::endl;
    std::cout << sumRec(NB_MAX, 0) << std::endl;

    return EXIT_SUCCESS;
}