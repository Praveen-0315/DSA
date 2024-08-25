#include <iostream>
#include <string>

using namespace std;

struct dictionary {
    string word;
    string description;
};

void print_description(string s, struct dictionary *d, int n) {
    int found = 0;
    for (int i=0; i<n; ++i) {
        if(s == d[i].word) {
            cout<< d[i].description<< endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout<< "Not Found!!"<< endl;
    }
}

int main() {
    int n;
    cout<<"Enter number of words to be entered :";
    cin>>n;

    struct dictionary arr[n];
    for (int i=0; i<n; ++i) {
        struct dictionary d ;
        cout<< "Word : ";
        cin>> d.word;
        cout<< "Description : ";
        cin >> d.description;
        arr[i] = d;
    }

    string word ;
    cout<<"write word to search ";
    cin>>word;
    print_description(word, arr, n);

    return 0;
}