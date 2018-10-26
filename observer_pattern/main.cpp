#include <iostream>
#include <vector>
//#include "FileSaver.h"
#include "Sensor.h"
#include "CoutSaver.h"
#include "DummySensor.h"
//#include "CarbonDioxideSensor.h"
#include <unistd.h>
using namespace std;


int main() {
//  Fi
// leSaver fs("./log.txt");
  CoutSaver cs;
  DummySensor ds;
  std::vector<Sensor*> sensors;
  sensors.push_back(&ds);
  ds.attach(&cs);
//  CarbonDioxideSensor s1;
//  fs.registerSubject(&s1);
  int i =0;
  while(true) {
    std::cout << "Petla : " << i << std::endl;
    for (auto sensor : sensors) {
      // sprawdz czy pora na pomiar
      sensor->measure();

      usleep(500000);
    }
    ++i;
  }
}
