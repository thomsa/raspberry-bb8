#ifndef XIAOMIGAMEPADINTERFACE_H
#define XIAOMIGAMEPADINTERFACE_H

#include <Delegate.hpp>

class XiaomiGamepadInterface
{
    public:
        XiaomiGamepadInterface();
        virtual ~XiaomiGamepadInterface();
        // button callback hooks
    void BUTTON_A_DOWN(CallbackType callback);
    void BUTTON_A_UP(CallbackType callback);
    void BUTTON_B_DOWN(CallbackType callback);
    void BUTTON_B_UP(CallbackType callback);
    void BUTTON_Y_DOWN(CallbackType callback);
    void BUTTON_Y_UP(CallbackType callback);
    void BUTTON_X_DOWN(CallbackType callback);
    void BUTTON_X_UP(CallbackType callback);



        void Start(char* input);
    protected:
    private:
};

#endif // XIAOMIGAMEPADINTERFACE_H
