#pragma once

namespace mainScreen {
    class HideMethod {
    public:
        // constructor
        HideMethod();

        // destructor
        virtual ~HideMethod();

        // set hidden
        void setHidden(bool hidden);

        // get hidden
        bool getHidden() const;

    private:
        bool isHidden;
    };
} // namespace mainScreen