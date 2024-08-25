#include<iostream>
using namespace std;

class Cuboid
{
private:
    int height;
protected:
    int length, breadth;
public:
    Cuboid(int l=0, int b=0, int h=0)
    {
        setHeight(h);
        setLength(l);
        setBreadth(b);
    }
    void setHeight(int h);
    int getHeight() {return height;}
    int getLength() {return length;}
    int getBreadth() {return breadth;}
    void setLength(int l);
    void setBreadth(int b);
    int Volume() {return getLength()*getBreadth()*height;}
};
class Rectangle:public Cuboid
{
private:
    
public:
    Rectangle(int l=0,int b=0)
    {
        setLength(l);
        setBreadth(b);
    }
    
    int area() {return getLength()*getBreadth();}
    int perimeter() {return 2*(getLength()+ getBreadth());}
};

int main()
{
    int l, b , h;
    Cuboid c(l, b, h);

    Rectangle R(l, b);

    cout<<"Enter Length: ";
    cin>>l;
    cout<<"Enter Breadth: ";
    cin>>b;
    cout<<"Enter Height: ";
    cin>>h;
    c.setLength(l);
    c.setBreadth(b);
    c.setHeight(h);

    R.setLength(l);
    R.setBreadth(b);

    cout<<"Length is "<<c.getLength()<<endl;
    cout<<"Breadth is "<<c.getBreadth()<<endl;
    cout<<"Height is "<<c.getHeight()<<endl;
    
    cout<<"Volume of Cuboid is "<<c.Volume()<<endl;
    cout<<"Area of Rectangle is "<<R.area()<<endl;
    cout<<"Perimeter of Rectangle is "<<R.perimeter()<<endl;
    
    return 0;
}
void Cuboid::setLength(int l)
{
    if(l>=0) {length=l;}
    else
    {
        cout<<"Invalide Length input    ";
        length = 0;
    }
}
void Cuboid::setBreadth(int b)
{
    if(b>=0) {breadth=b;}
    else
    {
        cout<<"Invalide Breadth input    ";
        breadth = 0;
    }
}
void Cuboid::setHeight(int h)
{
    if(h>=0) {height=h;}
    else
    {
        cout<<"Invalide Height input    ";
        height = 0;
    }
}


