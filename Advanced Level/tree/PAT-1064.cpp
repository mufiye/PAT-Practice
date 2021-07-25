//构建一个完全二叉搜索树
//给出这颗树的level-order traversal

#include<iostream>
#include<algorithm>
#define max_size 1000

using namespace std;

int level[max_size], in[max_size];
int N, t=0;

//按照层次遍历顺序排列的数组有着规律：根为root,左子树节点序号为root*2+1,右子树节点序号为root*2+2（当起始的根节点为0）。
void inToLevel(int root){
    if(root>=N)  return; //考虑level数组的容量
    //按照中序遍历的顺序还原一整棵树
    inToLevel(root*2+1); 
    level[root] = in[t++];
    inToLevel(root*2+2);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>in[i];
    sort(in, in+N);
    inToLevel(0);
    for(int i=0;i<N;i++){
        if(i!=0)  cout<<" "<<level[i];
        else  cout<<level[i];
    }
    cout<<endl;
    return 0;
}
