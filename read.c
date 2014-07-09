/*
    Method inspired by the arduino CapacitiveSense library as well as others
    Initial code from http://www.raspberrypi.org/forums/viewtopic.php?t=42358
*/

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "read.h"
#define NUMREADINGS 20

void setup(void) {
    wiringPiSetup();
    fprintf(stderr, "successfully initialized wiringPi\n");
    piHiPri(99); //Try to decrease nice value
}

int read(int pin) {
    int i, count, sum=0;
    for (i = 0; i < NUMREADINGS; i++) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
        
        count = 0;
        pinMode(pin, INPUT);
        while (digitalRead(pin) == LOW) {
            count++;
            if (count > 100000) {
                break; 
            }
        }
        sum += count;
    }
    return sum/NUMREADINGS;
}
