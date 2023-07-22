#include "HideMethod.h"

namespace mainScreen {
    HideMethod::HideMethod() : isHidden(false) {}

    HideMethod::~HideMethod() {}

    void HideMethod::setHidden(bool hidden) {
        isHidden = hidden;
    }

    bool HideMethod::getHidden() const {
        return isHidden;
    }
} // namespace mainScreen