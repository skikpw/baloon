//
// Created by belkar on 25.10.18.
//

#ifndef HOME_COUTSAVER_H
#define HOME_COUTSAVER_H

#include "Observer.h"
#include "Sensor.h"
#include <iostream>

class CoutSaver : public Observer {
public:
    CoutSaver();
    void update(Sensor* x);
private:
    //void save(string to_save);
};

CoutSaver::CoutSaver() {

}

void CoutSaver::update(Sensor *x) {
    std::cout << (x)->get_time_stamp() << " " << (x)->get_last_value() << std::endl;
}

#endif //HOME_COUTSAVER_H
