#ifndef _PROMOTION_H_
#define _PROMOTION_H_

class Promotion {
private:
    int discountValue;
    bool selected;
public:
    Promotion();
    Promotion(int value, bool selected);

    void setDiscountValue(int value);
    int getDiscountValue() const;

    void setSelected(bool selected);
    bool getSelected();
};

#endif