// 3 tính chất của OOP:
// 1. Enscapsulation & Data hiding
// Đóng gói: đưa các thuộc tính & các hàm xử lí có liên quan vào cùng 1 class
// Bao bọc, ẩn dữ liệu: scope (private vs public vs protected)
// 2. Inheritance
// 3. Polymorphism

// Công ty ABC có 2 loại NhanVien:
// NVSanXuat: mã nhân viên, họ tên, địa chỉ, số sản phẩm làm được trong tháng.
// Lương(NVSanXuat) = số sản phẩm * 10.000.
// NVCongNhat: mã nhân viên, họ tên, địa chỉ, hệ số lương, lương cơ bản, số ngày nghỉ.
// Lương(NVCongNhat): hệ số lương * lương cơ bản - số ngày nghỉ * 300.000.
// Với mỗi class nhân viên, viết 3 hàm sau đây: Nhap(), Xuat(), TinhLuong()

#include<iostream>
#include<string>
#include<vector>
using namespace std;
// Base class
class NhanVien{
private:
    // 3 thuộc tính
    int maNV;
    string hoTen;
    string diaChi;
public:
    // 2 hàm
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong();
    
};
void NhanVien::Nhap(){
    do{
        cout << "Ma NV: ";
        cin >> maNV;
    }while(maNV <= 0);
    cout << "Ho ten: ";
    cin.ignore(1);
    getline(cin, hoTen);
    cout << "Dia chi: ";
    getline(cin, diaChi);
}

void NhanVien::Xuat()
{
    cout << "Ma NV: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Luong: " << TinhLuong() << endl;
    
}

double NhanVien::TinhLuong()
{
    return 0;
    
    /*
    // SAI
    if(loaiNV == 1){
        // Tính lương theo NVSanXuat
    }
    else{
        // Tính lương theo NVCongNhat
    }
     */
}

class NVSanXuat: public NhanVien{
private:
    // 3 + 1 thuộc tính
    int soSP;
public:
    // 2 + 0 hàm
    // void NhapNVSX(); // SAI
    void Nhap();
    void Xuat();
    double TinhLuong();
};

/* SAI
void NVSanXuat::NhapNVSX(){
    // Gọi lại hàm Nhap() của NhanVien, để nhập maNV, hoTen, diaChi
    NhanVien::Nhap();
    // Nhập số sản phẩm
    cout << "So san pham: ";
    cin >> soSP;
}
 */

/*
// SAI
void NVSanXuat::Nhap(){
    // Gọi lại hàm Nhap() của NhanVien, để nhập maNV, hoTen, diaChi
    // Sửa lại protected!!!
    do{
        cout << "Ma NV: ";
        cin >> maNV;
    }while(maNV <= 0);
    cout << "Ho ten: ";
    cin.ignore(1);
    getline(cin, hoTen);
    cout << "Dia chi: ";
    getline(cin, diaChi);

    // Nhập số sản phẩm
    cout << "So san pham: ";
    cin >> soSP;
}
 */

void NVSanXuat::Nhap(){
    // Gọi lại hàm Nhap() của NhanVien, để nhập maNV, hoTen, diaChi
    NhanVien::Nhap();
    // Nhập số sản phẩm
    cout << "So san pham: ";
    cin >> soSP;
}

void NVSanXuat::Xuat(){
    NhanVien::Xuat();
    // cout << "Luong: " << TinhLuong() << endl;
    cout << "So san pham: " << soSP << endl;
}

double NVSanXuat::TinhLuong(){
    // NhanVien::TinhLuong();
    // Đề phòng sau này thay đổi qui định, nhân viên công ty mặc định được trợ cấp 1.000.0000 VND
    return NhanVien::TinhLuong() + soSP * 10000;
}

// NVCongNhat: mã nhân viên, họ tên, địa chỉ, hệ số lương, lương cơ bản, số ngày nghỉ.
// Lương(NVCongNhat): hệ số lương * lương cơ bản - số ngày nghỉ * 300.000.
class NVCongNhat: public NhanVien{
private:
    // 3 + 2 thuộc tính
    double heSo;
    double luongCB;
public:
    // 2 + 0 hàm
    void Nhap();
    void Xuat();
    double TinhLuong();
};

void NVCongNhat::Nhap(){
    NhanVien::Nhap();
    cout << "He so luong: ";
    cin >> heSo;
    cout << "Luong CB: ";
    cin >> luongCB;
}

void NVCongNhat::Xuat(){
    NhanVien::Xuat();
    // cout << "Luong: " << TinhLuong() << endl;
    cout << "He so luong: " << heSo << endl;
    cout << "Luong CB: " << luongCB << endl;
    
}

double NVCongNhat::TinhLuong(){
    // NhanVien::TinhLuong();
    // Đề phòng sau này thay đổi qui định, nhân viên công ty mặc định được trợ cấp 1.000.0000 VND
    return NhanVien::TinhLuong() + heSo * luongCB;
}

// Nhận xét:
// 1. Hai class NVSanXuat và NVCongNhat có 3 thuộc tính chung -> copy & paste khi khai báo thuộc tính
// 2. Hai class NVSanXuat và NVCongNhat có 3 thuộc tính chung -> copy & paste khi cài đặt hàm NVCongNhat::Nhap()
// 3. Vấn đề sửa đổi các thành phần chung: qui định maNV > 0 -> sửa code hàm NVSanXuat::Nhap() -> nhớ sửa lại code hàm NVCongNhat::Nhap()
// 4. Tương tự, đối với Xuat() -> code hàm NVSanXuat::Xuat() -> copy & paste & edit hàm NVCongNhat::Xuat()

// Các bước thực hiện kế thừa
// 1. Tạo base class (lớp cơ sở, lớp cha).
// 2. Đem các thuộc tính, hàm chung lên base class.
// 3. Cho 2 class hiện tại kế thừa (inherit/extend) base class -> subclasses, derived classes (lớp con, lớp dẫn xuất).
// 4. Ở 2 derived classes: xóa các thuộc tính và các hàm chung, giữ lại các thuộc tính riêng, các hàm riêng.
// 5. Override các hàm chung, nếu thấy cần.
// 6. Mặc định, NVSanXuat có thể gọi sử dụng hàm Nhap(), Xuat() mà cần viết code 2 hàm này (lớp con thừa hưởng các hàm của lớp cha). Tuy nhiên, hàm NhanVien::Nhap() sử dụng NVSanXuat chưa đầy đủ, cụ thể là ko cho nhập số sản phẩm -> trong lớp NVSanXuat override hàm Nhap() của NhanVien

/*
int main(){
    NVSanXuat nvsx1;
    // nvsx1.NhapNVSX(); // SAI
    nvsx1.Nhap();
    nvsx1.Xuat();
    
    NVCongNhat nvcn1;
    nvcn1.Nhap();
    nvcn1.Xuat();
    
    return 0;
}
*/

class CongTy{
private:
    string name;
    // vector<NhanVien*> a; // DUNG
    // vector<NhanVien> *a; // SAI
    vector<NhanVien> a; // SAI
public:
    void NhapDS();
    double TinhTongLuong();
};

void CongTy::NhapDS(){
    int n;
    int type;
    NhanVien *p;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin nhan vien thu " << i << endl;
        cout << "Loai nhan vien (1: NVSX; 2: NVCN): ";
        cin >> type;
        
        p = NULL;
        
        if(type == 1){
            // p = new NVSanXuat; // DUNG
            NVSanXuat nv; // SAI
            nv.Nhap(); // SAI
            a.push_back(nv); // SAI
        }
        else if(type == 2){
            // p = new NVCongNhat; // DUNG
            NVCongNhat nv; // SAI
            nv.Nhap(); // SAI
            a.push_back(nv); // SAI
        }
        
        // p->Nhap(); // DUNG
        // a.push_back(p); // DUNG
    }
}

double CongTy::TinhTongLuong(){
    double sum = 0;
    for(int i = 0; i < a.size(); i++){
        // sum += a[i]->TinhLuong(); // DUNG
        sum += a[i].TinhLuong(); // SAI
    }
    return sum;
}

void f1(NhanVien nv){
    cout << nv.TinhLuong() << endl;
}
void f2(NhanVien& nv){
    cout << nv.TinhLuong() << endl;
}
void f3(NhanVien* nv){
    cout << nv->TinhLuong() << endl;
}

int main(){
    // CongTy abc;
    // abc.NhapDS();
    // cout << "Tong luong: " << abc.TinhTongLuong() << endl;
    NVSanXuat nvsx;
    nvsx.Nhap();
    
    f1(nvsx);
    f2(nvsx);
    f3(&nvsx);
    
    return 0;
}



