#include <iostream>
#include <string>
#include <complex>
#include "Accumulation.h"

// todo ask Andrew about sample_num
int main(/*int argc, char *argv[]*/) {
    freopen("input.txt", "r", stdin);
    int32_t sample_num;
    std::cin >> sample_num;

    Accumulation complexes(sample_num);

    while (!feof(stdin)) {
        int16_t real, imag;
        std::cin >> imag >> real;
        complexes.push(complex16(imag, real)); // reversed
        if (complexes.isAverageReady) std::cout << complexes.getAverage() << std::endl;
    }

    fclose(stdin);
    return 0;
}
