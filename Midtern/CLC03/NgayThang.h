#ifndef _NGAY_THANG_H_
#define _NGAY_THANG_H_

#include <iostream>
#include <sstream>
using namespace std;

class NgayThang
{
private:
    int ngay;
    int thang;
    int nam;
public:
    bool NamNhuan();
    void DieuChinh();

    NgayThang();
    NgayThang(int ngay, int thang, int nam);
    NgayThang(string s);
    NgayThang(int n);
    ~NgayThang();
    
    friend ostream& operator<<(ostream& os, const NgayThang& ngay_thang);
    NgayThang* operator+(const NgayThang& khac);
    NgayThang* operator+(int days);
    friend NgayThang* operator+(int ngay, const NgayThang& ngay_thang);
    NgayThang& operator++();
    NgayThang* operator++(int);
};


#endif