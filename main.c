#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


#include "read.h"

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
        
    }
    fprintf(stderr, "Count: %d, pin: %d", count, pin);
    for (int i = 0; i < count; i++) {
        printf("%d\n", read(pin));
        fflush(stdout);
        delay(10);
    }                             
}
