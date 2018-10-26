#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <iostream>
#include <vector>
using namespace std;
class Sensor;

class Observer {
    // 2. "dependent" functionality

  public:
//    void registerSubject(Subject* sb);
    virtual void update(Sensor* x) =0;
    Observer();
};
#endif
