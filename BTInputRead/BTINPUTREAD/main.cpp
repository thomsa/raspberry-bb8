#include <stdio.h>
#include <stdlib.h>

#include  <cstring>

#include <errno.h>

#include <unistd.h>
#include <fcntl.h>


#include <libevdev-1.0/libevdev/libevdev.h>
#include <libevdev-1.0/libevdev/libevdev-uinput.h>

#include <XiaomiGamepadInterface.h>

#include <Delegate.hpp>

#include <iostream>

int foo(int x)
{
    std::cout << "foo(" << x << ")" << std::endl;
    return 1;
}



int main(void)
{
    XiaomiGamepadInterface *iFace = new XiaomiGamepadInterface();
    //static function

    //Delegate<int, int> d1(foo);
    iFace->BUTTON_A_DOWN(&foo);

    iFace->Start("/dev/input/event0");
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
