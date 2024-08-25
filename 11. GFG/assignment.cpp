#include <iostream>

using namespace std;

class item{
    
    public:
    int item_code;
    int price;
    
    void display();
    void add();
    void del(int,int);
    int total_value();
}c[10];

void item::del(int index,int i){
    item_code=0;
    price=0;
    
    while(index!=i){
        swap(c[index].item_code,c[index+1].item_code);
        swap(c[index].price,c[index+1].price);
        index++;
    }
}
    
void item::display(){
    cout<<item_code<<" "<<price<<endl;
}

void item::add(){
    cout<<"enter code:";
    cin>>item_code;
    
    if(item_code==1){
        price=100;
    }
    else{
        price=200;
    }
    cout<<"item added!"<<endl;
}

int item::total_value(){
    return price;
}

int main(){

    int ch,index,sum=0;
    
    cout<< "code"<<"    "<<"price"<<endl;
    cout<<1<<"       "<<100<<endl;
    cout<<2<<"       "<<200<<endl;
    cout<<endl;
    
    cout<<"1. Add item"<<endl;
    cout<<"2. Delete item"<<endl;
    cout<<"3. Total price"<<endl;
    cout<<"4. Display List"<<endl;
    cout<<endl;

    do{
        cout<<"Enter choice: ";
        cin>>ch;
        
        int i=0;
        while(c[i].item_code!=0){
            i++;
     }
    
        switch (ch){
            case 1: 
            c[i].add();
            cout<<endl;
            break;
            
            case 2:
            cout<<"Enter item index to delete: ";
            
            cin>>index;
            c[index].del(index,i);
            cout<<endl;
            
            break;
            
            case 3:
            sum=0;
            for(int j=0;j<i;j++){
                sum+=c[j].total_value();
            }
            cout<<"Total price is: "<<sum<<endl;
            cout<<endl;
            break;
            
            case 4:
            for(int j=0;j<i;j++){
                c[j].display();
            }
            cout<<endl;
            break;
            
            default:
            break;
        
        }
        
    }while (ch!=0);
    
    return 0;
}