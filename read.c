#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MYPIN 0 
#define NUMREADINGS 20

int main (void) {
    int c,x,re[1000],med=0;
    printf ("Raspberry Pi wiringPi Capacitor reading \n") ;

    int err = wiringPiSetup();
    printf("successfully initialized wiringPi %d\n", err);
    piHiPri(99);
    for (;;) {
        for (x=0;x<NUMREADINGS;x++) {
            pinMode(MYPIN, OUTPUT);
            digitalWrite (MYPIN, LOW);
            c=0;
            pinMode (MYPIN, INPUT);
            while (digitalRead(MYPIN)==LOW) {
                c++;
            }
            re[x]=c;
        }
        med=0;    
        for (x=0;x<NUMREADINGS;x++) 
            med+=re[x];
        if (med/NUMREADINGS > 8000) {
            printf("down:");

        }
        printf("%d\n",med/NUMREADINGS);
        fflush(stdout);
        delay(10);
    }                             
}
