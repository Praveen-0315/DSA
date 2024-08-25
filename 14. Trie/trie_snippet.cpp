#include <iostream>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                Node *newNode = new Node();
                node->links[word[i] - 'a'] = newNode;
            }
            // move to the reference trie
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
                return false;
            node = node->links[word[i] - 'a'];
        }

        return node->flag;
    }

    bool startsWith(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
                return false;
            node = node->links[word[i] - 'a'];
        }

        return true;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->insert("apps");
    trie->insert("apxl");
    trie->insert("bac");
    trie->insert("bat");

    cout << trie->search("apple") << endl;
    cout << trie->search("apxl") << endl;
    cout << trie->search("dev") << endl;
    cout << trie->search("appu") << endl;

    cout << trie->startsWith("ap") << endl;
    cout << trie->startsWith("app") << endl;
    cout << trie->startsWith("apps") << endl;
    cout << trie->startsWith("appu") << endl;

    return 0;
}