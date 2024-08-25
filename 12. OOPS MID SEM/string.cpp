#include<iostream>
using namespace std;
class String{
    char *name;
    int length;
    public:
    String();
    String(char*);
    int strlen(char*);
    void strcpy(char*,char*);
    void input();
    void display();
    void strcat(String);
};

String :: String(){
    length = 0;
    name = new char[length+1];
}

String :: String(char *str){
    length = strlen(str);
    name = new char[length+1];
    strcpy(name,str);
}

int String :: strlen(char *str){
    int len = 0,i = 0;
    while(str[i] != '\0'){
        i++;
        len++;
    }
    return len;
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
    length = strlen(name);
}

void String :: display(){
    cout << "String: " << name << endl;
    cout << "String Length:" << length << endl;
}

void String :: strcat(String str2)
{
    char *temp = new char[length];
    strcpy(temp,name);
    name = new char[length + strlen(str2.name) + 1];
    strcpy(name,temp);
    int i = length;
    int j = 0;
    while(str2.name[j] != '\0'){
        name[i] = str2.name[j];
        j++;
        i++;
    }
    name[i] = '\0';
    length = length + j;
}

int main(){
    String s,s1;
    s.input();
    /*
    char str[] = "Hello!"; 
    String s1(str);
    s1.display();
    s.display();
*/
    cout<<"Second string "<<endl;
    s1.input();
    s1.strcat(s);
    s1.display();

}