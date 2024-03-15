
#include<iostream>
using namespace std;

class DaThuc3{
    private:
        int a, b, c, d;
    public:
        DaThuc3(int a = 0, int b = 0, int c = 0, int d = 0){
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
        }
        ~DaThuc3(){}

        friend istream& operator>>(istream& is, DaThuc3& x){
            cout<<"a = "; is>>x.a;
            cout<<"b = "; is>>x.b;
            cout<<"c = "; is>>x.c;
            cout<<"d = "; is>>x.d;
            return is;
        }
        friend ostream& operator<<(ostream& os, DaThuc3 x){
            os<<x.a<<"x3 + "<<x.b<<"x2 + "<<x.c<<"x + "<<x.d;
            return os;
        }

        DaThuc3 operator+(DaThuc3 y){
            DaThuc3 kq(a + y.a, b + y.b, c + y.c, d + y.d);
            return kq;
        }

        DaThuc3 operator-(DaThuc3 y){
            DaThuc3 kq(a - y.a, b - y.b, c - y.c, d - y.d);
            return kq;
        }
};

int main(){
    DaThuc3 x, y;

    cout<<" ----------  nhap da thuc thu nhat  -----------\n";
    cin>>x;

    cout<<" ----------  nhap da thuc thu hai  -----------\n";
    cin>>y;

    cout<<"tong 2 da thuc tren: "<<x + y<<endl;

    cout<<"hieu 2 da thuc tren: "<<x - y<<endl;
    return 0;
}