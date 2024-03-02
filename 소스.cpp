//2023111359 최가윤
#include <iostream>
using namespace std;

//Complex 클래스
class Complex {
    // 필요한 멤버 구성
private:
    double x;
    double y;

public:
    Complex();
    Complex(double, double);
    //멤버 함수를 이용한 연산자 중복정의
    Complex operator+(Complex& c2) {
        Complex c(0.0, 0.0);
        c.x = this->x + c2.x;
        c.y = this->y + c2.y;
        return c;
    }
    Complex operator+(double a) {
        Complex c(0.0, 0.0);
        c.x = this->x + a;
        c.y = this->y;
        return c;
    }
    //전역 함수를 이용한 연산자 중복정의
    friend ostream& operator<<(ostream& od, const Complex& c);
    friend ostream& operator<<(const Complex& c, ostream& os);
};

//클래스 함수 외부정의
Complex::Complex() {
    x = 0.0;
    y = 0.0;
}
Complex::Complex(double x, double y) {
    this->x = x;
    this->y = y;
}

// 필요한 전역 함수 정의
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.x << " + " << c.y << "i" << endl;
    return os;
}
ostream& operator<<(const Complex& c, ostream& os) {
    os << c.x << " + " << c.y << "i" << endl;
    return os;
}

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;

    c1 << cout;

    cout << c3 << endl;

    c3 = c3 + 1;
    cout << c3 << endl;

    cout << "c1, c2, c3 : " << endl;
    c3 << (c2 << (c1 << cout));
    cout << endl;

    cout << "c1, c2, c3 : " << endl;
    cout << c1 << c2 << c3 << endl;

    return 0;
}