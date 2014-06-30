/*
    Method inspired by the arduino CapacitiveSense library as well as others
    Initial code from http://www.raspberrypi.org/forums/viewtopic.php?t=42358
*/

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MYPIN 0 
#define NUMREADINGS 20

void setup(void);
int read(void);

int main (void) {
    printf ("Raspberry Pi wiringPi Capacitor reading \n") ;
    setup();
    
    while (1) {
        printf("%d\n", read());
        fflush(stdout);
        delay(10);
    }                             
}

void setup(void) {
    wiringPiSetup();
    printf("successfully initialized wiringPi\n");
    piHiPri(99); //Try to decrease nice value
}

int read(void) {
    int i, count, sum=0;
    for (i = 0; i < NUMREADINGS; i++) {
        pinMode(MYPIN, OUTPUT);
        digitalWrite(MYPIN, LOW);
        
        count = 0;
        pinMode(MYPIN, INPUT);
        while (digitalRead(MYPIN) == LOW) {
            count++;
            if (count > 100000) {
                break; 
            }
        }
        sum += count;
    }

    return sum/NUMREADINGS;
}
