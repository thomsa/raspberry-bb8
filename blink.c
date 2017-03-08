/*
 * test2.c:
 *      Simple test program to test the wiringPi functions
 *      PWM test
 */

#include <wiringPi.h>
#include <softPwm.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
  int pin ;
  int l ;

  printf ("Raspberry Pi wiringPi PWM test program\n") ;

  if (wiringPiSetup () == -1)
    exit (1) ;

	  printf ("Setting outputs\n") ;
  for (pin = 0 ; pin < 8 ; ++pin)
  {
    pinMode (pin, OUTPUT) ;
    digitalWrite (pin, LOW) ;
  }

  softPwmCreate(0, 0, 300);

  for (;;)
  {
	printf ("Going up\n") ;
    for (l = 0 ; l < 300 ; ++l)
    {
      softPwmWrite (0, l) ;
      delay (1) ;
    }
	printf ("Going down\n") ;

    for (l = 300; l >= 0 ; --l)
    {
      softPwmWrite (0, l) ;
      delay (1) ;
    }
  }

  return 0 ;
}
