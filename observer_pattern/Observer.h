#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <iostream>
#include <vector>
using namespace std;
class Subject;

class Observer {
    // 2. "dependent" functionality

  public:
    Observer();
    virtual void update(Subject* const x) = 0;
    void registerSubject(Subject* sb);
};
#endif
