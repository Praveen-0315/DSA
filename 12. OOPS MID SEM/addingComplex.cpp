#include <iostream>
using namespace std;
class Complex {
    private:
        int real, imag;
    public:
    Complex(){
        real = imag = 0;    
    }
    Complex (int r, int i){
        real = r;
        imag = i;
    }
    Complex operator+(Complex c2){
        Complex ret;
        ret.real = real + c2.real;
        ret.imag = imag + c2.imag;
        return ret;
    }
    void print(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};
int main(){
    Complex c1(8,-5), c2(2,3);
    Complex res = c1 + c2;
    res.print();
    return 0;
}