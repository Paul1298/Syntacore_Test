#ifndef SYNTACORE_TEST_ACCUMULATION_H
#define SYNTACORE_TEST_ACCUMULATION_H

#include <queue>
#include <cstdint>
#include <complex>
#include <array>

using complex16 = std::complex<int16_t>;
constexpr int sampleNum = 128; // Accumulation capacity


/**
 * Fixed-size fifo container used array.
 *
 * @sample_num Accumulation interval (number of samples).
 * @sum Sum of container values.
 * @isAverageReady Average ready flag.
 */
class Accumulation {
public:
    explicit Accumulation(size_t capacity = sampleNum) : capacity(capacity) {};

    void push(const complex16 &value);

    complex16 getAverage() const;

    bool isAverageReady() const { return isReady; };

    size_t size() const {
        return (head > tail) ? (capacity - head + tail) : (tail - head);
    }

private:
    std::array<complex16 , sampleNum> samples{};
    size_t capacity;
    size_t head = 0, tail = 0;

    std::complex<int32_t> sum = 0;
    bool isReady = false;

    complex16 pop();
};


#endif //SYNTACORE_TEST_ACCUMULATION_H
