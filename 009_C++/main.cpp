#include <iostream>

#define NB_MAX 1000

int main() {
    for (int a=1; a<NB_MAX; a++) {
        for (int b=a+1; b<NB_MAX; b++) {
            for (int c=b+1; c<NB_MAX; c++) {
                if (a*a + b*b == c*c) {
                    if (a + b + c == NB_MAX) {
                        std::cout << a << "^2 + " << b << "^2 = " << c << "^2, abc = " << a*b*c << std::endl;
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
