#include "NgayThang.h"

bool NgayThang::NamNhuan()
{
    return ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0));
}

void NgayThang::DieuChinh()
{
    int NgayTrongThang[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (NamNhuan())
        NgayTrongThang[1] = 29;

    if (ngay < 0)
        ngay = -ngay;
    if (thang < 0)
        thang = -thang;
    if (nam < 0)
        nam = -nam;

   if (thang == 0) 
    {
        thang = 12;
        --nam;
    }

    while (thang > 12)
    {
        thang -= 12;
        ++nam;
        NgayTrongThang[1] = (NamNhuan()) ? 29 : 28;
    }

    if (ngay == 0)
    {
        thang--;
        if (thang < 1)
            thang = 12;
        ngay = NgayTrongThang[thang - 1];
    }

    while (ngay > NgayTrongThang[thang - 1]) 
    {
        ngay -= NgayTrongThang[thang - 1];
        ++thang;
        if (thang > 12) {
            thang = 1;
            ++nam;
            NgayTrongThang[1] = (NamNhuan()) ? 29 : 28;
        }
    }

    while (thang > 12)
    {
        thang -= 12;
        ++nam;
        NgayTrongThang[1] = (NamNhuan()) ? 29 : 28;
    }
}

NgayThang::NgayThang()
{
    ngay = thang = nam = 1;
}

NgayThang::NgayThang(int ngay, int thang, int nam)
{
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;

    DieuChinh();
}

NgayThang::NgayThang(string s)
{
    stringstream ss(s);
    ss >> ngay;
    ss.ignore();
    ss >> thang;
    ss.ignore();
    ss >> nam;
    ss.ignore();
    DieuChinh();
}

NgayThang::NgayThang(int n)
{
    ngay = n;
    thang = nam = 0;
    DieuChinh();
}

NgayThang::~NgayThang()
{
    cout << "Deleted date\n";
}

NgayThang* NgayThang::operator+(const NgayThang &khac)
{
    NgayThang* ans = new NgayThang(this->ngay + khac.ngay, this->thang + khac.thang, this->nam + khac.nam);
    ans->DieuChinh();
    return ans;
}

NgayThang *NgayThang::operator+(int days)
{
    NgayThang* ans = new NgayThang(this->ngay + days, this->thang, this->nam);
    ans->DieuChinh();
    return ans;
}

NgayThang &NgayThang::operator++()
{
    ngay += 1;
    DieuChinh();
    return *this;
}

NgayThang *NgayThang::operator++(int)
{
    NgayThang* temp = this;
    ++this->ngay;
    this->DieuChinh();
    return temp;
}

ostream &operator<<(ostream &os, const NgayThang &ngay_thang)
{
    os << ngay_thang.ngay << '/' << ngay_thang.thang << '/' << ngay_thang.nam;
    return os;
}

NgayThang *operator+(int ngay, const NgayThang &ngay_thang)
{
    NgayThang* ans = new NgayThang(ngay_thang.ngay + ngay, ngay_thang.thang, ngay_thang.nam);
    ans->DieuChinh();
    return ans;
}
