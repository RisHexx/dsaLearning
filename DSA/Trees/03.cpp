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

int count(TreeNode<int>*root){
    int ans = 1;
    for(int i = 0 ; i < root->children.size() ; i++){
        ans += count(root->children[i]);
    }
    return ans;
}

int sum(TreeNode<int>*root){
    int Totalsum = root->data;
    for(int i = 0 ; i < root->children.size() ; i++){
        Totalsum += sum(root->children[i]);
    }
    return Totalsum;
}


int Max(TreeNode<int>* root) {
    if (root == nullptr) return INT_MIN;
    int maxData = root->data;
    for (int i = 0; i < root->children.size(); i++) {
        int childMax = Max(root->children[i]);
        if (childMax > maxData) {
            maxData = childMax; 
        }
    }
    return maxData;
}

int Height(TreeNode<int>* root){
    int Maxheight = 0;
    for(int i = 0 ; i < root->children.size() ; i++){
        int heightChild = Height(root->children[i]);
        if(heightChild > Maxheight){
            Maxheight = heightChild;
        }
    }
    return Maxheight + 1;
}


int countLeafNodes(TreeNode<int>* root) {
    if (root == nullptr) return 0;
    // If current node is a leaf
    if (root->children.size() == 0) {
        return 1;
    }
    int count = 0;
    // Recur for all children
    for (int i = 0; i < root->children.size(); i++) {
        count += countLeafNodes(root->children[i]);
    }
    return count;
}

void preorder(TreeNode<int>*root){
    cout<<root->data<<" ";
    for(int i = 0 ; i < root->children.size() ; i++){
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int>*root){
    for(int i = 0 ; i < root->children.size() ; i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* node1 = new TreeNode<int>(20);
    TreeNode<int>* node2 = new TreeNode<int>(30);
    TreeNode<int>* node3 = new TreeNode<int>(40);
    TreeNode<int>* node4 = new TreeNode<int>(50);

    root->children.push_back(node1);
    root->children.push_back(node2);
    node2->children.push_back(node3);
    node3->children.push_back(node4);
    // printTree(root);
    // cout<<endl;
    // cout<<sum(root);
    // cout<<endl;
    // cout<<Max(root);
    // cout<<endl;
    // cout<<Height(root);
    // cout<<endl;
    // cout<<countLeafNodes(root);
    
    preorder(root);
    cout<<endl;
    postorder(root);
    delete root;

    
    
    return 0;
}