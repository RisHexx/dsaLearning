#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;

    TreeNode(T val){
        this->data = val;
    }
};

TreeNode<int>* takeInput(){
    int TreeData;
    cin>>TreeData;
    TreeNode<int>* root = new TreeNode<int>(TreeData);
    int children;
    cin>>children;
    for(int i = 0 ; i < children ; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>*root){
    cout<< root->data<< " : ";
    for(int i = 0 ; i < root->children.size() ; i++){
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children[i]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    // TreeNode<int>* root = new TreeNode<int>(10);
    // TreeNode<int>* node1 = new TreeNode<int>(20);
    // TreeNode<int>* node2 = new TreeNode<int>(30);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>* root = takeInput();
    printTree(root);

    delete root;
    // delete node1;
    // delete node2;

    
    
    return 0;
}