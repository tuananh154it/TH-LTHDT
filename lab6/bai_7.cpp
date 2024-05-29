#include<iostream>

using namespace std;

class ChuyenXe {
    protected:
        string maSoChuyen;
        string tenTX;
        int soXe;
        float doanhThu;
    public:
        virtual void nhap(){
            cout<<"nhap ma so chuyen: ";
            fflush(stdin);
            getline(cin, maSoChuyen);
            cout<<"nhap ho ten tai xe: ";
            fflush(stdin);
            getline(cin, tenTX);
            cout<<"nhap so xe: "; cin>>soXe;
            cout<<"nhap doanh thu: "; cin>>doanhThu;
        }
        virtual void xuat(){
            cout<<"msc: "<<maSoChuyen<<endl
                <<"ho ten TX: "<<tenTX<<endl
                <<"so xe: "<<soXe<<endl
                <<"doanh thu: "<<doanhThu<<endl;
        }

        virtual int phanLoai() = 0;

        float getDoanhThu(){
            return doanhThu;
        }
};


class ChuyenXeNoiThanh: public ChuyenXe {
    private:
        int soTuyen;
        float soKm;
    public:
        void nhap(){
            ChuyenXe::nhap();
            cout<<"nhap so tuyen: ";
            cin>>soTuyen;
            cout<<"nhap so km di duoc: ";
            cin>>soKm;
        }

        void xuat(){
            ChuyenXe::xuat();
            cout<<"so tuyen: "<<soTuyen<<endl
                <<"so km di duoc: "<<soKm<<endl;
        }
        int phanLoai(){
            return 1;
        }
};

class ChuyenXeNgoaiThanh: public ChuyenXe {
    private:
        string noiDen;
        int soNgayDiDuoc;
    public:
        void nhap(){
            ChuyenXe::nhap();
            cout<<"nhap noi den: ";
            fflush(stdin);
            getline(cin, noiDen);
            cout<<"nhap so ngay di duoc: ";
            cin>>soNgayDiDuoc;
        }

        void xuat(){
            ChuyenXe::xuat();
            cout<<"noi den: "<<noiDen<<endl
                <<"so ngay di duoc: "<<soNgayDiDuoc<<endl;
        }

        int phanLoai(){
            return 2;
        }
};

void nhapDS(ChuyenXe* a[], int& n){
    cout<<"=========== nhap ds ============"<<endl;

    cout<<"nhap so luong chuyen xe: "; cin>>n;
    int lc;
    for(int i = 0 ; i < n ; i++) {
        cout<<"------ nhap xe thu "<<i+1<<" ---------"<<endl;

        do{
            cout<<"ban muon nhap chuyen xe gi? "<<endl
                <<"1. chuyen xe noi thanh"<<endl
                <<"2. chuyen xe ngoai thanh"<<endl
                <<"lua chon: "; cin>>lc;

            if(lc == 1 || lc == 2){
                break;
            }
            cout<<"nhap khong hop le!!! vui long nhap lai!!!"<<endl;
        } while(true);
        if(lc == 1){
            a[i] =  new ChuyenXeNoiThanh();
        } else {
            a[i] = new ChuyenXeNgoaiThanh();
        }
        a[i]->nhap();
    }
}

void xuatDS(ChuyenXe* a[], int n){
    cout<<"============ ds chuyen xe =============="<<endl;
    for(int i = 0; i < n ; i++){
        a[i]->xuat();
        cout<<"---------"<<endl;
    }
}

void tongDoanhThuRieng(ChuyenXe* a[], int n){
    float tongNoi = 0, tongNgoai = 0;
    for(int i = 0; i<n; i++) {
        if(a[i]->phanLoai() == 1){
            tongNoi+= a[i]->getDoanhThu();
        } else {
            tongNgoai+= a[i]->getDoanhThu();
        }
    }

    cout<<"tong doanh thu chuyen xe noi thanh: "<<tongNoi<<endl;
    cout<<"tong doanh thu chuyen xe ngoai thanh: "<<tongNgoai<<endl;
}
int main(){
    int n;
    ChuyenXe* a[100];
    // nhap xuat
    nhapDS(a, n);
    xuatDS(a, n);

    // tong doanh thu tung loai
    tongDoanhThuRieng(a, n);
    return 0;
}