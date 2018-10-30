
#include <stdio.h>
#include <cstdlib>
//#include <pthready.h>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <sys/time.h>
#define NUM_THREADS     2

volatile int ready = 0;
volatile int rising = 0;
volatile suseconds_t rise = 0;
volatile suseconds_t fall = 0;
volatile suseconds_t lrise = 0;

//void* interrupt_monitor(void* param) {
//    while(1) {
//        if(waitForInterrupt(25,-1) >0){
//            flag = 1;
//        }
//    }
//}

void myInterrupt(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (rising) {
        lrise = rise;
	rise = tv.tv_usec;
	rising = !rising;
        ready = 1;
    } else {
	rising = !rising;
        fall = tv.tv_usec;
    }
}

int main (void)
{
    printf ("Raspberry Pi interrupt\n") ;
    if (wiringPiSetup () == -1)
        return 1 ;

    const int PWM_PIN = 1;
    const int INTERRUPT_PIN = 25;
    //pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17 https://github.com/WiringPi/WiringPi/blob/master/examples/wfi.c
    pinMode (INTERRUPT_PIN, INPUT);    // aka BCM  GPIO pin 26 , physical 37 https://pinout.xyz/pinout/pin37_gpio26#
    pinMode (PWM_PIN, OUTPUT); // pin BCM 18/ pin PWM1, physical 12

    softPwmCreate(PWM_PIN, 1, 100);
    softPwmWrite(PWM_PIN, 30);
//    pthready_t watek;
//    if (pthready_create(&watek, NULL, interrupt_monitor, 0))
//        printf("Error creating a thready.\n");

    if ( wiringPiISR (INTERRUPT_PIN, INT_EDGE_BOTH, &myInterrupt) < 0 ) {
        printf ("Unable to setup ISR: %s\n", strerror (errno));
        return 1;
    }
int licznik=0;
    while(1) {
        if(ready == 1) {
            ready = 0;
            printf("Odczytalem %d: od %d przez %d do %d high: %d low: %d, suma: %d\n",
                   licznik++, lrise, fall, rise, fall-lrise, rise-fall, rise-lrise);
        }
        //usleep(10000);
    }

    return 0;
}
