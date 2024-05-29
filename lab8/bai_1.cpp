#include<iostream>
using namespace std;

class Basic {
    protected:
        int thoiGianGoi;
        int donGiaGoi;
        int luuLuong;
        int donGiaInternet;
    public:
        virtual int cuocDienThoai();
        virtual int cuocInternet();
        virtual void nhap();
        virtual void xuat();
        virtual int cuocTong();
        void suDung(int a, int b);
        Basic();
        virtual ~Basic();
};

Basic:: Basic() {
    thoiGianGoi = 0;
    thoiGianGoi = 0;
    luuLuong = 0;
    donGiaInternet = 200;
}

Basic::~Basic() {

}

int Basic::cuocDienThoai() {
    return thoiGianGoi*donGiaGoi;
}

int Basic::cuocInternet() {
    return luuLuong*donGiaInternet;
}
int Basic::cuocTong() {
    return 1.1* (cuocDienThoai() + cuocInternet());
}
void Basic::nhap() {
    cout<<"- nhap thoi gian goi: "; cin>>thoiGianGoi;
    cout<<"- nhap luu luong su dung: "; cin>>luuLuong;
}

void Basic::xuat() {
    cout<<"\t - ten goi cuoc: Basic";
}

void Basic::suDung(int _thoiGianGoi, int _luuLuong) {
    thoiGianGoi += thoiGianGoi;
    luuLuong += _luuLuong;
}

class DataFree: public Basic {
    int cuocThueBao;
    int nguongMp;

    public:
        DataFree();
        int cuocInternet();
        void nhap();
        void xuat();
        int cuocTong();
        ~DataFree();
};
DataFree::DataFree(){}
DataFree::~DataFree(){}

int DataFree::cuocInternet() {
    if(luuLuong < nguongMp){
        return cuocThueBao;
    } else {
        return cuocThueBao + (luuLuong - nguongMp)*donGiaInternet;
    }
}

void DataFree::nhap() {
    Basic::nhap();
    cout<<"- nhap cuoc thue bao: ";
    cin>>cuocThueBao;
    cout<<"- nhap nguong luu luong mien phi: ";
    cin>>nguongMp;
}

void DataFree::xuat() {
    cout<<"\t - ten goi cuoc: DataFree";
}

int DataFree::cuocTong() {
    return 1.1*(cuocInternet() + cuocDienThoai());
}

class DataFix: public Basic {
    public:
        int cuocDienThoai();
        int cuocInternet();
        void xuat();
        int cuocTong();
        ~DataFix();
};

DataFix::~DataFix(){}
int DataFix::cuocDienThoai() {
    return Basic::cuocDienThoai()*0.9;
}
int DataFix::cuocInternet() {
    return 1000000;
}

int DataFix::cuocTong() {
    return 1.1*(DataFix::cuocDienThoai() + DataFix::cuocInternet());
}
void DataFix::xuat() {
    cout<<"\t - ten goi cuoc: DataFix";
}

class HopDong {
    string hoTen;
    string cmnd;
    string diaChi;
    Basic* goiCuoc;
    public:
        HopDong();
        ~HopDong();
        void nhap();
        void xuat();
        int tinhCuocCuoiThang();
};
HopDong::HopDong(){}
HopDong::~HopDong(){}

void HopDong::nhap() {
    cout<<"nhap ho ten: ";
    fflush(stdin);
    getline(cin, hoTen);
    cout<<"nhap cmnd: "; cin>>cmnd;
    cout<<"nhap dia chi: ";
    fflush(stdin);
    getline(cin, diaChi);

    int lc;
    cout<<"---------  nhap loai hop dong ---------"<<endl;
    do{
        cout<<"1. Basic"<<endl
            <<"2. DataFree"<<endl
            <<"3. DataFix"<<endl;
        cout<<"nhap lua chon: "; cin>>lc;
        if(lc>0 && lc<4) {
            break;
        }
        cout<<"nhap sai vui long nhap lai !!!"<<endl;
    }while(true);
    if(lc == 1) {
        goiCuoc = new Basic();
    } else if(lc == 2) {
        goiCuoc = new DataFree();
    } else if ( lc == 3) {
        goiCuoc = new DataFix();
    }
    goiCuoc->nhap();
}
void HopDong::xuat(){
    cout<<"ho ten: "<<hoTen<<endl
        <<"cmnd: "<<cmnd<<endl
        <<"dia chi: "<<diaChi<<endl;
    goiCuoc->xuat();
}
int HopDong::tinhCuocCuoiThang() {
    return goiCuoc->cuocTong();
}


void nhapDS(HopDong a[], int& n) {
    cout<<"=> nhap so luong hop dong: "; cin>>n;
    for(int i = 0 ; i<n ; i++) {
        cout<<"--------- nhap hop dong thu " << i+1<<" ---------"<<endl;
        a[i].nhap();
    }
}
void inDS(HopDong a[], int n) {
    cout<<"------------------- ds hop dong ----------------------"<<endl;
    for(int i = 0; i<n; i++) {
        a[i].xuat();
        cout<<"----------"<<endl;
    }
}
int main() {
    int n;
    HopDong a[100];
    nhapDS(a, n);
    system("cls");
    inDS(a, n);
    return 0;
}