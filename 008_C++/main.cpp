#include <iostream>
#include <fstream>

/**
 * Nombre de caractères consécutifs
 */
#define NB_CHARS 13

int main() {
    /**
     * Fichier de lecture
     */
    std::ifstream file ("numbers.txt");

    /**
     * Combinaison actuelle
     */
    char combin[NB_CHARS];

    /**
     * Combinaison max
     */
    char combinMax[NB_CHARS];

    // Vérification dans le dossier .. pour le fichier, pour que ça marche chez moi
    if (!file.is_open()) {
        file = std::ifstream("../numbers.txt");
    }

    if (file.is_open()) {
        /**
         * Caractère courant
         */
        char c;

        /**
         * Position actuelle
         */
        std::streampos pos = file.tellg();

        /**
         * Max
         */
        long max = -1;

        /**
         * Produit, accumulateur
         */
        long product = 1;

        /**
         * Nombre de chiffres passés dans le produit
         */
        int compt = 0;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        while (file.get(c)) {
            // Si 0 on skip tout
            if (c == '0') {
                pos = file.tellg();
                compt = 0;
                product = 1;
            }
            else if (c >= '1' && c <= '9') {
                product *= (c - '0');

                combin[compt] = c;

                compt++;

                if (compt == NB_CHARS) {
                    if (product >= max) {
                        max = product;

                        for (int i=0; i<NB_CHARS; i++) {
                            combinMax[i] = combin[i];
                        }
                    }

                    compt = 0;
                    product = 1;

                    // On revient à la position + 1
                    file.seekg(pos + std::streampos(1));
                    pos = file.tellg();
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        for (int i=0; i<NB_CHARS; i++) {
            std::cout << combinMax[i];

            if (i == NB_CHARS-1) {
                std::cout << " = " << max << std::endl;
            }
            else {
                std::cout << " x ";
            }
        }
    }
    else {
        std::cerr << "File not found" << std::endl;
    }

    return EXIT_SUCCESS;
}
