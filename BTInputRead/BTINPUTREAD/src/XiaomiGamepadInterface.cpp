#include "XiaomiGamepadInterface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

#include <errno.h>

#include <unistd.h>
#include <fcntl.h>


#include <libevdev-1.0/libevdev/libevdev.h>
#include <libevdev-1.0/libevdev/libevdev-uinput.h>

#include <XiaomiGamepadInterface.h>

#include <Delegate.hpp>

#include <iostream>

#include <Delegate.hpp>

CallbackType ButtonADownCallback;
CallbackType ButtonAUpCallback;
CallbackType ButtonXDownCallback;
CallbackType ButtonXUpCallback;
CallbackType ButtonYDownCallback;
CallbackType ButtonYUpCallback;
CallbackType ButtonBDownCallback;
CallbackType ButtonBUpCallback;

CallbackType DPadUpDownCallback;
CallbackType DPadUpUpCallback;
CallbackType DPadDownDownCallback;
CallbackType DPadDownUpCallback;
CallbackType DPadRightDownCallback;
CallbackType DPadRightUpCallback;
CallbackType DPadLeftDownCallback;
CallbackType DPadLeftUpCallback;
CallbackType DPadDefaultCallback;


void XiaomiGamepadInterface::BUTTON_A_DOWN(CallbackType callback)
{
    ButtonADownCallback = callback;
}

void XiaomiGamepadInterface::BUTTON_A_UP(CallbackType callback)
{
    ButtonAUpCallback = callback;
}
void XiaomiGamepadInterface::BUTTON_B_DOWN(CallbackType callback)
{
    ButtonBDownCallback = callback;
}
void XiaomiGamepadInterface::BUTTON_B_UP(CallbackType callback)
{
    ButtonBUpCallback = callback;
}
void XiaomiGamepadInterface::BUTTON_Y_DOWN(CallbackType callback)
{
    ButtonYDownCallback = callback;
}
void XiaomiGamepadInterface::BUTTON_Y_UP(CallbackType callback)
{
    ButtonYUpCallback = callback;
}
void XiaomiGamepadInterface::BUTTON_X_DOWN(CallbackType callback)
{
    ButtonXDownCallback = callback;
}
void XiaomiGamepadInterface::BUTTON_X_UP(CallbackType callback)
{
    ButtonXUpCallback= callback;
}

//--------------------------------------------------------------------


void XiaomiGamepadInterface::DPAD_DOWN_DOWN(CallbackType callback)
{
    DPadDownDownCallback = callback;
}

void XiaomiGamepadInterface::DPAD_DOWN_UP(CallbackType callback)
{
    DPadDownUpCallback = callback;
}

void XiaomiGamepadInterface::DPAD_UP_DOWN(CallbackType callback)
{
    DPadUpDownCallback = callback;
}

void XiaomiGamepadInterface::DPAD_UP_UP(CallbackType callback)
{
    DPadUpUpCallback = callback;
}
void XiaomiGamepadInterface::DPAD_LEFT_DOWN(CallbackType callback)
{
    DPadLeftDownCallback = callback;
}

void XiaomiGamepadInterface::DPAD_LEFT_UP(CallbackType callback)
{
    DPadLeftUpCallback = callback;
}
void XiaomiGamepadInterface::DPAD_RIGHT_DOWN(CallbackType callback)
{
    DPadRightDownCallback = callback;
}

void XiaomiGamepadInterface::DPAD_RIGHT_UP(CallbackType callback)
{
    DPadRightUpCallback = callback;
}

void XiaomiGamepadInterface::DPAD_DEFAULT(CallbackType callback)
{
    DPadDefaultCallback = callback;
}

void XiaomiGamepadInterface::Start(char* input)
{
    struct libevdev *dev = NULL;
    int fd;
    int rc = 1;

    fd = open(input, O_RDONLY|O_NONBLOCK);
    rc = libevdev_new_from_fd(fd, &dev);

    if (rc < 0)
    {
        fprintf(stderr, "Failed to init libevdev (%s)\n", std::strerror(-rc));
        exit(1);
    }
    printf("Input device name: \"%s\"\n", libevdev_get_name(dev));
    printf("Input device ID: bus %#x vendor %#x product %#x\n",
           libevdev_get_id_bustype(dev),
           libevdev_get_id_vendor(dev),
           libevdev_get_id_product(dev));

    do
    {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
        if (rc == 0)
        {
            printf("Event: %s %s %d\n",
                   libevdev_event_type_get_name(ev.type),
                   libevdev_event_code_get_name(ev.type, ev.code),
                   ev.value);

            GamePadEvent *gamePadEvent = new GamePadEvent(
                std::string(libevdev_event_type_get_name(ev.type)),
                std::string(libevdev_event_code_get_name(ev.type, ev.code)),
                ev.value);

            if(gamePadEvent->GetName() == "BTN_SOUTH")
            {
                if(gamePadEvent->GetValue() == 0 && ButtonAUpCallback!= NULL)
                    ButtonAUpCallback(gamePadEvent);
                if(gamePadEvent->GetValue() == 1 && ButtonADownCallback!= NULL)
                {
                    ButtonADownCallback(gamePadEvent);
                }
            }
            else if(gamePadEvent->GetName() == "ABS_HAT0X")
            {
                if(gamePadEvent->GetValue() == -1 && DPadLeftDownCallback!= NULL)
                    DPadLeftDownCallback(gamePadEvent);
                else if(gamePadEvent->GetValue() == 1 && DPadRightDownCallback != NULL)
                    DPadRightDownCallback(gamePadEvent);
                else if(DPadDefaultCallback!= NULL)
                    DPadDefaultCallback(gamePadEvent);
            }

            else if(gamePadEvent->GetName() == "ABS_HAT0Y")
            {
                if(gamePadEvent->GetValue() == -1 && ButtonAUpCallback != NULL)
                    DPadUpDownCallback(gamePadEvent);
                else if(gamePadEvent->GetValue() == 1 && ButtonAUpCallback != NULL)
                    DPadDownDownCallback(gamePadEvent);

                else if(DPadDefaultCallback != NULL)
                    DPadDefaultCallback(gamePadEvent);
            }


        }
    }
    while (rc == 1 || rc == 0 || rc == -EAGAIN);
}

XiaomiGamepadInterface::XiaomiGamepadInterface()
{
    ButtonADownCallback =NULL;
    ButtonAUpCallback=NULL;
    ButtonXDownCallback=NULL;
    ButtonXUpCallback=NULL;
    ButtonYDownCallback=NULL;
    ButtonYUpCallback=NULL;
    ButtonBDownCallback=NULL;
    ButtonBUpCallback=NULL;

    DPadUpDownCallback=NULL;
    DPadUpUpCallback=NULL;
    DPadDownDownCallback=NULL;
    DPadDownUpCallback=NULL;
    DPadRightDownCallback=NULL;
    DPadRightUpCallback=NULL;
    DPadLeftDownCallback=NULL;
    DPadLeftUpCallback=NULL;
    DPadDefaultCallback=NULL;
}

XiaomiGamepadInterface::~XiaomiGamepadInterface()
{
    //dtor
}
