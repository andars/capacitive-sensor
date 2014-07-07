/*
    Method inspired by the arduino CapacitiveSense library as well as others
    Initial code from http://www.raspberrypi.org/forums/viewtopic.php?t=42358
*/

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIN_DEFAULT 0 
#define NUMREADINGS 20

void setup(void);
int read(int pin);

int main (int argc, char* argv[]) {
    fprintf(stderr, "Raspberry Pi wiringPi Capacitor reading \n") ;
    setup();
    int count = 500;
    int pin = PIN_DEFAULT;
    if (argc > 1) {
        count = atoi(argv[1]);
    }
    
    if (argc > 2) {
        pin = atoi(argv[2]);
        fprintf(stderr,"%d\n", pin);
        
    }
    for (int i = 0; i < count; i++) {
        printf("%d\n", read(pin));
        fflush(stdout);
        delay(10);
    }                             
}

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
