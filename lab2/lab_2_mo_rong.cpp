// Phung Tuan Anh - 22103100015

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

void tieuDe();

struct Date{
	int ngay, thang, nam;
	void nhapDate(){
		cout<<"nhap ngay: "; cin>>ngay;
		cout<<"nhap thang: "; cin>>thang;
		cout<<"nhap nam: "; cin>>nam;
	}
	string inDate(){
		string kq = "" + to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam);
		return kq;
	}
	operator=(Date b){
		ngay = b.ngay;
		thang = b.thang;
		nam = b.nam;
	}
};
Date now;
class CongNhan{
	protected:
		int maCN;
		char hoTen[50];
		Date ngaySinh;
		float heSoLuong;
	public:
		CongNhan(){
		}
		CongNhan(int maNV, char hoTen[], Date ngaySinh, float heSoLuong){
			this->maCN = maCN;
			strcpy(this->hoTen, hoTen);
			this->ngaySinh = ngaySinh;
			this->heSoLuong = heSoLuong;
		}
		~CongNhan(){
		}
		
		void nhap(){
			cout<<"nhap ma nhan vien: "; cin>>maCN; cin.ignore();
			cout<<"nhap ho ten: "; cin.getline(hoTen, 51);
			cout<<"--------- nhap ngay sinh ----------\n"; ngaySinh.nhapDate();
			cout<<"nhap he so luong: "; cin>>heSoLuong;
		}
		
		float tinhLuong(){
			return heSoLuong*1500000;
		}
		void in(){
			cout<<setw(15)<<left<<maCN
				<<setw(55)<<left<<hoTen
				<<setw(15)<<left<<ngaySinh.inDate()
				<<setw(15)<<left<<heSoLuong
				<<setw(15)<<left<<tinhLuong()<<endl;
		}
		
		int tinhTuoi(){
			
			
			if(now.nam > ngaySinh.nam && now.thang > ngaySinh.thang && now.ngay > ngaySinh.ngay){
				return now.nam - ngaySinh.nam;
			} else{
				return now.nam - ngaySinh.nam -1;
			}
			return 0;
		}
		// so sanh maCN
		bool operator!=(CongNhan b){
			return this->maCN != b.maCN;
		}
		friend CongNhan tongLuong2CN(CongNhan cn[], int n, CongNhan a, CongNhan b);
				
};
CongNhan tongLuong2CN(CongNhan cn[], int n, CongNhan a, CongNhan b){
	float tongLuong = a.tinhLuong() + b.tinhLuong();
	for(int i = 0; i<n ;i++){
		if(cn[i].tinhLuong() == tongLuong && cn[i]!=a && cn[i]!=b){
			return cn[i];
		}
	}
}

class ToCN: public CongNhan{
	private:
		int maTo;
		char tenTo[50];
		int soCN;
		CongNhan* danhSachCN;
	public:
		ToCN(){
		}
		ToCN(int n, int maTo, char tenTo[]){
			soCN = n;
			this->maTo = maTo;
			strcpy(this->tenTo, tenTo);
			if(n != 0){
				
				danhSachCN = new CongNhan[n+1];
			}
		}
		~ToCN(){
			delete danhSachCN;
		}
		
		void nhapDSCN(){
			for(int i = 0; i<soCN; i++){
				cout<<"------- nhap thong tin cho cong nhan thu "<<i+1<<" -------\n";
				danhSachCN[i].nhap();
			}
		}
		void inDSCN(){
			cout<<"---------- DS Cong Nhan -----------\n";
			tieuDe();
			for(int i = 0 ; i< soCN; i++){
				danhSachCN[i].in();
			}
		}
		
		float tongLuongTo(){
			float tong = 0;
			for(int i = 0 ; i< soCN; i++){
				tong+=danhSachCN[i].tinhLuong();
			}
			return tong;
		}
		
		void sapSepGiamLuong(){
			for(int i = 0 ; i< soCN - 1; i++){
				for(int j = i+1; j< soCN; j++){
					if(danhSachCN[i].tinhLuong() < danhSachCN[j].tinhLuong()){
						swap(danhSachCN[i], danhSachCN[j]);
					}
				}
			}
		}
		
		void CNluongMax(){
			int nv_i = 0;
			float luongMax = danhSachCN[0].tinhLuong();
			for(int i = 0 ; i< soCN; i++){
				if(danhSachCN[i].tinhLuong() > luongMax){
					nv_i = i;
					luongMax = danhSachCN[i].tinhLuong();
				}
			}
			cout<<"-------- cong nhan co luong cao nhat ---------\n";
			tieuDe();
			danhSachCN[nv_i].in();
		}
		
		void add(CongNhan x){
			int k = soCN -1;
			while(danhSachCN[k].tinhLuong() > x.tinhLuong()){
				k--;
			}
			k++;
			soCN++;
			for(int i = soCN -1; i>k;i--){
				danhSachCN[i] = danhSachCN[i-1];
			}
			danhSachCN[k] = x;
		}
		void xoaCNnghiHuu(){
			for(int i = 0 ; i < soCN ;i++){
				if(danhSachCN[i].tinhTuoi() >= 60){
					for(int j = i; i<soCN-1; i++){
						danhSachCN[j] = danhSachCN[j+1];
					}
					soCN--;
				}
			}
		}
};
void tieuDe(){
	cout<<setw(15)<<left<<"MA CN"
		<<setw(55)<<left<<"HO TEN"
		<<setw(15)<<left<<"NGAY SINH"
		<<setw(15)<<left<<"HE SO LUONG"
		<<setw(15)<<left<<"LUONG"<<endl;
}

int main(){
	
	cout<<"nhap ngay/thang/nam hien tai: "<<endl;
	now.nhapDate();
	int n;
	cout<<"nhap so luong cong nhan: "; cin>>n;
	char tenTo[] = "to 1";
	ToCN toCN(n, 111, tenTo);
	// nhap va in
	toCN.nhapDSCN();
	toCN.sapSepGiamLuong();
	toCN.inDSCN();
	// them 1 cn theo thu tu sap xep
	CongNhan x;
	x.nhap();
	toCN.add(x);
	cout<<"--------- sau khi them 1 nv ------------\n";
	toCN.inDSCN();
	// xoa cn co tuoi nghi huu >=60
	toCN.xoaCNnghiHuu();
	cout<<"------------- sau khi xoa CN nghi huu ------------\n";
	toCN.inDSCN();
	
	return 0;
}
