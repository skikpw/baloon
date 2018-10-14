#include <iostream>
#include <vector>
#include "FileSaver.h"
#include "CarbonDioxideSensor.h"
using namespace std;

int main() {
  FileSaver fs("./log.txt");
  CarbonDioxideSensor s1;
  fs.registerSubject(&s1);
  while(1) {
    s1.checkValue();
  }
}
