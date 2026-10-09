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

void PrintTree(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<" L "<<root->left->data <<" , ";
    }
    if(root->right != NULL){
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);

}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin>> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin>> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendings;
    pendings.push(root);
    while(pendings.size() != 0){
    BinaryTreeNode<int>* front = pendings.front();
    pendings.pop();
    int leftData;
    cin>>leftData;
    if(leftData != -1){
    BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
    front->left = leftNode;
    pendings.push(leftNode);
    }
    int rightData;
    cin>>rightData;
    if(rightData != -1){
    BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
    front->right = rightNode;
    pendings.push(rightNode);
    }
    }
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
    // BinaryTreeNode<int>* root = takeInputLevelWise();
    // printLevelWise(root);
    BinaryTreeNode<int>* root = takeInput();
    PrintTree(root);

    
    return 0;
}