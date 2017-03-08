#ifndef XIAOMIGAMEPADINTERFACE_H
#define XIAOMIGAMEPADINTERFACE_H

#include <Delegate.hpp>

class XiaomiGamepadInterface
{
    public:
        XiaomiGamepadInterface();
        virtual ~XiaomiGamepadInterface();
        void RegisterAButton(CallbackType callback);
        void Start(char* input);
    protected:
    private:
};

#endif // XIAOMIGAMEPADINTERFACE_H
