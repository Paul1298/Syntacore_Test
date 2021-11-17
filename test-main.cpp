#include <iostream>
#include <string>
#include <fstream>
#include "Accumulation.h"

// todo ask Andrew about sample_num
int main(int argc, char *argv[]) {
    const char *input_filename = argv[1];
    freopen(input_filename, "r", stdin);

    const char *output_filename = argv[2];
    std::ifstream output(output_filename);

    int32_t sample_num;
    std::cin >> sample_num;

    Accumulation complexes(sample_num);
//    complexes.size();

    while (!feof(stdin)) {
        int16_t real, imag;
        std::cin >> imag >> real;
        complexes.push(complex16(imag, real)); // reversed
        if (complexes.isAverageReady()) {
            std::string expected; std::getline(output, expected);

            std::stringstream buf;
            buf << complexes.getAverage();
            std::string actual = buf.str();

            if (actual != expected) {
                std::cout << "TestFailed";
                return EXIT_FAILURE;
            }
        }
    }
    std::cout << "TestPassed";

    fclose(stdin);
    return EXIT_SUCCESS;
}
