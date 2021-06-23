/*
  该题是先读取一颗树，然后要将其构建成二叉搜索树，最后要输出其的层次遍历
  1. 读取很简单，我们创建一个node的结构体，结构体中的val属性表示键值，left和right分别存储左右子节点的下标值
  2. 构建二叉搜索树，这个有些难，使用中序遍历将排完序的键值赋给每个节点
  3. 层次遍历就是使用广度优先搜索，此处是使用队列实现了广度优先搜索
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct node{
    int val, left, right;
};

int N, index=0;
vector<node> vec; //vec存储的是树节点
vector<int> v; //v存储的是键值

void inorder(int root)
{
	if (root == -1)
		return;
	inorder(vec[root].left);
	vec[root].val = v[index++];
	inorder(vec[root].right);
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(vec[cur].left != -1)  q.push(vec[cur].left);
        if(vec[cur].right != -1)  q.push(vec[cur].right);
        //输出
        if(cur == root)  cout<<vec[cur].val;
        else  cout<<" "<<vec[cur].val;
    }
}

int main(){
    cin>>N;
    
    //存储每个节点的左右儿子
    for(int i=0;i<N;i++){
        node nd;
        cin>>nd.left>>nd.right;
        vec.emplace_back(nd);
    }
    
    //存储节点的值
    for(int i=0;i<N;i++){
        int value;
        cin>>value;
        v.emplace_back(value);
    }
    
    //排序，为了二叉搜索树
    sort(v.begin(),v.end());
    //广度优先搜索
    inorder(0);
    bfs(0);
    cout<<endl;
    return 0;
}
