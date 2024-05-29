#include<iostream>

using namespace std;

template <class T>
class MyPair{
    private:
        T a, b;
    public:
        MyPair(T first, T second) {
            a = first;
            b = second;
        }
        void Print() {
            cout<<"First = "<<a<<", Second = "<<b<<endl;

        }

        T GetMax() {
            return a > b ? a : b;
        }

};

int main() {
    MyPair<int> pair1(100, 200);
    pair1.Print();
    cout<<"max: "<<pair1.GetMax()<<endl;
    MyPair<char> pair2('C', 'B');
    pair2.Print();
    cout<<"max: "<<pair2.GetMax()<<endl;
    return 0;
}