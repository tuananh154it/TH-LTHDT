/*
Bài 1: Cho lớp độc giả (DocGia) mô tả các đối tượng độc giả. Lớp có thuộc tính:mã, họ, tên, số tháng hiệu lực.
 Lớp độc giả trẻ (DGTre), lớp độc giả người lớn (DGLon) kế thừa từ lớp độc giả.
  Lớp độc giả trẻ bổ sung thêm thuộc tính: năm sinh. Lớp đôc giả người lớn bổ sung thêm thuộc tính: nghề nghiệp. 
  - Quản lý danh sách các loại độc giả (cả hai loại). 
  - Tìm độc giả trẻ em có số tháng hiệu lực <10, độc giả người lớn là giảng viên. 
  - Tính tổng tiền làm thẻ của tất cả các độc giả. Biết độc giả trẻ em tiền làm thẻ = số tháng hiệu lực * 20000,
   độc giả người lớn tiền làm thẻ = số tháng hiệu lực * 30000*/
#include<iostream>
using namespace std;

class DocGia{
    protected:
        string ma;
        string ho;
        string ten;
        int soThangHieuLuc;
    public:
        virtual void nhap(){
            cout<<"nhap ma: ";
            fflush(stdin);
            getline(cin, ma);
            cout<<"nhap ho: ";
            fflush(stdin);
            getline(cin, ho);
            cout<<"nhap ten: ";
            fflush(stdin);
            getline(cin, ten);
            cout<<"nhap so thang hieu luc: ";
            cin>>soThangHieuLuc;
        }

        virtual void xuat(){
            cout<<"ma: "<<ma<<endl
                <<"ho ten: "<<ho + " " + ten<<endl
                <<"so thang hieu luc: "<<soThangHieuLuc<<endl;
        }
        virtual string phanLoai() = 0;

        int getSoThangHieuLuc(){
            return soThangHieuLuc;
        }

        virtual string getNgheNghiep() = 0;
};

class DGTre: public DocGia {
    private:
        int namSinh;
        string getNgheNghiep(){
            return "";
        }
    public:
        void nhap(){
            DocGia::nhap();
            cout<<"nhap nam sinh: ";
            cin>>namSinh;
        }

        void xuat(){
            DocGia::xuat();
            cout<<"nam sinh: "<<namSinh<<endl;
        }

        string phanLoai(){
            return "DGTre";
        }
};

class DGNguoiLon: public DocGia {
    private:
        string ngheNghiep;
    public:

        void nhap(){
            DocGia::nhap();
            cout<<"nhap nghe nghiep: ";
            fflush(stdin);
            getline(cin, ngheNghiep);
        }

        void xuat(){
            DocGia::xuat();
            cout<<"nghe nghiep: "<<ngheNghiep<<endl;
        }
        
        string phanLoai(){
            return "DGNguoiLon";
        }
        
        string getNgheNghiep(){
            return ngheNghiep;
        }
};

void nhapDS(DocGia* dg[], int& n) {
    cout<<"nhap so luong doc gia: ";
    cin>>n;
    int lc = -1; // tre: 0, gia: 1
    for(int i = 0 ; i < n ; i++){
        cout<<"------- nhap doc gia thu "<<i+1<<" --------"<<endl;
        do{
            cout<<"nhap thong tin cho doc gia?"<<endl
                <<"0. tre"<<endl
                <<"1. gia"<<endl
                <<"nhap lua chon: ";
            cin>>lc;
            if(lc == 0 || lc == 1){
                break;
            }
            cout<<"nhap sai quy dinh!!! yeu cau nhap loai!!!"<<endl;
        } while(true);

        if(lc == 0){
            dg[i] = new DGTre();
        } else{
            dg[i] = new DGNguoiLon();
        }
        dg[i]->nhap();
    }
}

void inDS(DocGia* dg[], int n){
    cout<<"------- ds ----------"<<endl;
    if(n == 0){
        return;
    }
    for(int i = 0 ; i < n ; i++){
        dg[i]->xuat();
        cout<<"-----*-----"<<endl;
    }
}
void docGiaTre10(DocGia* dg[], int& n){
    cout<<"------ doc gia tre co so thang hieu luc nho hon 10 -------"<<endl;
    for(int i = 0 ; i< n ; i++){
        if(dg[i]->phanLoai() == "DGTre" && dg[i]->getSoThangHieuLuc() < 10){
            dg[i]->xuat();
            cout<<"-------------"<<endl;
        }
    }
}

void docGiaLonGiangVien(DocGia* dg[], int& n){
    cout<<"------ doc gia nguoi lon la giang vien -------"<<endl;
    for(int i = 0 ; i< n ; i++){
        if(dg[i]->phanLoai() == "DGNguoiLon" && dg[i]->getNgheNghiep() == "Giang Vien"){
            dg[i]->xuat();
            cout<<"-------------"<<endl;
        }
    }
}
float tongTienLamThe(DocGia* dg[], int n){
    float tong = 0;
    for(int i = 0 ; i < n ; i++){
        if(dg[i]->phanLoai() == "DGTre"){
            tong+= 20000* dg[i]->getSoThangHieuLuc();
        } else{
            tong+= 30000* dg[i]->getSoThangHieuLuc();
        }
    }
    return tong;
}
int main(){
    int n;
    DocGia* dg[100];
    // nhap xuat

    nhapDS(dg, n);
    inDS(dg, n);

    // 
    docGiaTre10(dg, n);
    docGiaLonGiangVien(dg, n);

    //
    cout<<"tong tien lam the la : "<<tongTienLamThe(dg, n);
    return 0;
}