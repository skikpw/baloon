/*
 * blink.c:
 *      blinks the first LED
 *      Gordon Henderson, projects@drogon.net
 */
 
#include <stdio.h>
#include <wiringPi.h>
 
int main (void)
{
  printf ("Raspberry Pi blink\n") ;
 
  if (wiringPiSetup () == -1)
    return 1 ;
 
  pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17
 
  for (;;)
  {
    int i=rand()%100+10;
    digitalWrite (0, 1) ;       // On
    delay (3*i) ;               // mS
    digitalWrite (0, 0) ;       // Off
    delay (i*2) ;
  }
  return 0 ;
}
