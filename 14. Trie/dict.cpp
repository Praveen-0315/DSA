#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public: 
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode*root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        
        // assumption, word will be in lower case
        int index = word[0] - 'a';
        TrieNode* child;

        // present 
        if(root->children[index] != NULL)
            child = root->children[index];
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index];
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0 ){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child ;

        // present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else 
            return false;
        
        return searchUtil(child, word.substr(1));
    }


    bool searchword(string word){
        return searchUtil(root, word);
    }
};

int main(){
    Trie *t = new Trie();
    t->insertWord("time");
    t->insertWord("arm");
    t->insertWord("does");
    t->insertWord("do");
    t->searchword("do") == true ? cout<<"true" : cout<<false;
    return 0;
}