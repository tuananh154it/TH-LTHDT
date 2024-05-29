#include<iostream>

using namespace std;

class HangHoa{
    protected:
        string ma;
        string ten;
        float donGia;
    public:
        HangHoa(string ma = "", string ten = "", float donGia = 0){
            this->ma = ma;
            this->ten = ten;
            this->donGia = donGia;
        }
        ~HangHoa(){}

        void nhap(){
            cout<<"nhap ma: ";
            getline(cin, ma);
            cout<<"nhap ten: ";
            getline(cin, ten);
            cout<<"nhap don gia: ";
            cin>>donGia;
        }

        void xuat(){
            cout<<"ma: "<<ma<<endl
                <<"ten: "<<ten<<endl
                <<"don gia: "<<donGia<<endl;
        }
};

class MayTinh:public HangHoa{
    protected:
        float tocDo;
        int soLuong;
    public:
        MayTinh(string ma = "", string ten = "", float donGia = 0, float tocDo = 0, int soLuong = 0)
        :HangHoa(ma, ten, donGia){
            this->tocDo = tocDo;
            this->soLuong = soLuong;
        }

        ~MayTinh(){}

        friend istream& operator>>(istream& is, MayTinh& mt){
            dynamic_cast<HangHoa&>(mt).nhap();
            cout<<"nhap toc do: ";
            is>>mt.tocDo;
            cout<<"nhap so luong: ";
            is>>mt.soLuong;
            return is;
        }
        float thanhTien(){
            return soLuong*donGia;
        }
        friend ostream& operator<<(ostream& os, MayTinh mt){
            dynamic_cast<HangHoa&>(mt).xuat();
            cout<<"toc do: "<<mt.tocDo<<endl
                <<"so luong: "<<mt.soLuong<<endl
                <<"thanh tien: "<<mt.thanhTien()<<endl;
            return os;
        }

        
};

class MayTinhXachTay:public MayTinh {
    private:
        float trongLuong;
    public:
        MayTinhXachTay(string ma = "", string ten = "", float donGia = 0, float tocDo = 0, int soLuong = 0)
        :MayTinh(ma, ten, donGia, tocDo, soLuong){
            this->trongLuong = trongLuong;
        }
        ~MayTinhXachTay(){}

        float phiBaoTri(){
            return 0.05*donGia;
        }

        friend istream& operator>>(istream& is, MayTinhXachTay& mtxt){
            is>>dynamic_cast<MayTinh&>(mtxt);
            cout<<"nhap trong luong: ";
            cin>>mtxt.trongLuong;
            return is;
        }
        friend ostream& operator<<(ostream& os, MayTinhXachTay mtxt){
            os<<dynamic_cast<MayTinh&>(mtxt);
            cout<<"trong luong: "<<mtxt.trongLuong<<endl
                <<"phi baoa tri: "<<mtxt.phiBaoTri()<<endl;
            return os;
        }     
        string getMa(){
            return ma;
        }
        string getTen(){
            return ten;
        }
        float getTocDo(){
            return tocDo;
        }
};

void nhapDS(MayTinhXachTay a[], int& n){
    cout<<"======== NHAP DS MTXT ========="<<endl;
    cout<<"nhap so luong may tinh xach tay: ";
    cin>>n;
    for(int i = 0 ; i< n ; i++){
        cout<<"------- nhap thong tin cho may thu "<<i+1<<" --------"<<endl;
        fflush(stdin);
        cin>>a[i];
    }
}

void inDS(MayTinhXachTay a[], int n){
    cout<<"========= DS MTXT ========"<<endl;
    for(int i = 0 ; i< n; i++){
        cout<<a[i];
        cout<<"-------------"<<endl;
    }
}

void timTheoMa(MayTinhXachTay a[], int n){
    string x;
    cout<<"nhap ma may can tim: ";
    fflush(stdin);
    getline(cin, x);
    for(int i = 0 ; i<n; i++){
        if(a[i].getMa() == x){
            cout<<"========= co tim thay MTXT co ma "<<x<<" =========="<<endl;
            cout<<a[i];
            return;
        }
    }
    cout<<"========= khong tim thay MTXT co ma "<<x<<" =========="<<endl;
}

void lietKeTheoTen(MayTinhXachTay a[], int n){
    string x;
    cout<<"nhap ten may tin can tim: ";
    fflush(stdin);
    getline(cin, x);
    cout<<"======== DS MTXT co ten la "<<x<<" ========"<<endl;
    for(int i = 0; i<n ;i++){
        if(a[i].getTen() == x){
            cout<<a[i];
            cout<<"-----------------"<<endl;
        }
    }
}
void tongPhiBaoTri(MayTinhXachTay a[], int n){
    float tong = 0; 
    for(int i = 0 ; i< n ;i++){
        tong+= a[i].phiBaoTri();
    }
    cout<<"===== tong phi bao tri la: "<<tong<<endl;
}

void tocDoNhoNhat(MayTinhXachTay a[], int n){
    MayTinhXachTay min = a[0];
    for(int i = 0 ; i< n; i++){
        if(a[i].getTocDo() < min.getTocDo()){
            min = a[i];
        }
    }
    cout<<"======= may tinh co toc do nho nhat ======="<<endl;
    cout<<min;
}

void suaThongTin(MayTinhXachTay a[], int n){
    string x;
    cout<<"nhap ma may can sua thong tin: ";
    fflush(stdin);
    getline(cin, x);
    for(int i = 0 ; i < n ;i++){
        if(a[i].getMa() == x){
            cout<<"======= nhap thong tin can sua =======";
            cin>>a[i];
            break;
        }
    }
}
void xoaTheoMa(MayTinhXachTay a[], int& n){
    string x;
    cout<<"nhap ma can xoa: ";
    fflush(stdin);
    getline(cin, x);
    for(int i = 0 ;i< n ; i++){
        if(a[i].getMa() == x){
            n--;
            for(int j = i; j<n ; j++){
                a[j] = a[j+1];
            }
            break;
        }
    }
}
void chenVaoK(MayTinhXachTay a[], int& n){
    int k = -1;
    do{
        cout<<"nhap vi tri can chen: ";
        cin>>k;
    }while( k>= 0 && k<n);
    MayTinhXachTay y;
    cout<<"======== nhap thong tin may tinh can chen =========="<<endl;
    fflush(stdin);
    cin>>y;

    for(int i = n; i>k ; i--){
        a[i] = a[i-1];
    }
    a[k] = y;
    n++;
}
void sapSepTangMaMay(MayTinhXachTay a[], int n){
    for(int i = 0 ; i< n - 1; i++){
        for(int j = i +1; j<n ;j++){
            if(a[i].getMa().compare(a[j].getMa()) > 0){
                swap(a[i], a[j]);
            }
        }
    }
}
void menu(MayTinhXachTay a[], int& n){
    int luaChon = -1;
    do{
        cout<<"1. nhap danh sach"<<endl
            <<"2. in danh sach"<<endl
            <<"3. tim theo ma"<<endl
            <<"4. liet ke theo ten"<<endl
            <<"5. tinh tong phi bao tri"<<endl
            <<"6. tim may tinh xach tay co toc do nho nhat"<<endl
            <<"7. sua thong tin cho mot may tinh xach tay"<<endl
            <<"8. xoa mot may tinh xach tay theo ma cho truoc"<<endl
            <<"9. chen mot may tinh xach tay tai vi tri k"<<endl
            <<"10. sap xep theo chieu tang dan cua ma may"<<endl
            <<"11. thoat"<<endl;

        cout<<"+++++ nhap lua chon: ";
        cin>>luaChon;
        switch (luaChon)
        {
        case 1:
            nhapDS(a, n);
            break;
        case 2:
            inDS(a, n);
            break;
        case 3:
            timTheoMa(a, n);
            break;
        case 4:
            lietKeTheoTen(a, n);
            break;
        case 5:
            tongPhiBaoTri(a, n);
            break;
        case 6:
            tocDoNhoNhat(a, n);
            break;
        case 7:
            suaThongTin(a, n);
            break;
        case 8:
            xoaTheoMa(a, n);
            break;
        case 9:
            chenVaoK(a, n);
            break;
        case 10:
            sapSepTangMaMay(a, n);
            break;
        case 11:
            cout<<"========== DA THOAT CHUONG TRINH ==========="<<endl;
            return;
        default:
            cout<<"lua chon khong hop le !!! vui long nhap lai!!!"<<endl;
        }

    } while(true);
}


int main(){
    int n;
    MayTinhXachTay a[100];
    menu(a, n);
    return 0;
}