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

TreeNode<int>* takeInputLevel(){
    int TreeData;
    cin>>TreeData;
    TreeNode<int>* root = new TreeNode<int>(TreeData);
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(pending.size() != 0){
        TreeNode<int>* front = pending.front();
        pending.pop();
        int numofchild;
        cin>>numofchild;
        for(int i = 0 ; i < numofchild ; i++){
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> pendings;
    pendings.push(root);
    while(pendings.size() != 0){
        TreeNode<int>* front = pendings.front();
        pendings.pop();
        cout<<front->data<<" : ";
        for(int i = 0 ; i < front->children.size() ; i++){
            pendings.push(front->children[i]);
            cout<<front->children[i]->data<<" , ";
        }
        cout<<endl;
    }
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
    TreeNode<int>* root = takeInputLevel();
    printLevelWise(root);

    delete root;

    
    
    return 0;
}