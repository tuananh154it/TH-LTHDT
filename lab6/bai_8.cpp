#include<iostream>
using namespace std;

class MatHang{
    protected:
        string ten;
        int soLuong;
    public:
        virtual void nhapKho(){
            cout<<"nhap ten mat hang: ";
            fflush(stdin);
            getline(cin, ten);
            cout<<"nhap so luong: ";
            cin>>soLuong;
        }

        virtual void xuatKho() {
            int num;
            do{
                cout<<"nhap so luong can xuat(hoac -1 de thoat): "; cin>>num;
                if(num == -1){
                    return ;
                }
                if(num <= soLuong){
                    break;
                }
                cout<<"nhap sai!!! so luong phai <= "<<soLuong<<endl;
            } while (true);
            soLuong-=num;
        }

        virtual int phanLoai() = 0;
        int getSoLuong(){
            return soLuong;
        }

        string getTen(){
            return ten;
        }
};


class NhapKhau: public MatHang {
    private:
        float thue;
    public:
        void nhapKho(){
            MatHang::nhapKho();
            cout<<"nhap thue: ";
            cin>>thue;
        }

        void tangGiamThue(){
            cout<<"nhap thue can tang/giam: ";
            cin>>thue;
        }
        int phanLoai(){
            return 1;
        }
};


class DaiLy: public MatHang {
    private:
        float hoaHong;
    public:
        void nhapKho(){
            MatHang::nhapKho();
            cout<<"nhap hoa hong: ";
            cin>>hoaHong;
        }

        void tangGiamHoaHong(){
            cout<<"nhap hoa hong can tang/giam: ";
            cin>>hoaHong;
        }

        int phanLoai(){
            return 2;
        }
};

void nhapHangVaoKho(MatHang* a[], int& n){
    cout<<"nhap so luong hang: "; cin>>n;
    int lc;
    for(int i = 0; i < n ; i++){
        cout<<"------ nhap mat hang thu "<<i+1<<" --------"<<endl;
        do{
            cout<<"ban can nhap loai hang gi? nhap khau (1), dai ly (2): ";
            cin>>lc;
            if(lc == 1 || lc == 2){
                break;
            }
            cout<<"nhap sai!!! nhap lai!!!"<<endl;
        } while(true);
        if(lc == 1){
            a[i] = new NhapKhau();
        } else {
            a[i] = new DaiLy();
        }

        a[i]->nhapKho();
    }
}

void xuatKho(MatHang* a[], int& n){
    string x;
    cout<<"nhap ten mat hang can xuat kho: ";
    fflush(stdin);
    getline(cin , x);

    for(int i = 0 ; i < n ; i++){
        if(a[i]->getTen() ==  x){
            a[i]->xuatKho();
            break;
        }
    }
}

void soLuongRieng(MatHang* a[], int n){
    int tongNK = 0 , tongDL = 0;
    for(int i = 0 ; i< n ; i++){
        if(a[i]->phanLoai() == 1){
            tongNK+=a[i]->getSoLuong();
        } else {
            
            tongDL+=a[i]->getSoLuong();
        }
    }

    cout<<"so luong hang nhap khau: "<<tongNK<<endl;
    cout<<"so luong hang dai ly: "<<tongDL<<endl;
}
int main(){
    int n;
    MatHang* a[100];
    nhapHangVaoKho(a, n);
    xuatKho(a, n);

    soLuongRieng(a, n);
    return 0;

}