#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
class Observer;
//powinien byc wiirtualny (prototyp), tak samo Observer
class Subject {
// 1. "independent" functionality
    vector < class Observer * > views;
  protected:
    string value;
     // 3. Coupled only to "interface"
    // int value;
  public:
    void attach(Observer *obs);
    // void setVal(int val);
    virtual string getVal() const = 0;
    void notify();
    string GetTimeStamp();
};
#endif
