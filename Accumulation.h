#ifndef SYNTACORE_TEST_ACCUMULATION_H
#define SYNTACORE_TEST_ACCUMULATION_H

#include <queue>
#include <cstdint>
#include <complex>

#define complex16 std::complex<int16_t>


/**
 * Fixed-size queue container.
 *
 * @sample_num Accumulation interval (number of samples).
 * @sum Sum of container values.
 * @isAverageReady Average ready flag.
 */
class Accumulation : public std::queue<complex16 > {
public:
    explicit Accumulation(int32_t sample_num);

    int32_t sample_num;
    std::complex<int32_t> sum = 0;
    bool isAverageReady = false;

    void push(const complex16 &value);

    complex16 getAverage() const;
};


#endif //SYNTACORE_TEST_ACCUMULATION_H
