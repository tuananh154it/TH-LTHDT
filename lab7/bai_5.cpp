#include<iostream>
using namespace std;
class PhanSo {
    private:
        float tu, mau;
    public:
        PhanSo(float t = 0, float m = 1) {
            tu = t;
            mau = m;
        }
        PhanSo operator+(PhanSo b) {
            PhanSo kq(tu*b.mau + mau*b.tu, mau*b.mau);
            return kq;
        }
        
        PhanSo operator-(PhanSo b) {
            PhanSo kq(tu*b.mau - mau*b.tu, mau*b.mau);
            return kq;
        }

        
        PhanSo operator*(PhanSo b) {
            PhanSo kq(tu*b.tu, mau*b.mau);
            return kq;
        }
        
        PhanSo operator/(PhanSo b) {
            PhanSo kq(tu*b.mau, mau*b.tu);
            return kq;
        }
        
        void operator=(PhanSo b) {
            tu = b.tu;
            mau = b.mau;
        }
        friend ostream& operator<<(ostream& os, PhanSo b) {
            os<<b.tu<<"/"<<b.mau;
            return os;
        }
        bool operator>(PhanSo b) {
            return (tu/mau) > (b.tu/b.mau);
        }
};
template<class T>
class CalCulator{
    private:
        T num1, num2;
    public:
        CalCulator(T n1, T n2) {
            num1 = n1;
            num2 = n2;
        }

        void displayResult() {
            cout<<"hai so "<<num1<<" va "<<num2<<":"<<endl
                <<"tong: "<< num1 + num2<<endl
                <<"hieu: "<< num1 - num2<<endl
                <<"tich: "<< num1 - num2<<endl
                <<"thuong: "<< num1/num2<<endl
                <<"so lon nhat: "<< getMax() <<endl;
        }
        T getMax() {
            return num1 > num2 ? num1 : num2;
        }
};



int main() {
    // test voi so nguyen
    CalCulator<int> a(4,3);
    a.displayResult();

    // test voi phan so
    PhanSo x(1,5), y(4,7);
    CalCulator<PhanSo> b(x,y);
    b.displayResult();
    return 0;
}