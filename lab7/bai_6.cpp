#include<iostream>
using namespace std;

template<class T>
class Array{
    private:
        T* a;
        int n;
    public:
        Array() {
            cout<<"nhap so luong phan tu: ";
            cin>>n;
            a = new T[n];
        }
        void nhap() {
            cout<<"---------- nhap ds ----------"<<endl;
            for(int i = 0; i<n ; i++) {
                cout<<"-> nhap phan tu thu "<<i+1<<endl;
                cin>>a[i];
            }
        }
        void xuat() {
            cout<<"------------ in ds -----------"<<endl;
            for(int i = 0 ; i<n; i++) {
                cout<<a[i]<<"    ";
            }
            cout<<endl;
        }
        T tongPhanTu() {
            T sum = a[0];
            for(int i = 1; i< n ; i++) {
                sum = sum + a[i];
            }
            return sum;
        }
        void sapXepTang(){
            for(int i = 0; i < n - 1; i++) {
                for(int j = i + 1; j < n ; j++) {
                    if(a[i] > a[j]){
                        swap(a[i], a[j]);
                    }
                }
            }
        }
        T max() {
            T m = a[0] ;
            for(int i =1; i < n ; i++ ) {
                if(a[i] > m){
                    m = a[i];
                }
            }
            return m;
        }
        T min() {
            T m = a[0] ;
            for(int i =1; i < n ; i++ ) {
                if(a[i] < m){
                    m = a[i];
                }
            }
            return m;
        }
        T avg
};

int main() {
    Array<int> a;
    a.nhap();
    a.xuat();
    cout<<"tong phan tu cua mang: "<<a.tongPhanTu()<<endl;
    return 0;
}