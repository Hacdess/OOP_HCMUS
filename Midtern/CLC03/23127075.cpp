#include "MangNgayThang.h"

int main() 
{ 
 MangNgayThang mnt; 
  
 /// 1.0 điểm: không lỗi biên dịch 
 mnt.ThemNgayThang(new NgayThang(90, 110, -1923)); 
 mnt.ThemNgayThang(new NgayThang("09/11/2023")); 
 mnt.ThemNgayThang(new NgayThang(119000)); 
 mnt.ThemNgayThang(new NgayThang); 
 /// 1.0 điểm: khởi tạo object hợp lý 
 /// xuất ra dạng: 'x/x/x' ; vd: '3/2/1900' 
 /// phân tách các NgayThang bằng "; " 
 /// 1.0 điểm: xuất định dạng: dd/mm/yyyy 
 cout << "MangNgayThang: " << mnt << endl; 
 
 /// 1.0 điểm 
 delete mnt[3]; 
 mnt[3] = new NgayThang(123456); 
 cout << mnt << endl;
 
 /// 1.5 điểm (lưu ý toán tử ++, +int áp dụng lên ngày) 
 mnt.ThemNgayThang(*mnt[0] + *mnt[1]); 
cout << mnt << endl;
 mnt.ThemNgayThang(*mnt[0] + 119); 
 cout << mnt << endl;
 mnt.ThemNgayThang(911 + *mnt[0]); 
 
 /// 1.5 điểm 
 mnt.ThemNgayThang(191 + (*mnt[1])++ + ++(*mnt[2])); 
 cout << "MangNgayThang: " << mnt << endl; 
 
 /// 2.0 điểm: xuất ngày tháng lớn nhất (lưu ý operator) 
 //cout << "Ngay Thang lon nhat: " << *mnt.NgayThangLonNhat() << endl; 
 /// 1.0 điểm: ngày tối đa mỗi tháng hợp lý 
 /// (vd: tháng 2 có 28~29 ngày, tháng 7 có 31 ngày). 
 
 system("pause"); 
 return 0; 
} 