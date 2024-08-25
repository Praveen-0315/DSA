#include<iostream>
#include<vector>
using namespace std;




int main(){
    int x1, y1, x2, y2;

    cout<<"enter x1 and y1"; 
    cin>>x1>>y1;
    cout<<"enter x2 and y2"; 
    cin>>x2>>y2;

    if(x1 != x2){
        x1 = min(x1, x2);
        x2 = max(x1, x2);
    }

    if(y1 != y2){
        y1 = min(y1, y2);
        y2 = max(y1, y2);
    }

    cout<<"x = "<<x1<<", y = "<<y1<< " ,  ";

    while(x1 != x2 or y1 != y2){
        if( x1 == x2){
            y1++;
            cout<<"x = "<<x1<<", y = "<<y1<< " ,  ";
            continue;
        }
        if(y1 == y2){
            x1++; 
            cout<<"x = "<<x1<<", y = "<<y1<< " ,  ";
            continue;
        }

        float m = (float)(y2 - y1)/ (x2-x1);

        if( m >= 0 and m < 0.58){
            y1++;
            cout<<"x = "<<x1<<"y = "<<y1<< " ,  ";
        }
        else if(m>= 0.58 and m < 1.73){
            y1++;
            x1++;
            cout<<"x = "<<x1<<"y = "<<y1<< " ,  ";
        }
        else {
            x1++;
            cout<<"x = "<<x1<<"y = "<<y1<< " ,  ";
        }
        
    }

    return 0;
}