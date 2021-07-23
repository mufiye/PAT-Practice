//输入一个树结构，输出节点最多的一层的节点数量和level值

#include<iostream>
#include<vector>
#include<queue>
//#include<string>

using namespace std;

// struct Node{
//     int id;
//     vector<Node*> children;
// };

int main(){
    int N,M;//N为总的节点数目,M为有子节点的节点数
    cin>>N>>M;
    
    //如何根据这样的输入形成一棵树？
    //不使用node结构体，而使用二维的vector结构
    vector<vector<int>> tree(N+1);
    for(int i=0;i<M;i++){
        int id,k;
        cin>>id>>k;
        for(int j=0;j<k;j++){
            int num;
            cin>>num;
            tree[id].push_back(num);
        }
    }
    
    //得到树后,用树结构做层次遍历
    queue<int> que;
    que.push(1);
    int thresholdVal = 1;
    vector<int> generation;
    while(!que.empty()){
        generation.push_back(thresholdVal);
        int temp = 0;
        for(int i=0;i<thresholdVal;i++){
            int id = que.front();
            temp += tree[id].size();
            for(int j=0;j<tree[id].size();j++){
                que.push(tree[id][j]);
            }
            que.pop();
        }
        thresholdVal = temp;
    }
    
    int maxIndex = 0;
    int maxNum = generation[0];
    for(int i=1;i<generation.size();i++){
        if(generation[i]>maxNum){
            maxIndex = i;
            maxNum = generation[i];
        }
    }
    cout<<maxNum<<" "<<maxIndex+1<<endl;
    return 0;
}
