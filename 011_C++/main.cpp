#include <iostream>
#include <vector>
#include <fstream>

#define ADJACENT_NUMBERS 4

/**
 * Lit le fichier contenant les chiffres et le transforme en vector 2D
 *
 * @param path Chemin du fichier
 * @throws length_error Si les lignes ne sont pas de même longueur
 * @throws failure Si le fichier n'existe pas
 * @return Vector 2d
 */
std::vector<std::vector<int>> readFromFile(const std::string& path) {
    std::vector<std::vector<int>> res;

    /**
     * Nombre observé
     */
    int number = 0;

    /**
     * Évite d'ajouter un 0 en cas de double espace ou de \r par exemple
     */
    int numberCount = 0;

    /**
     * Vector courant
     */
    std::vector<int> currentVect;

    /**
     * Vérifie que la taille des lignes soit identique
     */
    int vectSize = -1;

    /**
     * Caractère courant
     */
    char ch;

    /**
     * Stream de lecture
     */
    std::fstream istream(path, std::fstream::in);

    if (istream.is_open()) {
        while (istream >> std::noskipws >> ch) {
            if (ch >= '0' && ch <= '9') {
                number *= 10;
                number += static_cast<int>(ch - '0');
                numberCount++;
            }
            else if (ch == '\n') {
                if (vectSize == -1) {
                    vectSize = currentVect.size();
                }
                else if (vectSize != currentVect.size()) {
                    throw std::length_error("Different vector size");
                }

                res.push_back(currentVect);
                currentVect = std::vector<int>();
            }
            else {
                if (numberCount != 0) {
                    currentVect.push_back(number);
                    number = 0;
                    numberCount = 0;
                }
            }
        }
    }
    else {
        throw std::ios_base::failure("File does not exist");
    }

    return res;
}

/**
 * Calcule le produit de la diagonale descendante gauche
 *
 * @param array Tableau
 * @param row Ligne
 * @param col Colonne
 *
 * @return Produit si position valide, -1 sinon
 */
long long getLeftDiagonal(const std::vector<std::vector<int>>& array, int row, int col) {
    long long nb = -1;

    if (row <= array.size() - ADJACENT_NUMBERS && col >= ADJACENT_NUMBERS-1) {
        nb = 1;

        for (int i = 0; i < ADJACENT_NUMBERS; i++) {
            nb *= array.at(row + i).at(col - i);
        }
    }

    return nb;
}

/**
 * Calcule le produit de la verticale descendante
 *
 * @param array Tableau
 * @param row Ligne
 * @param col Colonne
 *
 * @return Produit si position valide, -1 sinon
 */
long long getVertical(const std::vector<std::vector<int>>& array, int row, int col) {
    long long nb = -1;

    if (row <= array.size() - ADJACENT_NUMBERS) {
        nb = 1;

        for (int i = 0; i < ADJACENT_NUMBERS; i++) {
            nb *= array.at(row + i).at(col);
        }
    }

    return nb;
}

/**
 * Calcule le produit de la diagonale descendante droite
 *
 * @param array Tableau
 * @param row Ligne
 * @param col Colonne
 *
 * @return Produit si position valide, -1 sinon
 */
long long getRightDiagonal(const std::vector<std::vector<int>>& array, int row, int col) {
    long long nb = -1;

    if (row <= array.size() - ADJACENT_NUMBERS && col <= array.at(row).size() - ADJACENT_NUMBERS) {
        nb = 1;

        for (int i = 0; i < ADJACENT_NUMBERS; i++) {
            nb *= array.at(row + i).at(col + i);
        }
    }

    return nb;
}

/**
 * Calcule le produit de l'horizontale gauche
 *
 * @param array Tableau
 * @param row Ligne
 * @param col Colonne
 *
 * @return Produit si position valide, -1 sinon
 */
long long getHorizontal(const std::vector<std::vector<int>>& array, int row, int col) {
    long long nb = -1;

    if (col <= array.at(row).size() - ADJACENT_NUMBERS) {
        nb = 1;

        for (int i = 0; i < ADJACENT_NUMBERS; i++) {
            nb *= array.at(row).at(col + i);
        }
    }

    return nb;
}

/**
 * Calcule le maximum pour toute suite de n chiffres
 *
 * @param array Tableau
 *
 * @return Maximum
 */
long long getMax(const std::vector<std::vector<int>>& array) {
    long long max = 0;

    for (int row = 0; row < array.size(); row++) {
        for (int col = 0; col < array.at(row).size(); col++) {
            long long nb;

            nb = getLeftDiagonal(array, row, col);
            if (nb >= max) {
                max = nb;
                std::cout << '(' << row << ',' << col << ") ld : " << nb << std::endl;
            }

            nb = getVertical(array, row, col);
            if (nb >= max) {
                max = nb;
                std::cout << '(' << row << ',' << col << ") v : " << nb << std::endl;
            }

            nb = getRightDiagonal(array, row, col);
            if (nb >= max) {
                max = nb;
                std::cout << '(' << row << ',' << col << ") rd : " << nb << std::endl;
            }

            nb = getHorizontal(array, row, col);
            if (nb >= max) {
                max = nb;
                std::cout << '(' << row << ',' << col << ") h : " << nb << std::endl;
            }
        }
    }

    return max;
}

/**
 * Main
 *
 * @return Code d'erreur
 */
int main() {
    std::vector<std::vector<int>> array = readFromFile("grid.txt");
    long long max = getMax(array);

    std::cout << max << std::endl;

    return EXIT_SUCCESS;
}
