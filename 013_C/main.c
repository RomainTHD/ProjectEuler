#include <stdio.h>
#include <stdint.h>

#define NB_ROWS 100
#define NB_DIGITS 50
#define BUFFER_DIGITS 2

char numbers[NB_ROWS][NB_DIGITS+1];
char final[NB_DIGITS + BUFFER_DIGITS];

int main() {
    FILE* f;
    f = fopen("./numbers.txt", "r");

    for (int i = 0; i < NB_ROWS; i++) {
        fgets(numbers[i], NB_DIGITS+1, f);
        if (fgetc(f) == '\r')
            fgetc(f);
    }

    uint16_t sum = 0;

    for (int j = 0; j < NB_DIGITS; ++j) {
        for (int i = 0; i < NB_ROWS; ++i) {
            sum += numbers[i][NB_DIGITS - j - 1] - '0';
        }

        final[j] = (char) ((sum % 10) + '0');
        sum /= 10;
    }

    for (int i = 0; i < BUFFER_DIGITS; ++i) {
        final[NB_DIGITS + i] = (char) ((sum % 10) + '0');
        sum /= 10;
    }

    for (int i = 0; i < 10; i++)
        printf("%c", final[NB_DIGITS + BUFFER_DIGITS - i - 1]);

    printf("\n");

    return 0;
}
