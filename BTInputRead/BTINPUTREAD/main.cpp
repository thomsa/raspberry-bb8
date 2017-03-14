#include <stdio.h>
#include <stdlib.h>

#include  <cstring>

#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <wiringPi.h>

#include <libevdev-1.0/libevdev/libevdev.h>
#include <libevdev-1.0/libevdev/libevdev-uinput.h>

#include <XiaomiGamepadInterface.h>

#include <Delegate.hpp>

#include <iostream>

int foo(GamePadEvent* x)
{
    std::cout  << x->GetName() << std::endl;
    return 1;
}

int turnServoRight(GamePadEvent* x) {
std::cout  << "turn right"  << std::endl;
pwmWrite(1, 5); // right
}
int turnServoLeft(GamePadEvent* x) {
std::cout  << "turn left" << std::endl;
pwmWrite(1, 23.9); //left
}
int turnServoCenter(GamePadEvent* x) {
std::cout  << "turn middle" << std::endl;
pwmWrite(1, 13); //middle
}

int absZMoved(GamePadEvent* x) {
    float middlePoint = 0.1;
    float pwmValue = middlePoint * x->GetValue();

    if(pwmValue < 5)
            pwmValue = 5;
    if(pwmValue > 23.9)
            pwmValue = 23.9;


    pwmWrite(1, pwmValue); //middle

}

int main(void)
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




    XiaomiGamepadInterface *iFace = new XiaomiGamepadInterface();

    iFace->DPAD_RIGHT_DOWN(&turnServoRight);
    iFace ->DPAD_LEFT_DOWN(&turnServoLeft);
    iFace->DPAD_DEFAULT(&turnServoCenter);
    iFace->ABS_Z_CALLBACK(&absZMoved);
    iFace->Start("/dev/input/event4");
}
//
//int main()
//{
// struct libevdev *dev = NULL;
// int fd;
// int rc = 1;
//
//
// fd = open("/dev/input/event0", O_RDONLY|O_NONBLOCK);
// rc = libevdev_new_from_fd(fd, &dev);
// if (rc < 0) {
//         fprintf(stderr, "Failed to init libevdev (%s)\n", std::strerror(-rc));
//         exit(1);
// }
// printf("Input device name: \"%s\"\n", libevdev_get_name(dev));
// printf("Input device ID: bus %#x vendor %#x product %#x\n",
//        libevdev_get_id_bustype(dev),
//        libevdev_get_id_vendor(dev),
//        libevdev_get_id_product(dev));
////    if (!libevdev_has_event_type(dev, EV_REL) ||
////    !libevdev_has_event_code(dev, EV_KEY, BTN_LEFT))
////    {
////        printf("This device does not look like a mouse\n");
////        exit(1);
////    }
//
// do {
//         struct input_event ev;
//         rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
//         if (rc == 0)
//                 printf("Event: %s %s %d\n",
//                        libevdev_event_type_get_name(ev.type),
//                        libevdev_event_code_get_name(ev.type, ev.code),
//                        ev.value);
// } while (rc == 1 || rc == 0 || rc == -EAGAIN);
//}
