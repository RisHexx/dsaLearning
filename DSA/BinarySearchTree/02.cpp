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
        // resursively deleete the entrie tree
        delete left; // call the destructor of left subtree 
        delete right; // call the destructor of right subtree

    }

};


BinaryTreeNode<int>* createTree(int arr[] , int si , int ei){
    if ( si > ei) return NULL;
    int mid = (si + ei) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    root->left = createTree(arr , si , mid - 1);
    root->right = createTree(arr , mid + 1 , ei);

    return root;
}
void printLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*>pendings;
    pendings.push(root);
    while(pendings.size() != 0){
        BinaryTreeNode<int>*front = pendings.front();
        pendings.pop();
        cout<<front->data<<" : ";
        if(front->left != NULL){
            cout<<"L "<<front->left->data<<" , ";
            pendings.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R "<<front->right->data;
            pendings.push(front->right);
        }
        cout<<endl;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int arr[7] = {1,2,3,4,5,6,7};
    BinaryTreeNode<int>* root = createTree(arr,0,6);
    printLevelWise(root);
    
    return 0;
}