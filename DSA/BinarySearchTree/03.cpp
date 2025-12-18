#include <bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode(T val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

class BST{
    private:
    bool hasData(int data, BinaryTreeNode<int>* node){
        if(node == NULL) return false;
        if(node->data == data){
            return true;
        }
        if(data < node->data){
            return hasData(data , node->left);
        }else{
            return hasData(data , node->right);
        }
    }
    BinaryTreeNode<int>* insert(int data , BinaryTreeNode<int>* node){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data < node->data){
            node->left = insert(data,node->left);
        }else{
            node->right = insert(data,node->right);
        }
        return node;
    }

    BinaryTreeNode<int>* deleteData(int data , BinaryTreeNode<int>* node){
        if(node == NULL){
            return NULL;
        }
        if(data > node->data){
            deleteData(data , node->right);
        }
        else if(data <node->data){
            deleteData(data , node->left);
        }else{
            // if node has no childeren
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            // if left is null
            else if(node->left == NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL; // so our destructor dont delete right subtree
                delete node;
                return temp;
            }
            // if right is null
            else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL; // so our destructor dont delete left subtree
                delete node;
                return temp;
            }
            // if node has both children
            // so take minium of right to replace with
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode != NULL){
                    minNode = node->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin , node->right);
                return node;
            }
        }

    }
    public:
    BinaryTreeNode<int>* root;
    BST(){
        root = NULL;
    }
    ~BST(){
        root = NULL;
    }

    void deleteData(int data){
        deleteData(data , this->root);
    }

    void insertData(int data){
        this->root = insert(data , this->root);
    }

    bool isData(int data){
      return hasData(data , this->root);
    }

};
int main() {
    std::ios_base::sync_with_stdio(false);
    
    
    return 0;
}