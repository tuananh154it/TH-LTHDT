#include<iostream>
#include<string>

using namespace std;

class VT{
    private:
        int n;
        float *v;
    public:
        VT(){
            cout<<"nhap so chieu: ";
            cin>>n;
            v = new float[n];
        }
        VT(VT &b){
            v = new float[b.n];
            n = b.n;
            for(int i = 0 ; i< n; i++){
                v[i] = b.v[i];
            }
        }
        int length(){
            return n;
        }

        float& operator[](int i){
            return v[i];
        }

        VT& operator=(VT &b){
            if(this != &b){
                delete v;
                v = new float[b.n];
                for(int i = 0 ; i<n; i++){
                    v[i] = b.v[i];
                }
            }
            return *this;
        }
};
void nhap(VT& s){
    for(int i = 0; i< s.length(); i++){
        cout<<"toa do thu "<<i+1<<": ";
        cin>>s[i];
    }
}
void in(VT& s){
    cout<<"so chieu: "<<s.length()<<endl;
    for(int i = 0; i< s.length() ;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int main(){

    VT s1, s2;
    cout<<"\nNhap toa do cua s1: "<<endl;
    nhap(s1);
    cout<<"\nIn thong tin ve s1: "<<endl;
    in(s1);
    s2 = s1;
    cout<<"\nIn thong tin ve s2: "<<endl;
    in(s2);
    
    return 0;
}