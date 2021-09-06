//根据先序遍历和中序遍历得到树的结构，之后输出一个left-view（实际上是输出树的BFS的第一个结果）
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, in[20], pre[20];
struct Node{
    int val;
    Node *left, *right;
    Node(int v){
        this->val = v;
    }
};

void getTree(Node* &root, int inL, int inR, int preRoot){//三个int参数都是下标位置
    if(inL > inR)  return;
    else if(inL == inR)  root = new Node(in[inL]);
    else{
        int index;
        for(index=inL; index<=inR; index++){
            if(in[index] == pre[preRoot]){
                break;
            }
        }
        root = new Node(pre[preRoot]);
        getTree(root->left, inL, index-1, preRoot+1);
        getTree(root->right, index+1, inR, preRoot+index-inL+1);
        return;
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++)  cin>>in[i];
    for(int i=0;i<N;i++)  cin>>pre[i];
    //首先通过pre和in数组得到树的结构
    //之后进行bfs遍历,每一轮遍历的第一个节点就是left-view
    Node* root;
    getTree(root, 0, N-1, 0);
    //cout<<root->left->val;
    //bfs
    queue<Node*> q;
    vector<int> res;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        Node* f;
        for(int i=0; i<s; i++){
            f = q.front();
            if(i == 0)  res.push_back(f->val);
            q.pop();
            if(f->left != nullptr)  q.push(f->left);
            if(f->right != nullptr)  q.push(f->right);
        }
    }
    for(int i=0; i<res.size(); i++){
        if(i != 0)  cout<<" "<<res[i];
        else  cout<<res[i];
    }
    return 0;
}
