#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main(){
    ifstream infile;
    infile.open("faltu.txt");
    if(infile.is_open()){
        int vow = 0;
        int consonents = 0;
        int total_alpha = 0;
        char letter;

        while(infile.get(letter)){
            letter = tolower(letter);
            if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' )
                vow ++;
            if(letter > 'a' && letter < 'z')
                total_alpha++;
        }
        cout<<"number of vowels: "<<vow<<endl;
        cout<<"number of consonents: "<< total_alpha-vow <<endl;
        cout<<"number of alphabets: "<< total_alpha <<endl;
    }
    else{
        cout<<"Could not open the file. ";
    }
    infile.close();
    
    return 0;
}