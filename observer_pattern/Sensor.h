//
// Created by belkar on 25.10.18.yyyyyyy
//

#ifndef HOME_SENSOR_H
#define HOME_SENSOR_H

//#include "Subject.h"
#include "Observer.h"
#include <sys/time.h>
#include <ctime>
#include <string>

class Sensor {
public:
    Sensor(double frequency, std::string n);
    std::string get_time_stamp();
    std::string get_last_value();
    const std::string name;
    void set_measure_frequency(double freq);
    virtual void measure() = 0;
    virtual void initialise() = 0;
//    bool time_to_measure();
public:
    void attach(Observer *obs);
    virtual void notify();
protected:
    std::string last_value;
    double measure_frequency;
    long measure_sec_interval;
    long measure_usec_interval;
    struct timeval last_measure;
private:
    vector < class Observer * > views;
};

Sensor::Sensor(double mes_freq=1.0, std::string n="unnamed_sensor") : name(n) {
    gettimeofday(&last_measure, NULL);
    set_measure_frequency(mes_freq);
}

void Sensor::set_measure_frequency(double freq) {
//    if(freq == 0.0) // taki hack tymczasowy
//        freq = 0.000000000001;
    measure_usec_interval = 1000000.0/freq;
    measure_sec_interval = 1.0/freq;
    measure_frequency = freq;
}

void Sensor::attach(Observer *obs) {
  views.push_back(obs);
}


void Sensor::notify() {
    // 5. Publisher broadcasts
    for (auto it = views.begin(); it != views.end(); it++)
        (*it)->update(this);
}
//bool Sensor::time_to_measure() {
//    return last_measure.tv_sec >
//
//}


std::string Sensor::get_last_value() {
    return last_value;
}

std::string Sensor::get_time_stamp(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    std::string s = std::to_string(tv.tv_sec) + ";" + std::to_string(tv.tv_usec);
    return s;
}

#endif //HOME_SENSOR_H
