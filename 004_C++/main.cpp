#include <iostream>
#include <string>

#define MAX 1000

/**
 * Si un nombre est un palindrome ou non<br>
 * Exemple : 9119 ou 525 sont des palindromes
 * @param nb Nombre
 * @return Palindrome ou non
 */
bool isPalindrome(unsigned int nb) {
    std::string str = std::to_string(nb);

    bool ok = true;

    int i = 0;

    while (i <= str.length()/2 && ok) {
        if (str[i] != str[str.length()-i-1]) {
            ok = false;
        }

        i++;
    }

    return ok;
}

/**
 * <code>i</code> va aller de <code>MAX-1</code> à <code>1</code>,
 * <code>j</code> de <code>MAX-1</code> à <code>i</code>,
 * et on teste si le produit est un palindrome
 */
void v1() {
    unsigned int max = 0;
    unsigned long long nbIter = 0;

    unsigned int left = 0, right = 0;

    for (unsigned int i = MAX-1; i >= 1; i--) {
        for (unsigned int j = MAX-1; j >= i; j--) {
            nbIter++;

            if (isPalindrome(i*j) && i*j > max) {
                // std::cout << i << " x " << j << std::endl;
                max = i*j;
                left = i;
                right = j;
            }
        }
    }

    std::cout << left << " x " << right << " = " << max << std::endl << "iter : " << nbIter << std::endl;
}

/**
 * Comme v1, mais une limite est fixée.
 * En effet, si l'on a un palindrome à <code>80 x 90</code>, pas besoin de chercher en dessous de 70,
 * puisque aucun produit ne sera supérieur<br>
 * Pour des nombres à 3 chiffres, on économise 99.1% d'opérations (499500 vs 4465)
 */
void v2() {
    unsigned int max = 0;
    unsigned int top = 0;
    unsigned long long nbIter = 0;

    unsigned int left = 0, right = 0;

    for (unsigned int i = MAX-1; i >= 1 && i >= top; i--) {
        for (unsigned int j = MAX-1; j >= i; j--) {
            nbIter++;

            if (isPalindrome(i*j) && i*j > max) {
                // std::cout << i << " x " << j << std::endl;
                max = i*j;
                top = i - (MAX - j);
                left = i;
                right = j;
            }
        }
    }

    std::cout << left << " x " << right << " = " << max << std::endl << "iter : " << nbIter << std::endl;
}

int main() {
    v1();
    v2();

    return EXIT_SUCCESS;
}
