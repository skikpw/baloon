
#include <stdio.h>
#include <cstdlib>
//#include <pthread.h>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <wiringPi.h>
#define NUM_THREADS     2

volatile int flag = 0;

//void* interrupt_monitor(void* param) {
//    while(1) {
//        if(waitForInterrupt(25,-1) >0){
//            flag = 1;
//        }
//    }
//}

void myInterrupt(void) {
    flag = 1;
}



int main (void)
{
    printf ("Raspberry Pi interrupt\n") ;
    if (wiringPiSetup () == -1)
        return 1 ;

    //pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17 https://github.com/WiringPi/WiringPi/blob/master/examples/wfi.c
    pinMode (25, INPUT);    // aka BCM  GPIO pin 26 , physical 37 https://pinout.xyz/pinout/pin37_gpio26#
//
//    pthread_t watek;
//    if (pthread_create(&watek, NULL, interrupt_monitor, 0))
//        printf("Error creating a thread.\n");

    if ( wiringPiISR (25, INT_EDGE_BOTH, &myInterrupt) < 0 ) {
        printf ("Unable to setup ISR: %s\n", strerror (errno));
        return 1;
    }
int licznik=0;
    while(1) {
        if(flag == 1) {
            flag = 0;
            usleep(10000);
            printf("Odczytalem %d \n", licznik++);
        }
        usleep(10000);
    }

    return 0;
}
