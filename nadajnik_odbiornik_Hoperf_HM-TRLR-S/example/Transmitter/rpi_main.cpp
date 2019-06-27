/**
 * @Author: Michał Kocon
 * @Date:   10-01-2017
 * @Filename: main.cpp
 * @Last modified by:   Michał Kocon
 * @Last modified time: 11-01-2017
 */


#include "wiringPi.h"
#include "wiringSerial.h"
#include "hoperf.hpp"
#include "hoperf_pi_driver.hpp"
#include <errno.h>

#define UART_TX1 15
#define UART_RX1 16
#define HCONFIG 0
#define HSLEEP 1
#define HSTATUS 2
#define HRESET 3
extern int errno;
//Treated as main
int main()
{
  pinMode(UART_TX1, OUTPUT);
  pinMode(UART_RX1, INPUT);

  int fd;
  if((fd = serialOpen("/dev/ttyAMA0", 115200)) < 0) {
    perror("Error with opening uart");
    //     printf("Error uart");
  }
  else
  serialClose(fd);
  skik::hoperf::ArduinoDriver drv("/dev/ttyAMA0", HCONFIG, HSLEEP, HSTATUS, HRESET);

  skik::hoperf::Command c;
  skik::hoperf::RadioModule radio(drv, 9600);

  radio.writeCommand(c.kBaudRate, "9"); // Baudrate
  radio.driver.setUartBaudRate(115200);
  radio.writeCommand(c.kModulation, "2"); // FSK
  const int N = 1<<14;
  char tab[N];
  char buf[128];
 
 for(int i=0;i<N; i++) {
    tab[i] = 'd';
  }
  tab[(N)-1] = '\0';
  int count = 0;  
  radio.writeCommand("MODE", "?");
  radio.readData(buf, 128);
  printf("Odczytano modulacje: %s\n", buf);
  radio.writeCommand("SPR", "?");
  radio.readData(buf, 128);
  printf("Odczytano baudrate: %s\n", buf);
  while(1) {
	  printf("Write attempt... %d\n", count++);
	  radio.writeData(tab); // za czesto - psuje
	  //    delay(5);
  }
}
