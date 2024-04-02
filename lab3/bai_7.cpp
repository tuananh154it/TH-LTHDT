#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class OTO{
    private:
        string maHang;
        string tenHangSX;
        float donGia;
        float dungTich;
        float trongLuong;
    public:
        OTO(string maHang = "", string tenHangSX = "", float donGia = 0, float dungTich = 0, float trongLuong = 0){
            this->maHang = maHang;
            this->tenHangSX = tenHangSX;
            this->donGia = donGia;
            this->dungTich = dungTich;
            this->trongLuong = trongLuong;
        }

        ~OTO(){}

        friend istream& operator>>(istream& is, OTO& oto){
            cout<<"nhap ma hang: ";
            getline(is, oto.maHang);
            cout<<"nhap ten hang SX: ";
            getline(is, oto.tenHangSX);
            cout<<"nhap don gia: "; is>>oto.donGia;
            cout<<"nhap dung tich xi lanh: "; is>>oto.dungTich;
            cout<<"nhap trong luong: "; is>>oto.trongLuong;
            return is;
        }
        float tinhTienVC(){
            if(trongLuong > 2){
                return 100000;
            } else if(trongLuong > 1){
                return 50000;
            } else {
                return 30000;
            }
        }
        friend ostream& operator<<(ostream& os, OTO oto){
            os<<setw(15)<<left<<oto.maHang
                <<setw(50)<<left<<oto.tenHangSX
                <<setw(15)<<left<<oto.donGia
                <<setw(15)<<left<<oto.dungTich
                <<setw(15)<<left<<oto.trongLuong
                <<setw(15)<<left<<oto.tinhTienVC()<<endl;
                return os;
        }

        bool operator==(float x){
            return dungTich == x;
        }
        // mo rong
        bool operator>(OTO b){
            return donGia>b.donGia;
        }
        bool operator>=(OTO b){
            return donGia>=b.donGia;
        }
        bool operator<(OTO b){
            return donGia<b.donGia;
            }
        bool operator<=(OTO b){
            return donGia<=b.donGia;
        }
        // getter
        string getTenHangSX(){
            return tenHangSX;
        }

};

void nhapDS(OTO oto[], int& n){
    cout<<"nhap vao so luong oto: "; cin>>n;

    cout<<"============  nhap danh sach oto ============"<<endl;

    for(int i = 0 ; i< n; i++){
        cin.ignore();
        cout<<"---------- nhap thong tin cho oto thu "<<i+1<<" ----------"<<endl;
        cin>>oto[i];
    }
}

void tieuDe(){
    cout<<setw(15)<<left<<"MA HANG"
        <<setw(50)<<left<<"TEN HANG SX"
        <<setw(15)<<left<<"DON GIA"
        <<setw(15)<<left<<"DUNG TICH"
        <<setw(15)<<left<<"TRONG LUONG"
        <<setw(15)<<left<<"TIEN VC"<<endl;
}

void inDS(OTO oto[], int n){
    cout<<"============  in danh sach oto ============"<<endl;
    tieuDe();
    for(int i = 0 ; i< n; i++){
        cout<<oto[i];
    }
}
void inOTO2_5(OTO oto[], int n){
    cout<<"============ DANH SACH OTO DUNG TICH 2.5L ============"<<endl;
    tieuDe();
    for(int i = 0 ; i< n ;i++){
        if(oto[i] == 2.5){
            cout<<oto[i];
        }
    }
}
void timOTO(OTO oto[], int& n){
    string name;
    cin.ignore();
    cout<<"nhap ten can tim: ";
    getline(cin, name);


    for(int i = 0;i<n;i++){
        if(oto[i].getTenHangSX() == name){
            cout<<"CO TIM THAY OTO "<<name<<endl;
            for(int j = i; j<n-1; j++){
                oto[j] = oto[j+1];
            }
            cout<<"DA XOA "<<name<<endl;
            n--;
            return ;
        }
    }
    cout<<"KHONG TIM THAY OTO "<<name<<endl;
    n++;
    for(int i = n-1 ; i>0 ; i--){
        oto[i] = oto[i-1];
    }
    cout<<" -------- nhap thong tin cho oto "<<name<<" -----------"<<endl;
    cin>>oto[0];
    cout<<"DA CHEN OTO "<<name<<endl;
}

void donGiaLonNhat(OTO oto[], int n){
    OTO max = oto[0];
    for(int i = 0 ; i<n; i++){
        if(oto[i] > max){
            max = oto[0];
        }
    }
    cout<<"========== OTO CO DON GIA LON NHAT ============"<<endl;
    tieuDe();
    cout<<max;
}
int main(){
    OTO oto[100];
    int n;
    //
    nhapDS(oto, n);
    inOTO2_5(oto, n);

    timOTO(oto, n);

    donGiaLonNhat(oto, n);
    return 0;
}