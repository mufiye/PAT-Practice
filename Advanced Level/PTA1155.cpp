#include<iostream>
using namespace std;

//该题目的要求是有规则地输出一个heap从根部到叶子节点的路径，并且判断这个heap是max Heap还是min Heap或者根本不是Heap
//使用数组存储该二叉树，用深度优先搜索（path记录每一条路径）规则的输出路径，用两个bool变量记录和判断是什么heap

int tree[1001];
int path[1001];
int N;
bool isMaxHeap,isMinHeap;

void dfs(int node,int pos){
    path[pos] = node;
    //到达叶子节点，输出
    if(node*2>N){
        for(int i=0;i<=pos;i++){
            if(i!=pos) cout<<tree[path[i]]<<" ";
            else cout<<tree[path[i]]<<endl; 
        } 
        return;
    }
    int rightNode = node*2+1;
    int leftNode = node*2;
    
    //判断
    if(rightNode<=N){
        if(tree[rightNode]<=tree[node]) isMaxHeap = true;
        else isMinHeap = true;
    }
    if(leftNode<=N){
        if(tree[leftNode]<=tree[node]) isMaxHeap = true;
        else isMinHeap = true;
    }

    //右子树先于左子树
    if(rightNode<=N) dfs(rightNode,pos+1);
    if(leftNode<=N) dfs(leftNode,pos+1);
    return;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tree[i+1];
    }
    isMaxHeap = false;
    isMinHeap = false;
    dfs(1,0);
    if(isMaxHeap && isMinHeap) cout<<"Not Heap"<<endl;
    else if(isMaxHeap) cout<<"Max Heap"<<endl;
    else if(isMinHeap) cout<<"Min Heap"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
