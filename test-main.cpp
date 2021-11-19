#include <iostream>
#include <string>
#include <fstream>
#include "Accumulation.h"

int main(int argc, char *argv[]) {
    const char *input_filename = argv[1];
    freopen(input_filename, "r", stdin);

    const char *output_filename = argv[2];
    std::ifstream output(output_filename);

    Accumulation complexes(2);

    while (!feof(stdin)) {
        int16_t real, imag;
        std::cin >> imag >> real;
        complexes.push(complex16(imag, real)); // reversed
        if (complexes.isAverageReady()) {
            std::string expected;
            std::getline(output, expected);

            std::stringstream buf;
            buf << complexes.getAverage();
            std::string actual = buf.str();

            if (actual != expected) {
                std::cout << "TestFailed";
                return EXIT_FAILURE;
            }
        }
    }
    if (output.eof()) std::cout << "TestPassed";
    else std::cout << "TestFailed";

    fclose(stdin);
    return EXIT_SUCCESS;
}
