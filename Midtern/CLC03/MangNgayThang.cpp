#include "MangNgayThang.h"

MangNgayThang::MangNgayThang()
{
}

MangNgayThang::~MangNgayThang()
{
    int len = DanhSach.size();
    for (int i = 0; i < len; ++i)
        delete DanhSach[i];
    DanhSach.clear();
}

void MangNgayThang::ThemNgayThang(NgayThang *ngay_thang)
{
    DanhSach.push_back(ngay_thang);
}

vector<NgayThang *> MangNgayThang::layMNT() const
{
    return DanhSach;
}

NgayThang*& MangNgayThang::operator[](int index)
{
    return DanhSach[index];
}

ostream& operator<<(ostream& os, const MangNgayThang& mnt)
{
    int len = mnt.layMNT().size();
    for (int i = 0; i < len; ++i)
        cout << *mnt.DanhSach[i] << "; ";
    return os;
}

