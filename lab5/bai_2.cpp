#include<iostream>
#include<fstream>
using namespace std;

class Nguoi{
    protected:
        string hoTen;
        int namSinh;
    public:
        Nguoi(string hoTen = "", int namSinh = 0){
            this->hoTen = hoTen;
            this->namSinh = namSinh;
        }
        ~Nguoi(){}

        friend istream& operator>>(istream& is, Nguoi& ng){
            cout<<"nhap ho ten: ";
            fflush(stdin);
            getline(is, ng.hoTen);
            cout<<"nhap nam sinh: ";
            is>>ng.namSinh;
            return is;
        }

        friend ostream& operator<<(ostream& os, Nguoi ng){
            os<<"ho ten: "<<ng.hoTen<<endl
                <<"nam sinh: "<<ng.namSinh<<endl;
            return os;
        }
        
        //
};

class SinhVien{
    protected:
        string hanhKiem;
        float diem;

    public:
        SinhVien(string hanhKiem = "", float diem = 0){
            this->hanhKiem = hanhKiem;
            this->diem = diem;
        }

        ~SinhVien(){}

        friend istream& operator>>(istream& is, SinhVien& sv){
            cout<<"nhap hanh kiem: ";
            fflush(stdin);
            getline(is, sv.hanhKiem);
            cout<<"nhap diem: ";
            is>>sv.diem;
            return is;
        }

        friend ostream& operator<<(ostream& os, SinhVien sv){
            os<<"hanh kiem: "<<sv.hanhKiem<<endl
                <<"diem: "<<sv.diem<<endl;
                return os;
        }
};

class SinhVienTaiChuc: public Nguoi, public SinhVien {
    private:
        float hocPhi;
    public:
        friend istream& operator>>(istream& is, SinhVienTaiChuc& svtc){
            is>>dynamic_cast<Nguoi&>(svtc);
            is>>dynamic_cast<SinhVien&>(svtc);
            cout<<"nhap hoc phi: ";
            is>>svtc.hocPhi;
            return is;
        }
        float tinhHocBong(){
            if(hanhKiem == "tot" && diem >= 8){
                return 5000000;
            }
            if((hanhKiem == "kha" || hanhKiem == "tot") && (diem >= 7)){
                return 3000000;
            }
            return 0;
        }
        friend ostream& operator<<(ostream& os, SinhVienTaiChuc svtc){
            os<<dynamic_cast<Nguoi&>(svtc);
            os<<dynamic_cast<SinhVien&>(svtc);
            os<<"hoc phi: "<<svtc.hocPhi<<endl;
            os<<"hoc bong: "<<svtc.tinhHocBong()<<endl;
            return os;
        }

        bool operator>(SinhVienTaiChuc b){
            return diem > b.diem;
        }

        void docFile(ifstream& fileIn){
            fileIn.ignore();
            getline(fileIn, hoTen);
            fileIn>>namSinh;
            fileIn.ignore();
            getline(fileIn, hanhKiem);
            fileIn>>diem;
            fileIn>>hocPhi;
        }
        void ghiFile(ofstream& fileOut){
            fileOut<<"ho ten: "<<hoTen<<endl
                    <<"nam sinh: "<<namSinh<<endl
                    <<"hanh kiem: "<<hanhKiem<<endl
                    <<"diem: "<<diem<<endl
                    <<"hoc phi: "<<hocPhi<<endl;
        }

};

void nhapDS(SinhVienTaiChuc svtc[], int& n){
    cout<<"------ nhap danh sach sinh vien tai chuc --------"<<endl;
    cout<<"nhap so luong sinh vien tai chuc: ";
    cin>>n;
    for(int i = 0; i < n ; i++) {
        cout<<"---- nhap thong tin svtc thu "<<i+1<<" ------"<<endl;
        cin>>svtc[i];
    }
}

void inDS(SinhVienTaiChuc svtc[], int n){
    cout<<"------ in danh sach sinh vien tai chuc --------"<<endl;
    for(int i = 0; i < n ; i++) {
        cout<<"----"<<i+1<<"------"<<endl;
        cout<<svtc[i];
    }
}

void inSinhVienDatHocBong(SinhVienTaiChuc svtc[], int n){
    cout<<"------ ds sinh vien dat hoc bong -------"<<endl;
    for(int i = 0; i<n; i++){
        if(svtc[i].tinhHocBong() != 0){
            cout<<"----- "<<i+1<<" -----"<<endl;
            cout<<svtc[i];
        }
    }
}

void sapXepTheoDiem(SinhVienTaiChuc svtc[], int n){
    for(int i = 0 ; i< n-1; i++){
        for(int j = i+1; j<n; j++){
            if(svtc[i] > svtc[j]){
                swap(svtc[i], svtc[j]);
            }
        }
    }
}

void docDSFile(SinhVienTaiChuc svtc[], int& n, string tenfile){
    ifstream fileIn;
    fileIn.open(tenfile);
    if (!fileIn.is_open()) {
        cerr << "Không thể mở file." << endl;
        return;
    }
    fileIn>>n;
    for(int i = 0 ; i< n ;i++){
        svtc[i].docFile(fileIn);
    }
    fileIn.close();
}

void  ghiDSFile(SinhVienTaiChuc svtc[], int& n, string tenfile){
    ofstream fileOut;
    fileOut.open(tenfile);
    for(int i = 0; i < n ; i++){
        svtc[i].ghiFile(fileOut);
    }
    fileOut.close();
}
int main(){
    int n;
    SinhVienTaiChuc svtc[100];
    // // nhap va in
    // nhapDS(svtc, n);
    // inDS(svtc, n);

    // doc ghi file
    docDSFile(svtc, n, "vao.txt");
    ghiDSFile(svtc, n, "ra.txt");
    // in sinh vien dat hoc bong
    inSinhVienDatHocBong(svtc, n);
    // sap xep va in

    sapXepTheoDiem(svtc, n);

    cout<<"===== sau khi sap xep tang dan ====="<<endl;
    inDS(svtc, n);

    return 0;
}