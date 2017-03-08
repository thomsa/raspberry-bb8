/*
 * test2.c:
 *      Simple test program to test the wiringPi functions
 *      PWM test
 */
#include <iostream>

#include <wiringPi.h>
#include <softPwm.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <TestClass.h>

using namespace std;



int main (void)
{
    int pin ;
    int l ;
    bool litUp;

    printf ("Raspberry Pi wiringPi PWM test program\n") ;


    if (wiringPiSetup() == -1)
        exit (1) ;

    cout << "Setting outputs\n";


        pinMode (0, OUTPUT) ;
        digitalWrite (0, LOW) ;

    pinMode (1, INPUT) ;

    softPwmCreate(0, 0, 300);
    //bool litUp;
    litUp = false;

    for (;;)
    {


        if(digitalRead(1) > 0)
        {
            if(litUp == false){
                digitalWrite (0, HIGH) ;
                litUp = true;
                printf("You pushed the button\n");
            }

        }
        else
        {
            if(litUp == true)
            {    digitalWrite (0, LOW) ;
                litUp = false;
                printf("You released the button\n");
            }

        }
        //delay (1) ;

    }

    return 0 ;
}
