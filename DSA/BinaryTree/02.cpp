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
void mirror(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;

    // swaping left and right subtree
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}


int countNode(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    int ans = 1;
    ans += countNode(root->left);
    ans += countNode(root->right);

    return ans;
}

int height(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    int maxHeight= 0;
    int childHeightleft = height(root->left);
    int childHeightright = height(root->right);
    if(childHeightleft > maxHeight){
        maxHeight = childHeightleft;
    }
    if(childHeightright > maxHeight){
        maxHeight = childHeightright;
    }
    return maxHeight + 1;
}

void preorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<countNode(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    cout<<height(root);
    
    
    return 0;
}