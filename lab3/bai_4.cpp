/*
thêm:
so sánh theo trọng lượng
so sánh máy tính với một số
sắp xếp danh sách máy tính*/

// PHÙNG TUẤN ANH

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class MayTinh{
    private:
        int maHang;
        string tenHangSX;
        float donGia;
        int RAM;
        float trongLuong;
    public:
        MayTinh(int maHang = 0, string tenHangSX = "", float donGia = 0, int RAM = 0, float trongLuong = 0){
            this->maHang = maHang;
            this->tenHangSX = tenHangSX;
            this->donGia = donGia;
            this->RAM = RAM;
            this->trongLuong = trongLuong;
        }
        ~MayTinh(){}

        float tienVC(){
            if(trongLuong > 2){
                return 100000;
            } else if( trongLuong > 1){
                return 50000;
            } else {
                return 30000;
            }
        }

        bool operator==(int x){
            return RAM == x;
        }

        bool operator>(MayTinh b){
            return trongLuong > b.trongLuong;
        }

        friend istream& operator>>(istream& is, MayTinh& a){
            cout<<"nhap ma hang: ";
            is>>a.maHang; is.ignore();
            cout<<"nhap ten hang SX: ";
            getline(is, a.tenHangSX);
            cout<<"nhap vao don gia: ";
            is>>a.donGia;
            cout<<"nhap dung luong RAM: ";
            is>>a.RAM;
            cout<<"nhap vao trong luong: ";
            is>>a.trongLuong;
            return is;
        }
        friend ostream& operator<<(ostream& os, MayTinh a){
            os<<setw(15)<<left<<a.maHang
                <<setw(35)<<left<<a.tenHangSX
                <<setw(15)<<left<<a.donGia
                <<setw(15)<<left<<a.RAM
                <<setw(15)<<left<<a.trongLuong
                <<setw(15)<<left<<a.tienVC()<<endl;
            return os;
        }

        //getter
        string gettenHangSX(){
            return tenHangSX;
        }
};

void nhapDS(MayTinh a[], int &n){
    cout<<"nhap so luong may tinh: ";
    cin>>n;
    cout<<"---------- nhap danh sach may tinh -----------"<<endl;
    for(int i = 0 ; i<n ; i++){
        cout<<"----------- nhap may tinh thu "<<i+1<<" -------------"<<endl;
        cin>>a[i];
    }
}
void tieuDe(){
    cout<<setw(15)<<left<<"MA HANG"
        <<setw(35)<<left<<"HANG SX"
        <<setw(15)<<left<<"DON GIA"
        <<setw(15)<<left<<"RAM"
        <<setw(15)<<left<<"TRONG LUONG"
        <<setw(15)<<left<<"TIEN SHIP"<<endl;
}
void inRAM16(MayTinh a[], int n){
    cout<<"---------- nhap danh sach may tinh RAM = 16 -----------"<<endl;
    tieuDe();
    for(int i = 0 ; i<n ; i++){
        if(a[i] == 16){
            cout<<a[i];
        }
    }
}

void timSONY(MayTinh a[], int &n){
    for(int i = 0 ; i< n ; i++){
        if(a[i].gettenHangSX() == "SONY"){
            cout<<"co tim thay SONY!!!"<<endl;
            for(int j = i; j< n-1; j++){
                a[j] = a[j+1];
            }
            n--;
            return ;
        }
    }

    for(int i = n ; i>0;i--){
        a[i] = a[i-1];
    }
    cout<<"khong tim thay SONY!!!\n-------- nhap thong tin cho may SONY ----------"<<endl;
    cin>>a[0];
}

void inDS(MayTinh a[], int n){
    cout<<"============ DS MAY TINH ==========="<<endl;
    tieuDe();
    for(int i = 0 ; i < n ;i++){
        cout<<a[i];
    }
}
void sapXepTang(MayTinh a[], int n){
    for(int i = 0; i< n-1; i++){
        for(int j = i +1; j<n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

int main(){
    int n;
    MayTinh a[100];

    nhapDS(a, n);

    inRAM16(a, n);

    timSONY(a, n);

    sapXepTang(a, n);
    cout<<"============== sau khi sap xep tang ============"<<endl;
    inDS(a, n);

    return 0;
}