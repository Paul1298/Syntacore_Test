#include "Accumulation.h"

Accumulation::Accumulation(int32_t sample_num) : sample_num(sample_num) {}

void Accumulation::push(const complex16 &value) {
    queue<complex16 >::push(value);
    sum += value;

    if (this->size() == this->sample_num) {
        isAverageReady = true;
    } else if (this->size() > this->sample_num) {
        sum -= this->front();
        this->c.pop_front();
    }
}

complex16 Accumulation::getAverage() const {
    return sum / sample_num;
}
