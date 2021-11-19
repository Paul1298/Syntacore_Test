#include "Accumulation.h"


void Accumulation::push(const complex16 &value) {
    sum += value;

    if (size() == capacity) {
        isReady = true;
        samples[head] = value;
        sum -= pop();
    } else if (size() < capacity) {
        samples[tail] = value;
        tail = (tail + 1) % capacity;
    }
}

complex16 Accumulation::pop() {
    complex16 x = samples[head];
    head = (head + 1) % capacity;
    return x;
}

complex16 Accumulation::getAverage() const {
    return sum / sampleNum;
}
