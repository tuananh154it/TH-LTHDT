#include<iostream>
using namespace std;
template <class T>
void nhap(T a[], int& n) {
    cout<<"nhap so luong phan tu: ";
    cin>>n;
    cout<<"------- nhap danh sach -------"<<endl;
    for(int i = 0; i < n ; i++) {
        cout<<"a["<<i<<"] = ";
        cin>>a[i];
    }
}

template <class T>
void xuat(T a[], int n){
    cout<<"---------- in ds ----------"<<endl;
    for(int i = 0 ; i<n ; i++) {
        cout<<a[i]<<", ";
    }
    cout<<endl;
}
template <class T>
T max(T a[], int n) {
    T max = a[0];
    for(int i = 0 ; i<n ; i++) {
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

template <class T>
T sum(T a[], int n)  {
    T s = 0;
    for(int i = 0 ; i<n; i++) {
        s = s + a[i];
    }
    return s;
}
template <class T>
void doiCho(T a[], int n) {
    int i, k;
    do{
        cout<<"nhap 2 vi tri can doi cho: ";
        cin>>i>> k;
        if(i>=0 && k >=0 && i<n && k<n) {
            break;
        }
    }while (true);
    T temp = a[i];
    a[i] = a[k];
    a[k] = temp;
}

template <class T>
void sapXepTang(T a[], int n)  {
    for(int i = 0; i < n-1 ; i++)  {
        for(int j = i + 1; j < n ; j++) {
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

template <class T>
void demKhac(T a[], int n, T x) {
    int dem = 0;
    for(int i = 0 ; i<n; i++) {
        if(a[i] != x){
            dem++;
        }
    }
    cout<<"so phan tu khac "<<x<<" la: "<<dem<<endl;
}

template <class T>
void timX(T a[], int n) {
    T x;
    cout<<"nhap gia tri can tim: ";
    cin>>x;
    for(int i = 0; i< n ; i++) {
        if(a[i] == x) {
            cout<<"gia tri "<<x<<" o vi tri: "<<i<<endl;
            return;
        }
    }
    cout<<"khong tim thay gia tri "<<x<<endl;
}

template <typename A>
class PhanSo {
    private:
        A tu, mau;
    public:
        PhanSo(){}
        PhanSo(A tu = 0, A mau = 1){
            this->tu = tu;
            this->mau = mau;
        }
        void nhap(){
            cout<<"nhap tu so: "; cin>> tu;
            cout<<"nhap mau so: "; cin>>mau;
        }
        PhanSo operator+(PhanSo b) {
            PhanSo kq(tu*b.mau+mau*b.tu, mau*b.mau);
            return kq;
        }
        
        void xuat() {
            cout<<tu<<"/"<<mau;
        }
}
;
template<typename A>
class SoPhuc {
    private:
        A thuc, ao;
    public:
        SoPhuc(A thuc = 0, A ao = 0) {
            this->thuc = thuc;
            this->ao = ao;
        }
        void nhap() {
            cout<<"nhap phan thuc: "; cin>>thuc;
            cout<<"nhap phan ao: "; cin>>ao;
        }
        SoPhuc operator+(SoPhuc b) {
            SoPhuc kq(thuc + b.thuc, ao + b.ao);
            return kq;
        }
        void xuat(){
            cout<<thuc<<" + "<<ao<<"i";
        }
};
template <class T> 
void xoa(T a[], int n) {
    int idx;
    do {
        cout<<"nhap vi tri can xoa: ";
        cin>>idx;
        if(idx>=0 && idx<n) {
            break;
        }
    } while (true);
    for(int i = idx ; i < n -1 ; i++) {
        a[i] = a[i + 1];
    }
    n--;
}


template <class T> 
void them(T a[], int& n) {
    int idx;
    T x;
    do{
        cout<<"nhap vi tri can them: ";
        cin>>idx;
        if(idx>=0 && idx<=n) {
            break;
        }
    } while(true);

    cout<<"nhap gia tri can them: ";
    cin>>x;
    for(int i = n ; i>idx; i--){
        a[i] = a[i-1];
    }
    a[idx] = x;
    n++;
}
int main() {
    // int n;
    // int a[100];
    // nhap(a, n);
    // xuat(a, n);
    // cout<<"phan tu lon nhat: "<<max(a, n)<<endl;
    // cout<<"tong cac phan tu: "<<sum(a, n)<<endl;
    // doiCho(a, n);
    // cout<<"----------sau khi doi cho: "<<endl;
    // xuat(a, n);

    // sapXepTang(a, n);
    // cout<<"-------------- sau khi sap xep giam:"<<endl;
    // xuat(a, n);

    // demKhac(a, n, 2);

    // timX(a, n);

    // xoa(a, n);

    // them(a, n);
    PhanSo<double> x(1.4, 2.5), y(2,5);
    cout<<"tong cua 2 phan so: ";
    PhanSo tongPT = x+ y;
    tongPT.xuat(); cout<<endl;
    SoPhuc<double> t(3,4), v(5,7);
    cout<<"tong cua 2 so phuc: ";
    SoPhuc tongSP = t + v;
    tongSP.xuat(); cout<<endl;
    return 0;
}