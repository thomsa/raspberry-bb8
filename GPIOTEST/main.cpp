/*
 * test2.c:
 *      Simple test program to test the wiringPi functions
 *      PWM test
 */

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
    int pin ;
    int l ;

    printf ("Raspberry Pi wiringPi PWM test program\n") ;

    if (wiringPiSetup () == -1)
    {
        printf("Exiting");
        exit (1) ;
    }
    for (pin = 0 ; pin < 8 ; ++pin)
    {
        pinMode (pin, OUTPUT) ;
        digitalWrite (pin, LOW) ;
    }

    pinMode (1, PWM_OUTPUT) ;
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(1920);
    pwmSetRange(200);


//
//    printf("1");

//    printf("2");
    while (true)
    {

        pwmWrite(1, 5); // right
        delay(5000);
        pwmWrite(1, 13); //middle
        delay(5000);
         pwmWrite(1, 23.9); //left
        delay(5000);
    }

    return 0 ;
}

