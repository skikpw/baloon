#include <iostream>
#include <cstring>
#include <string>
#include <wiringPi.h>

#define _BSD_SOURCE
using namespace std;

const int PWM=2;


void init()
{
  wiringPiSetup();
  pinMode(PWM, INPUT);
}


// slaba funkcja - trzeba ja przerobic
string CarbonDioxideSensor::getVal() const
{
  return GetTimeStamp() + " " + value;
}

void CarbonDioxideSensor::checkValue() {
	//wait for PWM start
	//cout << "Waiting for LOW:\n";
	while (digitalRead(PWM)== LOW);
	//wait for PWM end
	long startTime = micros();
	//cout << "Waiting for HIGH:\n";
	while (digitalRead(PWM) == HIGH);
	long duration = micros() - startTime;
	//from datasheet
	//CO2 ppm = 5000 * (Th - 2ms) / (Th + Tl - 4ms)
	//  given Tl + Th = 1004
	//        Tl = 1004 - Th
	//        = 5000 * (Th - 2ms) / (Th + 1004 - Th -4ms)
	//        = 5000 * (Th - 2ms) / 1000 = 2 * (Th - 2ms)
  value = to_string( 5 * ((duration/1000) - 2));
  notify();
}

CarbonDioxideSensor::CarbonDioxideSensor(){
  init();
}
