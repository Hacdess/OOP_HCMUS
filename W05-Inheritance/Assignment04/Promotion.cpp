#include "Promotion.h"

Promotion::Promotion() {
    discountValue = 0;
    selected = 0;
}

Promotion::Promotion(int value, bool selected) {
    this->discountValue = value;
    this->selected = selected;
}

void Promotion::setDiscountValue(int value) {
    discountValue = value;
}

int Promotion::getDiscountValue() const {
    return discountValue;
}

void Promotion::setSelected(bool selected) {
    this->selected = selected;
}

bool Promotion::getSelected() {
    return selected;
}
