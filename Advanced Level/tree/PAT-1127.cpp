//根据中序遍历和后序遍历得到一棵二叉树
//输出这棵树的zigzag-order traversal

#include<iostream>
#include<vector>
#include<queue>
#define max_size 35
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
}nodes[max_size];

Node* root;
int in[max_size], post[max_size];//记录中序和后序遍历的数值
vector<int> res[max_size];//第一维数值为深度,第二维代表在该层的顺序下标
int N;

Node* tobeTree(int inLeft, int inRight, int postLeft, int postRight){//形成了一棵树,其中的重点是找到根节点
    if(inLeft>inRight) return nullptr;
    Node* rt = &nodes[post[postRight]];
    int i = 0;
    while(in[i] != post[postRight] && i<=inRight) i++;
    rt->left = tobeTree(inLeft,i-1,postLeft,postLeft+i-inLeft-1);
    rt->right = tobeTree(i+1,inRight,postLeft+i-inLeft,postRight-1);
    return rt;
}

void bfs(){
    queue<Node*> que;
    que.push(root);
    int times = 0;
    while(!que.empty()){
        for(size_t i=0,s=que.size();i<s;i++){
            Node* head = que.front();
            res[times].push_back(head->value);
            if(head->left != nullptr)  que.push(head->left);
            if(head->right != nullptr)  que.push(head->right);
            que.pop();
        }
        times++;
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++)  cin>>in[i];
    for(int i=0;i<N;i++)  cin>>post[i];
    for(int i=0;i<N;i++)  nodes[i].value = i;//使value值等于下标
    root = tobeTree(0,N,0,N);
    if(root==nullptr) cout<<"root is nullptr";
    bfs();
    cout<<res[0][0];
    for(size_t i=1;i<max_size;i++){
        if(i%2 == 1){//奇数层为正序
            for(size_t j=0;j<res[i].size();j++)  cout<<" "<<res[i][j];
        }
        else{//偶数层为逆序
            for(size_t j=res[i].size();j>=0;j--)  cout<<" "<<res[i][j];
        }
    }
    cout<<endl;
    return 0;
}
