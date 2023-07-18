#pragma once

namespace mainScreen {
    class PressMethod {
    public:
        // constructor
        PressMethod();

        // destructor
        virtual ~PressMethod();

        // set Pressed
        void setPressed(bool pressed);

        // get Pressed
        bool getPressed() const;

    private:
        bool isPressed;
    };
} // namespace mainScreen