//读取并存储一棵二叉树,然后做中序遍历

#include<iostream>
#include<string>
#include<vector>
#define MAX_N 21

using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;
}nodes[MAX_N];

bool marked[MAX_N];//用于判断是否为根节点

void dfs(Node*, bool);
int main(){
    int N;
    cin>>N;
    //读取并存储一棵二叉树
    fill(marked + 1, marked + N + 1, true);
    for(int i=1;i<N+1;i++){
        int left,right;
        cin>>nodes[i].data>>left>>right;
        if(left != -1){
            marked[left] = false;
            nodes[i].left = &nodes[left];
        }
        if(right != -1){
            marked[right] = false;
            nodes[i].right = &nodes[right];
        }
    }
#ifdef debug
    for(int i=1;i<N+1;i++){
        if(nodes[i].left != nullptr)  cout<<(nodes[i].left)->data<<endl;
    }
#endif
    
    //做中序遍历
    int root;
    for(int i = 1; i <= N; i++){
        if(marked[i]){
            root = i;
            break;
        }
    }
    dfs(&nodes[root], true);
    cout<<endl;
    return 0;
}

void dfs(Node* root, bool isRoot){
    bool notLeaf = root->left != nullptr || root->right != nullptr;
    if(notLeaf && !isRoot) cout<<"(";
    if(root->left != nullptr)  dfs(root->left,false);
    cout<<root->data;
    if(root->right != nullptr)  dfs(root->right,false);
    if(notLeaf && !isRoot) cout<<")";
}
