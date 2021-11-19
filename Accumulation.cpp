#include "Accumulation.h"


void Accumulation::push(const complex16 &value) {
    sum += value;

    if (size() != capacity) {
        samples[tail] = value;
    } else {
        sum -= samples[head];
        samples[head] = value;
        head = (head + 1) % (capacity + 1);
    }
    tail = (tail + 1) % (capacity + 1);

}

complex16 Accumulation::getAverage() const {
    return sum / capacity;
}
