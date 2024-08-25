#include <iostream>
using namespace std;

class rational{
private:
    int N;
    int D;
public:
    rational(int x, int y){
        N = x;
        D = y;
    }
    rational(){
        N = 0;
        D = 1;
    }
    int hcf(int N,int D){
        if(D == 0) return N;
        
        if(N > D)
            return hcf(D, N%D);
        else
            return hcf(N, D%N);
    }
    void add(rational r2){
        rational ans;
        ans.N = (N*r2.D) + (D*r2.N);
        ans.D = D * r2.D;
        int h = hcf(ans.N, ans.D);
        cout << ans.N / h << " / "<<ans.D/h<<endl;
    }
    void subtract(rational r2){
        rational ans;
        ans.N = (N*r2.D) - (D*r2.N);
        ans.D = D * r2.D;
        int h = hcf(ans.N, ans.D);
        cout << ans.N / h << " / "<<ans.D/h<<endl;
    }

};

int main(){
    rational r1(2, 4), r2(3, 7);
    r1.subtract(r2);
    return 0;
}