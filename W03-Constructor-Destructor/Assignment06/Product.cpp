#include "Product.h"

Product::Product() {
    name = "";
    selected = 0;
    quantity = 0;
    unitPrice = 0;
}

Product::Product(string name, int quantity, int unitPrice) {
    this->name = name;
    this->quantity = quantity;
    this->unitPrice = unitPrice;
}

Product::~Product() {
}

void Product::setName(string name) {
    this->name = name;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Product::setUnitPrice(int unitPrice) {
    this->unitPrice = unitPrice;
}

void Product::setSelected(bool selected) {
    this->selected = selected;
}

string Product::getName() {
    return name;
}

int Product::getQuantity() {
    return quantity;
}

int Product::getUnitPrice() {
    return unitPrice;
}

bool Product::getSelected() {
    return selected;
}

void Product::increase() {
    ++quantity;
}

void Product::decrease() {
    --quantity;
}
