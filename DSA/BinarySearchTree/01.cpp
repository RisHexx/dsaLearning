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

BinaryTreeNode<int>* search(BinaryTreeNode<int>* root , int val){
    if(root == NULL) return NULL;
    if(root->data == val) return root;
    if(val < root->data){
        search(root->left,val);
    }else{
        search(root->right,val);
    }
}

void printRange(BinaryTreeNode<int>* root , int k1 , int k2){
    if (root == NULL) return;

    if(root->data > k1){
        printRange(root->left , k1 , k2);
    }
    if(root->data >= k1 && root->data <= k2){
        cout<<root->data<<" ";
    }
    if (root->data < k2){
        printRange(root->right , k1 , k2);
    }
}

int maximum(BinaryTreeNode<int>* root){
    if(root == NULL) return INT_MIN;
    return max(root->data , max(maximum(root->left) , maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL) return INT_MAX;
    return min(root->data , min(minimum(root->left) , minimum(root->right)));

}

bool checkBST(BinaryTreeNode<int>* root){
    if(root == NULL) return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && checkBST(root->left) && checkBST(root->right);
    return output;
}


bool isBST(BinaryTreeNode<int>* root , int min = INT_MIN, int max = INT_MAX){
    if(root == NULL) return true;
    if(root->data < min || root->data > max){
        return false;
    }
    bool isLeftOK = isBST(root->left , min , root->data - 1);
    bool isRightOK = isBST(root->right , root->data , max);
    return isLeftOK && isRightOK;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    BinaryTreeNode<int>* node = search(root,10);
    cout<<endl;
    if(node){
        cout<<node->data;
    }else{
        cout<<"No value";
    }
    cout<<endl;
    // printRange(root,20,50);
    cout<<checkBST(root);
    cout<<endl;
    cout<<isBST(root);



    
    return 0;
}