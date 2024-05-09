#include<iostream>

using namespace std;

class LoaiHinhThueBao {
    protected: 
        float tienThueHangThang;
    public:
        virtual void nhap() {
            cout<<"nhap tien thue hang thang(VND): ";
            cin>>tienThueHangThang;
        }
        virtual void xuat() {
            cout<<"tien thue hang hang: "<<tienThueHangThang<<"VND"<<endl;
        }
        virtual float tinhTien() = 0;
        virtual int phanLoai() = 0;
};

class DialUp: public LoaiHinhThueBao {
    private:
        float thoiGianTruyCap;
        float donGia;
    public:
        void nhap() {
            LoaiHinhThueBao::nhap();
            cout<<"nhap thoi gian truy cap(phut): ";
            cin>>thoiGianTruyCap;
            cout<<"nhap don gia(VND/phut): ";
            cin>>donGia;
        }
        void xuat() {
            LoaiHinhThueBao::xuat();
            cout<<"thoi gian truy cap: "<<thoiGianTruyCap<<"phut"<<endl;
            cout<<"don gia: "<<donGia<<" VND/phut"<<endl;
            cout<<"tinh tien: "<<tinhTien()<<endl;
        }

        float tinhTien() {
            return tienThueHangThang + thoiGianTruyCap*donGia;
        }

        int phanLoai() {
            return 1;
        }
};
class ADSL: public LoaiHinhThueBao { 
    private:
        float tongDungLuong;
        float donGia;
    public:
        void nhap() {
            LoaiHinhThueBao::nhap();
            cout<<"nhap tong dung luong truy cap(MB): ";
            cin>>tongDungLuong;
            cout<<"nhap don gia(VND/MB): ";
            cin>>donGia;
        }

        void xuat() {
            LoaiHinhThueBao::xuat();
            cout<<"tong dung luong: "<<tongDungLuong<<"MB"<<endl;
            cout<<"don gia: "<<donGia<<" VND/MB"<<endl;
            cout<<"tinh tien: "<<tinhTien()<<endl;
        }

        float tinhTien() {
            return tienThueHangThang + tongDungLuong*donGia;
        }

        int phanLoai() {
            return 2;
        }
};

class T1: public LoaiHinhThueBao {
    private:
    public:
    void nhap() {
        LoaiHinhThueBao::nhap();
    }

    void xuat() {
        LoaiHinhThueBao::xuat();
        cout<<"tinh tien: "<<tinhTien()<<endl;
    }

    float tinhTien() {
        return tienThueHangThang;
    }

    int phanLoai() {
        return 3;
    }
};

class KhachHang{
    private:
        string hoTen;
        LoaiHinhThueBao *tb;
    public:
        void nhap() {
            cout<<"nhap ho ten khach hang: ";
            fflush(stdin);
            getline(cin, hoTen);
            int lc;
            do{
                cout<<"nhap loai hinh thue bao ?"<<endl
                    <<"1. DialUp"<<endl
                    <<"2. ADSL"<<endl
                    <<"3. T1"<<endl
                    <<"nhap lua chon: "; cin>>lc;
                if(lc>0 && lc<4){
                    break;
                }
                cout<<"nhap khong hop le vui long nhap lai !!!"<<endl;
            } while(true);

            if(lc ==1){
                tb = new DialUp();
            } else if(lc == 2) {
                tb = new ADSL();
            } else {
                tb = new T1();
            }
            tb->nhap();
        }

        void xuat() {
            cout<<"ho ten: "<<hoTen<<endl;
            tb->xuat();
        }
        LoaiHinhThueBao* getLoaiHinh(){
            return tb;
        }
};

class QuanLy {
    private:
        KhachHang kh[30];
        int soKhachHang;
    public:
        void nhap() {
            cout<<"nhap so luong khach hang: ";
            cin>>soKhachHang;
            cout<<"---------------- nhap ds khach hang --------------"<<endl;

            for(int i = 0; i<soKhachHang ;i++) {
                cout<<"------ nhap thong tin khach hang thu "<<i+1<<" -------"<<endl;
                kh[i].nhap();
            }
        }
        void xuat() {
            cout<<"---------------- xuat ds khach hang --------------"<<endl;
            for(int i = 0; i < soKhachHang; i++){
                cout<<"----- "<<i+1<<" -----"<<endl;
                kh[i].xuat();
            }
        }
        void tongTienCuocTungLoaiTB() {
            float d = 0, a = 0, t = 0;
            for(int i = 0; i < soKhachHang; i++){
                if(kh[i].getLoaiHinh()->phanLoai() == 1){
                    d+= kh[i].getLoaiHinh()->tinhTien();
                } else if (kh[i].getLoaiHinh()->phanLoai() == 2) {
                    a+= kh[i].getLoaiHinh()->tinhTien();
                } else {
                    t+= kh[i].getLoaiHinh()->tinhTien();
                }
            }
            cout<<"tong tien cuoc cua cac thue bao Dial Up: "<<d<<" VND"<<endl;
            cout<<"tong tien cuoc cua cac thue bao ADSL: "<<a<<" VND"<<endl;
            cout<<"tong tien cuoc cua cac thue bao T1: "<<t<<" VND"<<endl;
        }
        void tongTienCuocTatCa() {
            float tong = 0;
            for(int i = 0; i< soKhachHang; i++) {
                tong+=kh[i].getLoaiHinh()->tinhTien();
            }
            cout<<"tong cuoc tat ca cac thue bao trong thang: "<<tong<<endl;
        }

        void timThueBaoADSLMax(){
            int index  =  0;
            float max = kh[0].getLoaiHinh()->tinhTien();
            for(int i = 0; i< soKhachHang; i++) {
                if(kh[i].getLoaiHinh()->tinhTien() > max){
                    max = kh[i].getLoaiHinh()->tinhTien() > max;
                    index = i;
                }
            }
            cout<<"----------------- thue bao co tien cuoc cao nhat thang ------------------"<<endl;
            kh[index].xuat();
        }
};
int main() {
    QuanLy q;
    // 
    q.nhap();
    q.xuat();
    // 
    q.tongTienCuocTungLoaiTB();
    //
    q.tongTienCuocTatCa();
    //
    q.timThueBaoADSLMax();


    return 0;
}