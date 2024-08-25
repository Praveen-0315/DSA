#include<iostream>
using namespace std;

class String
{
private:
    char *name;
    int length;
public:
    String()
    {
        length = 0;
        name = new char[length+1];
    }
    String(char *str)
    {
        length = strlen(str);
        name = new char[length+1];
        strcpy(name,str);
    }
    int strlen(char*);
    void strcpy(char*, char*);
    void input();
    void display();
    void strcat(String);
};

int String :: strlen(char *str){
    int Length = 0, i = 0;
    while(str[i] != '\0'){
        i++;
        Length++;
    }
    return Length;
}

void String :: strcpy(char *str1, char *str2){
    int i;
    for(i = 0; str2[i] != '\0'; i++){
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}

void String :: input(){
    cout << "Enter string data: ";
    cin >> name;
}

void String :: display(){
    cout << "String: " << name << endl;
}

void String :: strcat(String str2){
    int i = length;
    int j = 0;
    while(str2.name[j] != '\0'){
        name[i] = str2.name[j];
        j++;
        i++;
    }
    length = length + j;
    name[i] = '\0';
}

int main(){
    String s;
    s.input();
    char str[] = "HOLA!!!"; 
    String s1(str);
    s1.display();   //display s1 i.e, Hello!
    s.display();    //display s
    s1.strcat(s);   //concatenates s1 with s respectively
    s1.display();   //displays updated s1 i.e s1+s


}