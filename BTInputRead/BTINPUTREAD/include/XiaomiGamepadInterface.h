#ifndef XIAOMIGAMEPADINTERFACE_H
#define XIAOMIGAMEPADINTERFACE_H

#include <string>

class GamePadEvent
{
private:
    std::string _type;
    std::string _name;
    int _value;
public:
    std::string GetType()
    {
        return _type;
    };
    std::string GetName()
    {
        return _name;
    };
    int GetValue()
    {
        return _value;
    };

    GamePadEvent(std::string type, std::string name, int value)
    {
        _type = type;
        _name = name;
        _value = value;
    };
};

typedef int(*CallbackType)(GamePadEvent*);


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

    void DPAD_UP_UP(CallbackType callback);
    void DPAD_UP_DOWN(CallbackType callback);
    void DPAD_LEFT_UP(CallbackType callback);
    void DPAD_LEFT_DOWN(CallbackType callback);
    void DPAD_DOWN_UP(CallbackType callback);
    void DPAD_DOWN_DOWN(CallbackType callback);
    void DPAD_RIGHT_UP(CallbackType callback);
    void DPAD_RIGHT_DOWN(CallbackType callback);
    void DPAD_DEFAULT(CallbackType callback);

    void ABS_Z_CALLBACK(CallbackType callback);

    void Start(char* input);
protected:
private:
};

#endif // XIAOMIGAMEPADINTERFACE_H
