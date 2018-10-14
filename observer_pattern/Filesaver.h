#ifndef _FILESAVER_H_
#define _FILESAVER_H_
#include <iostream>
#include <vector>
#include <fstream>
#include "Observer.h"
#include "Subject.h"
using namespace std;

class FileSaver : public Observer {
  public:
    FileSaver(string path);
    void update(Subject* const x);
  private:
    //void save(string to_save);
    fstream file;
};


#endif
