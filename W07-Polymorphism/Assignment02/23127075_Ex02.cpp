#include <iostream>
#include <cstring>
using namespace std;

class A {
private:
    char *m_s;
public:
    A() { m_s = strdup("default"); }
    A(char *s) { m_s = strdup(s); }

    // Constructor sao chép
    A(const A &other) {
        m_s = strdup(other.m_s);
    }

    // Destructor để giải phóng bộ nhớ
    virtual ~A() {
        free(m_s);
    }

    // Hàm chuẩn bị
    virtual void prepare() {
        cout << "A ";
    }

    // Hàm hiển thị
    void display() {
        prepare();
        cout << m_s << endl;
    }

    // Toán tử nhập
    friend istream &operator>>(istream &in, A &a) {
        char buffer[100];
        in >> buffer;
        free(a.m_s); // Giải phóng bộ nhớ cũ
        a.m_s = strdup(buffer);
        return in;
    }

    // Toán tử xuất
    friend ostream &operator<<(ostream &out, const A &a) {
        out << "A: " << a.m_s;
        return out;
    }
};

class B : public A {
public:
    B(char *s) : A(s) {}

    // Constructor sao chép
    B(const B &b) : A(b) {}

    // Destructor
    ~B() {}

    // Ghi đè phương thức prepare
    void prepare() override {
        cout << "B ";
    }

    // Toán tử nhập
    friend istream &operator>>(istream &in, B &b) {
        in >> static_cast<A&>(b);
        return in;
    }

    // Toán tử xuất
    friend ostream &operator<<(ostream &out, const B &b) {
        out << static_cast<const A&>(b);
        return out;
    }
};

void foo(A *obj1, A obj2) {
    obj1->display();
    obj2.display();
}

int main() {
    char text[] = "text";
    B obj1(text);
    A *obj2 = new B(obj1);

    // Gọi hàm foo
    foo(&obj1, *obj2);

    // Thử toán tử nhập/xuất
    A a;
    cout << "Nhập chuỗi cho A: ";
    cin >> a;
    cout << a << endl;

    B b(text);
    cout << "Nhập chuỗi cho B: ";
    cin >> b;
    cout << b << endl;

    // Giải phóng bộ nhớ
    delete obj2;
    return 0;
}
