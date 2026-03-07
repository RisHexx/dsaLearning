#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TrieNode {
    public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char val){
        this->data = val;
        children = new TrieNode*[26];
        for(int i=0 ; i < 26 ; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie{
    private:
    TrieNode* root;

    void insertWord(string word , TrieNode* root){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(word.substr(1) , child);
    }

    void removeWord(string word , TrieNode* root){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            //word not found
            return;
        }
        removeWord(word.substr(1) , child);

        // delete child if it useless
        if(child->isTerminal == false){
            for(int i = 0 ; i <26 ; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    bool search(string word , TrieNode* root){
        if(word.size() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            //word not found
            return false;
        }
        return search(word.substr(1) , child);
    }
    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(string word){
        insertWord(word , root);
    }

    void removeWord(string word){
        removeWord(word , root);
    }

    bool search(string word){
        return search(word , root);
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    Trie t;
    t.insertWord("and");
    t.insertWord("are");

    cout<<t.search("and")<<endl;
    cout<<t.search("are")<<endl;
    
    t.removeWord("are");
    cout<<t.search("are")<<endl;
    cout<<t.search("and")<<endl;
    
    return 0;
}