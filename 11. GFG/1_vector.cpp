#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> vect){
    int size = vect.size(); 
    for(int i=0; i<size; i++){
        cout<<vect[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    vector<int> vect1;
    int element, size;
    cout<<"Enter the size of your vector "<<endl;
    cin>>size;
    for(int i = 0; i < size; i++){
        cout<<"Enter the element to add in this vector :";
        cin>>element;
        vect1.push_back(element);
    }

    //vect1.pop_back();

    display(vect1);
}