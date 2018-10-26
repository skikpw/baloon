//
// Created by belkar on 25.10.18.
//
#include <cstdlib>
#include <string>

#ifndef HOME_DUMMYSENSOR_H
#define HOME_DUMMYSENSOR_H

class DummySensor : public Sensor {
public:
    DummySensor();
    void measure();
    void initialise();
private:
    int value;
};

DummySensor::DummySensor() : Sensor(2.0, "DummySensor") {
    srand(3123122);
}

void DummySensor::measure(){
    value = 10 + rand()%10;
    last_value = std::to_string(value);
    notify();
}

void DummySensor::initialise(){
    ;
}
#endif //HOME_DUMMYSENSOR_H
