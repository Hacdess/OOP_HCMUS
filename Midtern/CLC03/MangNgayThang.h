#ifndef _MANG_NGAY_THANG_H_
#define _MANG_NGAY_THANG_H_ 

#include "NgayThang.h"
#include <vector>

class MangNgayThang
{
private:
    vector<NgayThang*> DanhSach;
public:
    MangNgayThang();
    ~MangNgayThang();

    void ThemNgayThang(NgayThang* ngay_thang);

    vector<NgayThang*> layMNT() const;
    friend ostream& operator<<(ostream& os, const MangNgayThang& mnt);
    NgayThang*& operator[](int index);
};


#endif