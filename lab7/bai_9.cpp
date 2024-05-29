#include<iostream>
#include<iomanip>
using namespace std;

class PhanSo {
    private:
        float tu, mau;
    public:
        PhanSo(float tu = 0, float mau = 1) {
            this->tu = tu;
            this->mau = mau;
        }
        friend istream& operator>>(istream& is, PhanSo& a) {
            cout<<"nhap tu: "; is>>a.tu;
            do{
                cout<<"nhap mau: ";
                is>>a.mau;
                if(a.mau!=0) {
                    break;
                }
                cout<<"nhap mau khac 0!!!"<<endl;
            } while(true);
            return is;
        }
        friend ostream& operator<<(ostream& os, PhanSo a) {
            os<<a.tu<<" / "<<a.mau;
            return os;
        }

        PhanSo operator+(PhanSo b) {
            PhanSo kq(tu*b.mau + b.tu*mau, mau*b.mau);
            return kq;
        }
        bool operator>(PhanSo b) {
            return (tu/mau) > (b.tu/b.mau);
        }
};

template <typename T>
void nhap(T a[][100], int& x, int& y) {
    cout<<"nhap so hang: ";
    cin>>x;
    cout<<"nhap so cot: ";
    cin>>y;
    cout<<"---------------- nhap ds ----------------"<<endl;
    for(int i = 0; i< x ; i++) {
        for(int j= 0 ; j < y; j++) {
            cout<<"a["<<i<<"]["<<j<<"] = ";
            cin>>a[i][j];
        }
    }
}
template <typename T>
void xuat(T a[][100], int x, int y) {
    cout<<"-------------- in ds --------------"<<endl;
    for(int i = 0 ; i<x; i++) {
        for(int j = 0 ; j< y; j++){
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
}
template <typename T>
T max(T a[][100], int x, int y) {
    T max = a[0][0];
    for(int i = 0; i<x; i++) {
        for(int j = 0; j< y ; j ++) {
            if(a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

template <typename T>
T tongCheoChinh(T a[][100], int x, int y){
    T s = a[0][0];
    for(int i = 1; i < x; i++) {
        if(i<y) {
            s = s + a[i][i];
        }
    }
    return s;
}

template <typename T>
void sapXepDuongCheoTang(T a[][100], int x, int y) {

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y - 1; j++) {
            for(int k = j + 1; k < y; k++) {
                if(a[i][j] > a[i][k]){
                    swap(a[i][j], a[i][k]);
                }
            }
        }
    }
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x - 1; j++) {
            for(int k = j + 1; k < x; k++) {
                if(a[j][i] > a[k][i]){
                    swap(a[j][i], a[k][i]);
                }
            }
        }
    }
}
void nhapPS(PhanSo a[][100], int& n, int& m) {
    cout<<"nhap so hang: "; cin>>n;
    cout<<"nhap so cot: "; cin>>m;
    cout<<"--------- nhap danh sach phan so ------------"<<endl;
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j<m; j++) {
            cout<<"=> nhap phan so tai a["<<i<<"]["<<j<<"]"<<endl;
            cin>>a[i][j];
        }
    }
}
void inPS(PhanSo a[][100], int n, int m) {
    cout<<"----------- danh sach phan so ------------"<<endl;
    for(int i = 0 ; i< n ; i++) {
        for(int j = 0; j<m; j++) {
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
}
int main(){
    // // ma tran int
    // int a[100][100];
    // int x, y;
    // nhap(a, x, y);
    // system("cls");
    // xuat(a, x, y);

    // cout<<"phan tu max la: "<<max(a, x, y)<<endl;
    // cout<<"tong duong cheo chinh: "<<tongCheoChinh(a, x, y)<<endl;

    // cout<<"--------------- sau khi sap xep tang theo duong cheo -------------"<<endl;
    // sapXepDuongCheoTang(a, x, y);
    // xuat(a, x, y);

    // Phan so
    PhanSo b[100][100];
    int n, m;
    nhapPS(b, n, m);
    inPS(b, n, m);
    cout<<"phan tu max la: "<<max(b, n, m)<<endl;
    cout<<"tong duong cheo chinh: "<<tongCheoChinh(b, n, m)<<endl;

    cout<<"--------------- sau khi sap xep tang theo duong cheo -------------"<<endl;
    sapXepDuongCheoTang(b, n, m);
    xuat(b, n, m);
    return 0;
}