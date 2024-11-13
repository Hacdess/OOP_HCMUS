// #include "header.h"

// NgayThang::NgayThang()
// {
//     Ngay = Thang = Nam = 1;
// }

// NgayThang::NgayThang(int ngay, int thang, int nam)
// {
//     if(ngay < 0)
//     {
//         ngay *= -1;
//     }
//     if(thang < 0)
//     {
//         thang *= -1;
//     }
//     if(nam < 0)
//     {
//         nam *= -1;
//     }
//     Ngay = ngay;
//     Thang = thang;
//     Nam = nam;
//     if(Ngay > 30)
//     {
//         Ngay = 30;
//         while(ngay > 30)
//         {
//             Thang++;
//             ngay -= 30;
//         }
//     }
//     if(Thang > 12)
//     {
//         int tmp = Thang;
//         Thang = 12;
//         while(tmp > 12)
//         {
//             Nam++;
//             tmp -= 12;
//         }
//     }
// }

// NgayThang::NgayThang(string date)
// {
//     stringstream ss(date);
//     char tmp;
//     ss >> Ngay;
//     ss >> tmp;
//     ss >> Thang;
//     ss >> tmp;
//     ss >> Nam; 
//     NgayThang(Ngay, Thang, Nam);
// }

// NgayThang::NgayThang(int day)
// {

//     Ngay = day;
//     Thang = Nam = 1;
//     if(Ngay > 30)
//     {
//         Ngay = 30;
//         while(day > 30)
//         {
//             Thang++;
//             day -= 30;
//         }
//     }
//     if(Thang > 12)
//     {
//         int tmp = Thang;
//         Thang = 12;
//         while(tmp > 12)
//         {
//             Nam++;
//             tmp -= 12;
//         }
//     }

// }

// void NgayThang::print()
// {
//     cout << Ngay << "/" << Thang << "/" << Nam << ";" << endl;
// }

// NgayThang NgayThang::operator+(NgayThang other)
// {
//     Ngay += other.Ngay;
//     Thang += other.Thang;
//     Nam += other.Nam;
//     return NgayThang(Ngay, Thang, Nam);
// }

// NgayThang operator+ (NgayThang a, int x)
// {
//     NgayThang tmp;
//     tmp.Ngay = a.Ngay + x;
//     return NgayThang(tmp.Ngay, a.Thang, a.Nam);
// }

// NgayThang operator + (int x, NgayThang a)
// {
//     NgayThang tmp;
//     tmp.Ngay = a.Ngay + x;
//     return NgayThang(tmp.Ngay, a.Thang, a.Nam);
// }

// NgayThang NgayThang::operator++(int)
// {
//     NgayThang tmp = *this;
//     Ngay += 1;
//     normalize(Ngay, Thang, Nam);
//     return tmp;
// }

// NgayThang& NgayThang::operator++()
// {
//     Ngay += 1;
//     normalize(Ngay, Thang, Nam);
//     return *this;
// }

// bool NgayThang::operator>(NgayThang other)
// {
//     if(Nam > other.Nam)
//     {
//         return 1;
//     }
//     else if(Nam == other.Nam)
//     {
//         if(Thang > other.Thang)
//         {
//             return 1;
//         }
//         else if(Thang == other.Thang)
//         {
//             if(Ngay > other.Ngay){
//                 return 1;
//             }
//             else return 0;
//         }
//         else return 0;
//     }
//     else return 0;
// }

// int NgayThang::getNgay()
// {
//     return Ngay;
// }

// int NgayThang::getThang()
// {
//     return Thang;
// }

// int NgayThang::getNam()
// {
//     return Nam;
// }
// //---------------------------------------------------------------------------
// ostream& operator << (ostream& out, MangNgayThang a)
// {
//     for(int i = 0; i < a.v.size(); i++)
//     {
//         out << a.v[i]->getNgay() << "/" << a.v[i]->getThang() << "/" << a.v[i]->getNam() << endl;
//     }
//     return out;
// }

// NgayThang* MangNgayThang::operator[](int x)
// {
//     return v[x];
// }

// NgayThang& MangNgayThang::operator=(NgayThang* other(int x))
// {
    
//     normalize(Ngay, Thang, Nam);
//     return *this;
// }

// void MangNgayThang::ThemNgayThang(NgayThang* a)
// {
//     v.push_back(a);
// }
// NgayThang* MangNgayThang::NgayThangLonNhat()
// {
//     NgayThang* maxDate;
//     for(int i = 0; i < v.size(); i++)
//     {
//         if(*v[i] > *maxDate)
//         {
//             maxDate = v[i];
//         }
//     }
//     return maxDate;
// }

// MangNgayThang::~MangNgayThang()
// {
//     for (NgayThang* date : v)
//     {
//         delete date;
//     }
// }



#include "header.h"

NgayThang::NgayThang() : Ngay(1), Thang(1), Nam(1) {}

NgayThang::NgayThang(int ngay, int thang, int nam) : Ngay(ngay), Thang(thang), Nam(nam)
{
    normalize();
}

NgayThang::NgayThang(int ngay) : Ngay(ngay), Thang(1), Nam(1)
{
    normalize();
}

NgayThang::NgayThang(string date)
{
    stringstream ss(date);
    char tmp;
    ss >> Ngay >> tmp >> Thang >> tmp >> Nam;
    normalize();
}

void NgayThang::print()
{
    cout << Ngay << "/" << Thang << "/" << Nam;
}

NgayThang NgayThang::operator+(NgayThang other)
{
    return NgayThang(Ngay + other.Ngay, Thang + other.Thang, Nam + other.Nam);
}

NgayThang operator+(NgayThang a, int x)
{
    return NgayThang(a.Ngay + x, a.Thang, a.Nam);
}

NgayThang operator+(int x, NgayThang a)
{
    return NgayThang(a.Ngay + x, a.Thang, a.Nam);
}

NgayThang NgayThang::operator++(int)
{
    NgayThang temp = *this;
    Ngay++;
    normalize();
    return temp;
}

NgayThang& NgayThang::operator++()
{
    Ngay++;
    normalize();
    return *this;
}

bool NgayThang::operator>(NgayThang other)
{
    if (Nam != other.Nam)
        return Nam > other.Nam;
    if (Thang != other.Thang)
        return Thang > other.Thang;
    return Ngay > other.Ngay;
}

int NgayThang::getNgay() { return Ngay; }
int NgayThang::getThang() { return Thang; }
int NgayThang::getNam() { return Nam; }

void NgayThang::setNgay(int Ngay)
{
    this->Ngay = Ngay;
}

void NgayThang::setThang(int thang)
{
    Thang = thang;
}

void NgayThang::setNam(int nam)
{
    Nam = nam;
}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, MangNgayThang a)
{
    for (size_t i = 0; i < a.v.size(); ++i)
    {
        a.v[i]->print();
        if (i != a.v.size() - 1)
            out << "; ";
    }
    return out;
}

NgayThang*& MangNgayThang::operator[](int x)
{
    return v[x];
}

void MangNgayThang::ThemNgayThang(NgayThang* a)
{
    v.push_back(a);
}

void MangNgayThang::ThemNgayThang(NgayThang a)
{
    NgayThang* x = &a;
    v.push_back(x);
}
NgayThang* MangNgayThang::NgayThangLonNhat()
{
    if (v.empty()) return nullptr;
    NgayThang* maxDate = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        if (*v[i] > *maxDate)
        {
            maxDate = v[i];
        }
    }
    return maxDate;
}

MangNgayThang::~MangNgayThang()
{
    for (NgayThang* date : v)
    {
        delete date;
    }
    v.clear();
}
