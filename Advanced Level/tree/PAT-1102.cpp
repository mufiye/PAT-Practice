//从输入中读取树结构(使用结构体)
//invert tree
//第一行输出层次遍历
//第二行输出中序遍历

#include<iostream>
#include<queue>
#include<vector>
#define max_size 10

using namespace std;

struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
}nodes[max_size];

bool marked[max_size];
vector<int> vec;

void inOrder(Node* root){
    if(root->left != nullptr)  inOrder(root->left);
    vec.push_back(root->value);
    if(root->right != nullptr)  inOrder(root->right);
    return;
}

int main(){
    int N;
    cin>>N;
    //读取树结构
    fill(marked + 1, marked + N + 1, false);
    for(int i=0;i<N;i++){
        char a,b;
        cin>>a>>b;
        nodes[i].value = i;
        if(a != '-'){
            nodes[i].left = &nodes[a-'0'];
            marked[a-'0'] = true;
        }
        if(b != '-'){
            nodes[i].right = &nodes[b-'0'];
            marked[b-'0'] = true;
        }
    }
    
    //invert tree
    for(int i=0;i<N;i++){
        Node* temp = nullptr;
        temp = nodes[i].left;
        nodes[i].left = nodes[i].right;
        nodes[i].right = temp;
    }
    
    //find the root
    int root = 0;
    for(int i=0;i<N;i++){
        if(!marked[i]){
            root = i;
            break;
        }
    }
    
    //level-order traversal
    queue<Node*> que;
    que.push(&nodes[root]);
    int i=0;
    while(!que.empty()){
        Node* head = que.front();
        que.pop();
        if(head->left != nullptr) que.push(head->left);
        if(head->right != nullptr) que.push(head->right);
        //输出
        if(i != 0)  cout<<" "<<head->value;
        else  cout<<head->value;
        i++;
    }
    cout<<endl;
    
    //in-order traversal
    inOrder(&nodes[root]);
    for(int i=0;i<N;i++){
        if(i!=0) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
    cout<<endl;
    return 0;
}
