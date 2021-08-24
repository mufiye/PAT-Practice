//AVL树以及判断是不是完全二叉树
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#define max_size 21
using namespace std;

struct Node{
    int val, height=1;//如何更新height
    Node* left, *right;//不用指针而是用下标表示这棵树
    Node(int val){
        this->val = val;
    }
};

int getHeight(Node* root){
    if(root == nullptr)  return 0;
    else  return root->height;
}

void updateHeight(Node* root){
    root->height = max(getHeight(root->left),getHeight(root->right))+1;
}

int getBalanceFactor(Node* root){
    return getHeight(root->left) - getHeight(root->right);
}

//左旋
void L(Node* &root){
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//右旋
void R(Node* &root){
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//插入操作
void insert(Node* &root, int v){
    if(root == NULL){
        root = new Node(v);
        return;
    }
    if(v < root->val){  //v比根结点的权值小
        insert(root->left, v); //往左子树插入
        updateHeight(root); //更新树高
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->left) == 1){  //LL型
                R(root);
            }  
            else if(getBalanceFactor(root->left) == -1){  //LR型
                L(root->left);
                R(root);
            }
        }
    }
    else{  //v比根节点的权值大
        insert(root->right, v); //往右子树插入
        updateHeight(root); //更新树高
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->right) == -1){  //RR型
                L(root);
            }  
            else if(getBalanceFactor(root->right) == 1){  //RL型
                R(root->right);
                L(root);
            }
        }
    }
}

Node* create(vector<int>data){
    Node* root = nullptr;
    for(int i=0; i<data.size(); i++){
        insert(root, data[i]);
        //upDateHeight(root);
    }
    return root;
}

int main(){
    int n;
    vector<int> vec;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }
    Node* root = create(vec);
    //层次遍历并判断
    queue<Node*> q;
    q.push(root);
    bool notComplete = false, beforeisNull = false;
    while(!q.empty()){
        int s = q.size();
        for(int i=0; i<s; i++){
            Node* f = q.front();
            q.pop();
            if(f != root)  cout<<" "<<f->val;
            else  cout<<f->val;
            if(f->left != nullptr){
                q.push(f->left);
                if(beforeisNull)  notComplete = true;
            }
            else  beforeisNull = true;
            if(f->right != nullptr){
                q.push(f->right);
                if(beforeisNull)  notComplete = true;
            }
            else  beforeisNull = true;
        }
    }
    cout<<endl;
    if(notComplete)  cout<<"NO";
    else  cout<<"YES";
    return 0;
}
