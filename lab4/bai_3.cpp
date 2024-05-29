#include<iostream>
#include<iomanip>
using namespace std;

class MatHang{
    protected:
        string maHang;
        string tenHang;
        float donGia;
    public:
        MatHang(){}
        MatHang(string maHang, string tenHang, float donGia){
            this->maHang = maHang;
            this->tenHang = tenHang;
            this->donGia = donGia;
        }

        ~MatHang(){}

        friend istream& operator>>(istream& is, MatHang& mh){
            cout<<"nhap ma hang: ";
            getline(is, mh.maHang);
            cout<<"nhap ten hang: ";
            getline(is, mh.tenHang);
            cout<<"nhap don gia: ";
            cin>>mh.donGia;
            return is;
        }
};

class BanhKeo :public MatHang{
    private:
        string noiSanXuat;
    public:
        BanhKeo():MatHang(){}

        BanhKeo(string maHang, string tenHang, float donGia, string noiSanXuat)
        :MatHang(maHang, tenHang, donGia){
            this->noiSanXuat = noiSanXuat;
        }

        float tinhChietKhau(){
            return donGia*0.01;
        }

        friend istream& operator>>(istream& is, BanhKeo& bk){
            is>>dynamic_cast<MatHang&>(bk);
            cout<<"nhap noi xuan xuat: ";
            is.ignore();
            getline(is, bk.noiSanXuat);
            return is;
        }

        friend ostream& operator<<(ostream& os, BanhKeo bk){
            os<<setw(15)<<left<<bk.maHang
                <<setw(30)<<left<<bk.tenHang
                <<setw(15)<<left<<bk.donGia
                <<setw(30)<<left<<bk.noiSanXuat
                <<setw(15)<<left<<bk.tinhChietKhau()<<endl;
                return os;
        }

        //getter
        string getMaHang(){
            return maHang;
        }
};

void nhapDS(BanhKeo bk[], int& n){
    cout<<"nhap so luong banh keo: ";
    cin>>n;

    for(int i = 0 ; i < n ;i++){
        cout<<"------- nhap thong tin loai banh keo thu "<<i+1<<" -------"<<endl;
        fflush(stdin);
        cin>>bk[i];
    }
}

void tieuDe(){
    cout<<setw(15)<<left<<"MA"
        <<setw(30)<<left<<"TEN"
        <<setw(15)<<left<<"GIA"
        <<setw(30)<<left<<"NOI SX"
        <<setw(15)<<left<<"CHIET KHAU"<<endl;
}
void inDSkhacMO1(BanhKeo bk[], int n){
    cout<<"----- danh sach banh keo khac ma M01 la -------"<<endl;
    tieuDe();
    for(int i = 0 ; i< n ;i++){
        if(bk[i].getMaHang() != "M01"){
            cout<<bk[i];
        }
    }
}
int main(){
    int n;
    BanhKeo bk[100];
    nhapDS(bk, n);
    inDSkhacMO1(bk, n);
    return 0;
}